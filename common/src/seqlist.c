
#include "seqlist.h"

void init_seqlist(SeqList *list) {
  list->data = (int *)malloc(SEQ_MAX_SZ * sizeof(int));
  list->length = 0;
  list->maxsz = SEQ_MAX_SZ;
}

bool add_sqlist_elemn(SeqList *list, int data) {
  if ((list != NULL) && (list->length < SEQ_MAX_SZ)) {
    list->data[(list->length)++] = data;
    return true;
  } else {
    return false;
  }
}

void reset_seqlist(SeqList *list) {

  for (int i = 0; i < list->maxsz; i++) {
    list->data[i] = 0;
  }
  list->length = 0;
  // list->maxsz  could be changed
}

int get_seqlist_length(SeqList *list) { return list->length; }

int get_seqlist_elem(SeqList *list, int index, int *data) {

  if (index < 0 || index > list->length) {
    return -1;
  }

  *data = list->data[index];
};

int locate_seqlist_elem(SeqList *list, int data) {
  for (int i = 0; i < list->length; i++) {
    if (list->data[i] == data) {
      return i;
    }
  }
  return -1;
}

void increase_seqlist_size(SeqList *list, int len) {
  int *p = list->data; // keep the old data address

  /*malloc new space for data*/
  list->data = (int *)malloc((SEQ_MAX_SZ + len) * sizeof(int));
  for (int i = 0; i < list->length; i++) {
    list->data[i] = p[i];
  }
  list->maxsz = list->maxsz + len;
  free(p); // release space of the old data
}

void del_seqlist(SeqList *list) {
  free(list);
  list = NULL;
}

void show_seqlist(SeqList *list) {
  for (int i = 0; i < list->length; i++) {
    printf("[%d]%d ", i, list->data[i]);
  }
  printf("\r\n");
}