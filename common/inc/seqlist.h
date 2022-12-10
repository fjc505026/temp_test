#ifndef __SEQLIST_H
#define __SEQLIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SEQ_MAX_SZ 10

typedef struct {
  int *data;
  int maxsz;
  int length;
} SeqList;

void init_seqlist(SeqList *list);

bool add_sqlist_elemn(SeqList *list, int data);

void reset_seqlist(SeqList *list);

int get_seqlist_length(SeqList *list);

int get_seqlist_elem(SeqList *list, int index, int *data);

int locate_seqlist_elem(SeqList *list, int data);

void increase_seqlist_size(SeqList *list, int len);

void del_seqlist(SeqList *list);

void show_seqlist(SeqList *list);

#endif // __SEQLIST_H