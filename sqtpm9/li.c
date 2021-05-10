#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "li.h"


li* li_alloc() {
  return calloc(1,sizeof(li));
}



void li_free(li* L) {

  node* p = L->head;
  node* n = NULL;

  while (p != NULL) {
    n = p->next;
    free(p);
    p = n;
  }

  free(L);
}



int li_insert(li* L, int data) {

  node* n = malloc(sizeof(node));
  if (n == NULL)
    return 0;

  n->data = data;
  n->next = L->head;
  L->head = n;

  return 1;
}



void li_print(li* L) {

  node* p = L->head;
  printf("{");

  while (p != NULL && p->next != NULL) {
    printf("%d, ",p->data);
    p = p->next;
  }

  if (p != NULL)
    printf("%d",p->data);

  printf("}");
}

/*
  Evaluate the union of lists of ints A and B.  Return a new list on success.
  If memory allocation fails any partially constructed list is freed and it
  returns NULL.
*/
li* li_union(li* A, li* B) {
  li* C;
  C = li_alloc();
  if (C == NULL) {
    return NULL;
  }
  int count = 0;

  node* a = A->head;
  node* b = B->head;

  while (a) {
    while (b) {
      if (a->data == b->data) {
        count++;
        b = b->next;
      } else {
        b = b->next;
      }
    }
    b = B->head;
    if (count == 0) {
      li_insert(C, a->data);
    }
    a = a->next;
    count = 0;
  }

  while (b) {
    li_insert(C, b->data);
    b = b->next;
  }

  return C;
}


/*
  Evaluate the intersection of lists of ints A and B.  Return a new list on
  success.  If memory allocation fails any partially constructed list is freed
  and it returns NULL.
*/
li* li_intersection(li* A, li* B) {
  li* C;
  C = li_alloc();
  if (C == NULL) {
    return NULL;
  }

  node* a = A->head;
  node* b = B->head;

  while (a) {
    while (b) {
      if (a->data == b->data) {
        li_insert(C, a->data);
        b = b->next;
      } else {
        b = b->next;
      }
    }
    b = B->head;
    a = a->next;
  }
  return C;
}


/*
  Evaluate the difference A-B of lists of ints.  Return a new list on success.
  If memory allocation fails any partially constructed list is freed and it
  returns NULL.
*/
li* li_difference(li* A, li* B) {
  li* C;
  C = li_alloc();
  if (C == NULL) {
    return NULL;
  }
  int count = 0;

  node* a = A->head;
  node* b = B->head;

  while (a) {
    while (b) {
      if (a->data == b->data) {
        count++;
        b = b->next;
      } else {
        b = b->next;
      }
    }
    b = B->head;
    if (count == 0) {
      li_insert(C, a->data);
    }
    a = a->next;
    count = 0;
  }
  return C;
}