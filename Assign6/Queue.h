#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using std::ostream;

class Queue
{
  friend ostream &operator<<(ostream &, const Queue &);
  
 private:
  int *queueArray;
  size_t queueCap;
  size_t queueSize;
  int frontSub, backSub;
  
 public:
  Queue(); //default constructr=or
  Queue(const Queue &); // copy constucotr
  ~Queue(); // destructor
  void clear();
  size_t size()const;
  size_t capacity()const;
  bool empty()const;
  int front()const;
  int back()const;
  void push(int);
  void reserve(size_t);
  void pop();
  Queue &operator=(const Queue &); //assignment operator
};

#endif 
