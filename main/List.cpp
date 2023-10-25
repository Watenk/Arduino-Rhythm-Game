#include "List.h"
#include "Arduino.h"

List::List(){
  head = NULL;
}

void List::add(Object* object){

  //replace head with newObject
  ListNode* previousNode = head;
  ListNode* newNode = new ListNode(object, head);
  head = newNode;
  newNode->nextNode = NULL;

  if (previousNode != NULL){
    previousNode->nextNode = newNode;  
  }
}

void List::remove(Object* object){
  ListNode* currentNode = get(object);
  ListNode* previousNode = currentNode->previousNode;
  ListNode* nextNode = currentNode->nextNode;

  //is last remaining item in the list
  if (nextNode == NULL && previousNode == NULL){
    head = NULL;
  }

  //is last item in list
  else if (nextNode == NULL){
    previousNode->nextNode = NULL;
    head = previousNode;
  }

  //is first item in list
  else if (previousNode == NULL){
    nextNode->previousNode = NULL;
  }

  //is in middle of list
  else if (nextNode != NULL && previousNode != NULL){
    previousNode->nextNode = nextNode;
    nextNode->previousNode = previousNode;
  }

  free(&object);
  free(currentNode);
}

void List::remove(ListNode* listNode){
  ListNode* currentNode = listNode;
  ListNode* previousNode = currentNode->previousNode;
  ListNode* nextNode = currentNode->nextNode;

  //is last remaining item in the list
  if (nextNode == NULL && previousNode == NULL){
    head = NULL;
  }

  //is last item in list
  else if (nextNode == NULL){
    previousNode->nextNode = NULL;
    head = previousNode;
  }

  //is first item in list
  else if (previousNode == NULL){
    nextNode->previousNode = NULL;
  }

  //is in middle of list
  else if (nextNode != NULL && previousNode != NULL){
    previousNode->nextNode = nextNode;
    nextNode->previousNode = previousNode;
  }

  free(listNode->object);
  free(listNode);
}

ListNode* List::get(Object* object){

  ListNode* currentPointer = head;
  Object* currentObject = currentPointer->object;
  while (object != currentObject){
    currentPointer = currentPointer->previousNode;
    currentObject = currentPointer->object;
  }

  return currentPointer;
}

ListNode* List::getHead(){
  return head;
}

int List::lenght(){
  ListNode* currentPointer = head;
  int lenght = 0;

  while(currentPointer != NULL){
    currentPointer = currentPointer->previousNode;
    lenght++;
  }

  return lenght;
}