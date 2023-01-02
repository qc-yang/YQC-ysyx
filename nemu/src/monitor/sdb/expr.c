/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <memory/vaddr.h>
#include <memory/paddr.h>
/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ = 257, TK_NEQ = 258, TK_AND = 259, TK_OR = 260,
  TK_HNUM = 261, TK_DNUM = 262, TK_NEG = 263, TK_REG = 264, TK_DEREF = 265
  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},           // spaces
  {"==", TK_EQ},               // equal
  {"!=", TK_NEQ},              // not equal
  {"&&", TK_AND},              // logical and
  {"\\|\\|", TK_OR},           // logical or
  {"\\$[\\$a-zA-Z][0-9a-zA-Z]+", TK_REG},   // register
  {"\\+", '+'},                // plus
  {"\\-", '-'},                // minus
  {"\\*", '*'},                // multiply
  {"\\/", '/'},                // divide
  {"0x[0-9a-fA-F]+", TK_HNUM},   // one hexdemical number
  {"[0-9]+", TK_DNUM},         // one demical number
  {"\\(", '('},                // left parenthesis
  {"\\)", ')'},                // right parenthesis  
  
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[4096] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
	  case '+':
	  case '-':
	  case '*':
	  case '/':
	  case TK_EQ:  						
	  case TK_NEQ:
	  case TK_AND:
	  case TK_OR:
	  case '(': 
	  case ')':
	    tokens[nr_token].type = rules[i].token_type;
	    nr_token++;	
	    break;
          case TK_HNUM:
	  case TK_DNUM:
	  case TK_REG:
            strncpy(tokens[nr_token].str, substr_start, substr_len);             
	    tokens[nr_token].type = rules[i].token_type;
	    nr_token++;	
            break;
          default: break; 
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

static bool check_parentheses(int p, int q){
  int i;
  int count = 0;
  if(tokens[p].type != '(' || tokens[q].type != ')')
    return false;
  for(i = p; i <= q; i++){
    if(tokens[i].type == '(')
      count++; 
    else if(tokens[i].type == ')')
      count--; 
    if(count == 0 && i < q)
      return false;
}
    if(count != 0) return false;
    return true;
}

        

word_t eval(int p, int q, bool *success) {
    if(p > q) {
    return -1;
}
    else if (p == q) {
      uint64_t value = 0;
      switch(tokens[p].type){
      case TK_DNUM:
        sscanf(tokens[p].str, "%ld", &value);
        break;
      case TK_HNUM:
        sscanf(tokens[p].str, "%lx", &value);
        break;
      case TK_REG:
        strcpy(tokens[p].str, tokens[p].str+1);
        value = isa_reg_str2val(tokens[p].str, success);
    }
    return value;
}      
    else if (check_parentheses(p,q) == true) {
      return eval(p + 1,q - 1, success);
}   
    else if(tokens[p].type == TK_DEREF)
    {
        uint64_t addr = eval(p+1, q, success);
        return vaddr_read(addr,4);
    }      
    else {
        int op = -1  ;
        int i, cnt = 0;
        for(i = p; i <= q; i++){
            if(tokens[i].type == '(')
           cnt++;
            if(tokens[i].type == ')')
           cnt--;
            if(cnt != 0)
               continue;
            if(tokens[i].type == '+' || tokens[i].type == '-' || tokens[i].type == '*' || tokens[i].type == '/' || tokens[i].type == TK_EQ || tokens[i].type == TK_NEQ || tokens[i].type == TK_AND)
           {
            if(op == -1)
              op = i;
            else if(tokens[i].type == TK_EQ || tokens[i].type == TK_NEQ || tokens[i].type == TK_AND)
              op = i;
            else if((tokens[i].type == '*' || tokens[i].type == '/') && (tokens[op].type == '*' || tokens[op].type == '/'))
              op = i;
            else if((tokens[i].type == '+' || tokens[i].type == '-') && (tokens[op].type == '+' || tokens[op].type == '-' || tokens[op].type == '*' || tokens[op].type == '/'))
              op = i;
              
        }  
      }
      int val1 = eval(p, op - 1, success);
      int val2 = eval(op + 1, q, success);
      
      switch(tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': return val1 / val2;
      case TK_EQ: return val1 == val2;
      case TK_NEQ: return val1 != val2;
      case TK_AND: return val1 && val2;
      default: *success = false;
      } 
    }
    return 0;
}   

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  *success = true;
  for(int i = 0; i < nr_token; i++){
      if(tokens[i].type == '*' && (i == 0 || (tokens[i-1].type != TK_DNUM && tokens[i-1].type != TK_HNUM && tokens[i-1].type != TK_REG && tokens[i-1].type != ')' ) ))
         tokens[i].type = TK_DEREF;
      if(tokens[i].type == '-' && (i == 0 || (tokens[i-1].type != TK_DNUM && tokens[i-1].type != TK_HNUM && tokens[i-1].type != TK_REG && tokens[i-1].type != ')' ) ))
         tokens[i].type = TK_NEG;
  }
  word_t value = eval(0, nr_token - 1, success);
  
  if(*success == false) 
     return 0;
  return value;
}
