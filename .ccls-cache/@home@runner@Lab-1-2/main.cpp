/* Ask the user to input five numbers on the same line separated by spaces, then
do the following: a. Print out the five numbers (with spaces or tabs between
them). b. Calculate and print the sum, average, and product of the numbers.
  */
#include <iostream>
using namespace std;
struct node {
  int data;
  node * next;
};
class list { // This is a "Stack" data structure in the form of a linked list
             // with pointers
public:
  list() {
    head = nullptr; // initializing the starting pointer to 0
  }
  ~list() { // deallocating all of the memory, popping each off the list
    while (head) {
      node *temp = head;
      head = head->next;
      delete temp;
    }
  }

  void add_number(int passed_in_int) { // stacking the new node onto the list
    node *temp = head;
    head = new node;
    head->data = passed_in_int;
    head->next = temp;
  }
  void display_list() { // creating a temp node that will display each node
    display_list(head);
  }
  void display_list(node *&head) {
    if (!head)
      return;
    display_list(head->next);
    cout << head->data << endl;
  }
  int sum_of_list() { return sum_of_list(head); }
  int sum_of_list(node *&head) {
    if (!head)
      return 0;
    return head->data + sum_of_list(head->next);
  }
  int product_of_list() { return product_of_list(head); }
  int product_of_list(node *&head) {
    if (!head)
      return 1;
    return head->data * product_of_list(head->next);
  }
  int average_of_list() { return sum_of_list(head) / 5; }
  int average_of_list(node *&head) {
    if (!head)
      return 0;
    return head->data + average_of_list(head->next);
  }

private:
  node *head;
};

int main() { // main function to call the list functions and provide interface
             // to the user
  node head;
  list my_list;

  cout << "Input five numbers (with spaces or tabs between them)\n";

  int user_input = 0;
  int index = 0;
  while (index < 5) { // only accept the first five entries
    cin >> user_input;
    my_list.add_number(
        user_input); // calling "add_number" function in the list class
    cout << ++index << ". ";
    cout << user_input << endl;
  }
  cout << "List recieved: \n";
  my_list.display_list(); // calling "display_list" kickstarter function in list
                          // class

  cout << "Sum of all numbers in the list: " << my_list.sum_of_list()
       << endl; // calling "sum_of_list" kickstarter function in the list class
  cout << "Product of all numbers in the list: " << my_list.product_of_list()
       << endl;
  cout << "Average of all numbers in the list: " << my_list.average_of_list()
       << endl;
}