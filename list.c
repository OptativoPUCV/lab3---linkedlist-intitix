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
  else
  {
    list->head = nuevoNodo;
    list->tail = nuevoNodo;
  }
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* nuevoNodo = createNode(data);
  if (list->head == NULL || list->head->next)
    return;
  
  if (list->current->prev != NULL)
    list->current->prev = nuevoNodo;
    nuevoNodo->next = list->current;

  if (list->current->next != NULL)
    list->current->next->prev = nuevoNodo;
    nuevoNodo->prev = list->current->next;

  if (list->current == list->head)
    list->head = nuevoNodo;

  if (list->current == list->tail)
    list->tail = nuevoNodo;

  list->current = nuevoNodo;

  //NUEVO NODO
  

  
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
  void * dato = list->current->data;

  if (list->current->prev != NULL)
    list->current->prev->next = list->current->next;

  if (list->current->next != NULL)
    list->current->next->prev = list->current->prev;
  
  if (list->current == list->head)
    list->head = list->current->next;

  if (list->current == list->tail)
    list->tail = list->current->prev;
  
  list->current = list->current->next;
  
  return dato;
  
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}