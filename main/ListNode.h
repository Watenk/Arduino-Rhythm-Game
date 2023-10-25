#pragma once

#include "Object.h"

class ListNode{
  public:
    ListNode(Object* object, ListNode* previousNode);
    Object* object;
    ListNode* previousNode;
    ListNode* nextNode;
    
  private:

};