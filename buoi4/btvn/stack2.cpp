#include <iostream>
using namespace std;

template <class T>
struct Node{
  T data;
  Node *next;
  Node(T data){
    this->data = data;
    this->next = nullptr;
  }
}