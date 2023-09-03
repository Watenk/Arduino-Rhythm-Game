#pragma once

//My attempt at a linked list (isn't even generic :/ )

#include "ListNode.h"
#include "Object.h"

class List{
  public:
    List();
    void add(Object* object);
    void remove(Object* object);
    ListNode* getHead();
    int lenght();

  private:
    ListNode* get(Object* object);
    ListNode* head;
};