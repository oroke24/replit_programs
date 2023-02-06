#include <string>
#include "Bone.h"
using namespace std;

class Dog{
  public:
    Dog(string name);
    ~Dog();
    void run(int howFar, int howFast);
    void bark(int numTimes);
    void wag(int numTimes, int howFast);
    //^run, bark, and wag are the methods that do more than set.  
    //The below functions are just setters
    void setWeight(double weight);
    void setNumberOfLegs(int numLegs);
    void setHappiness(bool isHappy);
    void setEyeColor(string eyeColor);
    void setFurColor(string furColor);
    void addBone();

  private:
    int numberOfLegs;
    string eyeColor, furColor, name;
    float weight;
    bool isHappy;
    Bone * my_bone;
};