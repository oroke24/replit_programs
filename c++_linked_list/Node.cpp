#include "Node.h"
#include <iostream>

Node::Node(int value){
  this->value = value;
  this->next = nullptr;
}
Node::~Node(){
  std::cout << "Deleting Node value: " << printValue() << std::endl;
}
void Node::setValue(int x){
  this->value = x;
}
int Node::getValue(){
  return this->value;
}
Node * Node::getNext(){
  return this->next;
}
void Node::setNext(Node * n){
  this->next = n;
}
int Node::printValue(){
  return this->value;
}