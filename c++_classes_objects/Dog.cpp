#include <iostream>
#include "Dog.h"
#include <unistd.h>

using namespace std;

Dog::Dog(string name) {
  this->name = name;
  cout <<  this->name << " is alive!\n"; 
  
}
Dog::~Dog(){
  cout << this->name << " is no longer with us :'(\n";
  if(!my_bone){
    delete my_bone;
    my_bone = nullptr;
  }
}

void Dog::run(int howFar, int howFast){
  if (howFar < 0 || howFar > 1000)  cout << "Nothing happpened. " << name << " is too far or too close\n"; //a check for limits
  else if (numberOfLegs < 3) cout << name << " has less than 3 legs :(\n";
  else{    //if howFar is within limits, perform the rest of the function
    if(numberOfLegs == 3) howFast = ((howFast/3)+(howFast%3));
    cout << this->name << " is running to catch squirrles on " << numberOfLegs << " legs | run: " << howFar << ", sleep: " << howFast << "ms\n"; 
    
    if (howFast < 0 || howFast > 1000) howFast = 0;
    for(int i = 0; i < howFar; i++){
    cout << "#";
    cout.flush();
    usleep(howFast * 1000);    //converting micro seconds to millisconds inside the parameters
      }
    cout << endl;
  }
}

void Dog::bark(int numTimes){
  cout << this->name << ": ";
  string yap_or_woof;    //temporary/local string that correlates to a yap or a woof.
  if(this->weight < 100) yap_or_woof = "yap";
  else yap_or_woof = "WOOF";
  for(int i = 0; i < numTimes; i++){
    cout << yap_or_woof << " ";
    cout.flush();
    usleep(500000); // yap or woof every half second
  }
  cout << endl;
}
void Dog::wag(int numTimes, int howFast){
    addBone();
    if(isHappy){
     for(int i = 0; i < numTimes; i++){
       if(i%2 ==0) cout << "\\";
       else cout << "/ ";
       cout.flush();
       usleep(howFast * 1000);
     } 
      if(my_bone){
        cout << endl;
        delete my_bone;
        my_bone = nullptr;
      }
     cout << endl; 
    }
    else cout << "not happy, no wag :(";
}
void Dog::setWeight(double weight){
  this->weight = weight;
}
void Dog::setNumberOfLegs(int numLegs){
  if((numLegs <= 4) & (numLegs >=1)) numberOfLegs = numLegs;
  if(numLegs <= 0) numberOfLegs = 1;
  if(numLegs >= 4) numberOfLegs = 4;
}
void Dog::setHappiness(bool isHappy){
  this->isHappy = isHappy;
  }
void Dog::setEyeColor(string eyeColor){
 this->eyeColor = eyeColor; 
}
void Dog::setFurColor(string furColor){
 this->furColor = furColor; 
}
void Dog::addBone(){
  cout << "wow, thanks for the bone!\n";
  my_bone = new Bone;
  setHappiness(true);
}