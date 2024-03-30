#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *nuevaLista = (List *)malloc(sizeof(List));
  nuevaLista->head = NULL;
  nuevaLista->tail = NULL;
  nuevaLista->current = NULL;
     return nuevaLista;
}

void * firstList(List * list) {
    if (list->head == NULL)
        return NULL;
    list->current = list->head;
    return list->head->data;
}

void * nextList(List * list) {
  if (list->current == NULL || list->current->next == NULL)
    return NULL;
  list->current = list->current->next;
  return list->current->data;
}

void * lastList(List * list) {
  if (list->current == NULL || list->current->next == NULL)
    return NULL;
  while (list->current->next != NULL)
    {
      list->current = list->current->next;
    }
  
  return list->current->data;
}

void * prevList(List * list) {
  if (list->current == NULL || list->current->prev == NULL)
    return NULL;
  while (list->current->next != NULL)
    {
      list->current = list->current->next;
    }
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) {

  Node* nuevoNodo = createNode(data);
  if (list->head != NULL ) 
  {
    nuevoNodo->next = list->head;
    list->head = nuevoNodo;
    list->head->next->prev = list->head;
  }

  
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}