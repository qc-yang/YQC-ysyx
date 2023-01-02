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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char exp[32];
  word_t value; 
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp(char *exp){
    if(free_ == NULL){
       assert(0);
       }
       WP *new = free_;
       free_ = free_->next;
       new->next = NULL;
    
    bool success = true;
    strcpy(new->exp, exp);
    new->value = expr(exp, &success);
    
    if(head == NULL)
       head = new;
    else{
       new->next = head;
       head = new;
       }
    return new;
}

void free_wp(int n){
     WP *wp = head;
     if(head == NULL)
       printf("no watchpoint\n");
     else if(wp->NO == n){
          head = head->next;
          wp->next = free_;
          free_ = wp;
          printf("delete NO.%d watchpoint\n", n);
          return ;
     }
     else{
          WP *pre_wp = head;
          wp = wp->next;
          while(wp){
                if(wp->NO == n){
                   pre_wp->next = wp->next;
                   wp->next = free_;
                   free_ = wp;
                   printf("delete NO.%d watchpoint\n", n);
                   return ;
         }
     else{
         wp = wp->next;
         pre_wp = pre_wp->next;           
     }
     }
     return;
}
}

bool watchpoint_check(){
     WP* wp =head;
     int i=0;
     if(wp == NULL){
     //printf("there is no watchpoints\n");
     return false;
  }  else{
     while(wp){
           bool success = true;
           word_t new_value = expr(wp->exp, &success);
     if(success && new_value != wp-> value){
        printf("watchpoint No.%d\n", wp->NO);
        printf("watchpoint EXPR: %s\n", wp->exp);
        printf("watchpoint old_value: 0x%016lx, %lu\n", wp-> value, wp->value);
        printf("watchpoint new_value: 0x%016lx, %lu\n", new_value, new_value);
        wp->value = new_value;
        i++;
      }
      wp = wp->next;
    }  
    if(i != 0){
    return true;
    }
    return false;
  }
}

void watchpoint_display(){
  WP* wp = head;
  if(wp == NULL){
    printf("no watchpoints\n");
    return;
  }

  while(wp){
    printf("No.%d\t EXPR:%s\t value:%lu\n",wp->NO, wp->exp, wp->value);
    wp = wp->next;
  }
}
