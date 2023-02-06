#include <iostream>
#include "Dog.h"
#include <unistd.h>

  using namespace std;

int main() {
  cout << "Hello World, Im making a dog\n";
  
  Dog dog("dude");
  dog.setWeight(75);
  dog.setNumberOfLegs(4);
  dog.setHappiness(false);
  dog.setEyeColor("blue");
  dog.setFurColor("brown");

  dog.bark(8);
  dog.run(8, 500);
  dog.wag(8, 500);
}