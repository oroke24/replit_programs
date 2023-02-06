//Creator: Jamie O'Roke
//date: 11/21/2022
//purpose:    step 1; To create a root node
//            step 2; To create a linked list of size 10
//            step 3; To print the list
//            step 4; To delete or "clean up" the list
#include <iostream>
#include "Node.h"

using namespace std;


int main() {

  Node * root;          //This will be the unchanging first Node
  root = new Node(0);  //root now points to a Node object

  //Step 2 code here
  
  cout << "Creating the list...\n";
  for(int i = 1; i < 10; i++){
    cout << "Adding list Node: " << i << ", value: " << i * 2 << endl;
    Node * newNode = new Node(i*2);
    Node * temp = root;
    while(temp->getNext() != nullptr){
      temp = temp->getNext();
    }
   temp->setNext(newNode); 
  }
  
  //Step 3 code here
  
  cout << "Printing the list...\n";
  Node * temp = root;
  while(temp){
    cout << "Node value: " << temp->printValue() << endl;
    temp = temp->getNext();
  }
  
  //Step 4 code here
  cout << "Cleaning up the list...\n";
  while(root){
    temp = root->getNext();
    delete root;
    root = temp;
  }
}


