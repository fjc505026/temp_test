

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "seqlist.h"
void seqlist_test(void) {
  SeqList slist;

  init_seqlist(&slist);

  add_sqlist_elemn(&slist, 1);
  add_sqlist_elemn(&slist, 2);
  add_sqlist_elemn(&slist, 3);
  add_sqlist_elemn(&slist, 4);

  show_seqlist(&slist);
}

#include <squeue.h>
void squeue_test(void) {
  squeue Queue;

  init_squeue(&Queue);
  en_squeue(&Queue, 1);
  en_squeue(&Queue, 2);
  en_squeue(&Queue, 3);
  squeue_print(&Queue);
  int tmp_int = 0;
  de_squeue(&Queue, &tmp_int);
  printf("%d\r\n", tmp_int);
  de_squeue(&Queue, &tmp_int);
  printf("%d\r\n", tmp_int);
  de_squeue(&Queue, &tmp_int);
  printf("%d\r\n", tmp_int);
}

#include <sqstack.h>
void stack_test(void) {
  sqstack Stack;

  init_sqstack(&Stack);
  sqstack_push(&Stack, 1);
  sqstack_push(&Stack, 2);
  sqstack_push(&Stack, 4);

  int tmp_int = 0;
  sqstack_pop(&Stack, &tmp_int);
  sqstack_pop(&Stack, &tmp_int);
  sqstack_pop(&Stack, &tmp_int);
}

int main() {

  FILE *fp;

  char buff[255];

  fp = fopen("/usr/share/dict/words", "r");

  if (NULL == fp) {
    printf("file can't be opened \n");
    return 0;
  }

  int line = 0;

  while (fgets(buff, sizeof(buff), (FILE *)fp) != NULL) {
    line++;
  }
  printf("total line %d, %s \r\n", line, buff);
  // fscanf(fp, "%s", buff);

  // printf("1 : %s\n", buff);

  // fgets(buff, sizeof(buff), (FILE *)fp);
  // printf("2: %s\n", buff);

  // fgets(buff, sizeof(buff), (FILE *)fp);
  // printf("3: %s\n", buff);

  //  while (!feof(fp)) {  // read each char out
  //       ch = fgetc(fp);
  //       printf("%c", ch);
  //   }

  fclose(fp);

  printf("list test\r\n");
  seqlist_test();

  printf("Queue test\r\n");
  squeue_test();

  printf("Stack test\r\n");
  stack_test();

  return 0;
}
