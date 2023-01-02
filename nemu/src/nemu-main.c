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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

//void test_cmd_p()


int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  IFDEF(CONFIG_DEBUG,test_cmd_p());
  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}

/*word_t expr(char *e, bool *success);
#define TEST_CMD_P_PATH "./tools/gen_expr/expr_test.h"
void test_cmd_p() {
  int count = 0;
  char buf[65535];
  char *ex;
  FILE *fp = fopen(TEST_CMD_P_PATH, "r");
  assert(fp != NULL);
  
  char *input = fgets(buf, ARRLEN(buf), fp);
  while (input != NULL) {
    input[strlen(input) -1] = '\0';
    uint64_t answer = 0;
    bool success = false;
    char *ans_text = strtok(input, " ");
    sscanf(ans_text, "%lu", &answer);
    ex = input + strlen(ans_text) + 1;
    IFDEF(CONFIG_DEBUG, Log("Testing %u %s ...\n", answer, ex));
    uint64_t result = expr(ex, &success);
    assert(result == answer);
    input = fgets(buf, ARRLEN(buf), fp);
    ++count;
  }

  Log("通过%d个测试样例", count);
} */





