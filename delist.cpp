#include "delist.h"
#include <iostream>

using namespace std;

  // Constructs an empty Double-Ended List
  DEList::DEList()
  {
    head=nullptr;
    tail=nullptr;
  }
  // Destructor to clean-up memory of current list
  DEList::~DEList()
  {
    while(head!=nullptr)
    {
      DEItem *tmp=head;
      head=head->next;
      delete tmp;
    }
      tail=nullptr;
  }
  // returns a Boolean 'true' if the list is empty
  bool DEList::empty() const
  {
    return head==nullptr;
  }
  // returns number of items in the list
  int DEList::size() const
  {
    int cnt=0;
    if (head!=nullptr){
      DEItem *b=head;
       while(b->next!=nullptr)
      {
        cnt++;
        b=b->next;
      }
      cnt++;
    }
    return cnt;
  }
  // returns front item or -1 if empty list
  int DEList::front() const
  {
    if (head==nullptr)
    {
      return -1;
    }
    else {return head->val;}
  }
  // returns back item or -1 if empty list
  int DEList::back() const
  {
    if (tail==nullptr)
    {
      return -1;
    }
    else {return tail->val;}
    ;
  }
  // Adds a new integer to the front of the list
  void DEList::push_front(int new_val)
  {
    
    DEItem *p = new DEItem;//heap not stack
    p->prev = nullptr;
    p->val= new_val;
    p->next = head;
    
    if (head != nullptr) { //
      head->prev = p; // 
  } else {
      tail = p; //
  }
  head = p;
  }
  // Adds a new integer to the back of the list
  void DEList::push_back(int new_val)
  {
    DEItem *v = new DEItem;
    v->prev = tail;
    v->val= new_val;
    v->next = nullptr;

    if (head != nullptr) { //
      tail->next = v; // 
  } else {
      head = v; //
  }
  tail=v;
  }
  // Removes the front item of the list (if it exists)
  void DEList::pop_front()
  {
    if (head!=nullptr)
    {
      if(head==tail)
      {
        delete head;
        head=nullptr;
        tail=nullptr;
      }
      else{
        DEItem* tmpr=head;
        head=head->next;
        delete tmpr;
      }
    }
  }
  // Removes the back item of the list (if it exists)
  void DEList::pop_back()
  {
    if(head!=nullptr)
    {
      if(head==tail)
      {
        head=nullptr;
        delete tail;
        tail=nullptr;
      }
      else{
        DEItem *tmpr=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete tmpr;
        
      }
    }
  }
  // Converts the contents of the list to a string with spaces between 
  // each element an NO trailing newline (and no space before the 
  // first element or after the last element)
  string DEList::conv_to_string() const
  {
    string str0="";
    DEItem *cur=head;
    while (cur!=nullptr)
    { //stoi
      str0+=(to_string(cur->val));
      cur=cur->next;
      if(cur!=nullptr)
      {
        str0+=" ";
      }
    }
    return str0;
  }

