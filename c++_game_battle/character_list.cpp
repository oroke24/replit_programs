#include <string>
#include <time.h>
#include <iostream>
using namespace std;

class character{
  public:
    //reading in all the pieces that make a character from a function in main (the client)
    //because going through a file and finding such information is not a characters job
    int read_info(string name, int hp, string ability, int attack_min, int ability_min, int ability_max, int attack_max, int potion_min, int potion_max){
      
      this->name = name; 
      this->ability = ability;
      this->hp = this->max_hp = hp;
      this->attack_min = attack_min;
      this->attack_max = attack_max;
      this->ability_min = ability_min;
      this->ability_max = ability_max;
      this->potion_min = potion_min;
      this->potion_max = potion_max;
      number_of_potions = 3;
      
      return 0;
    }
    //Recieve damage, give damage, and use potion functions are things 
    //only a character should be able to do 
    //that is why they are not a in a data structure or client)
    int recieve_damage(int incoming_damage){
      hp -= incoming_damage;
      if(hp <= 0) return -1;
      return 0;
      } // the incoming_damage will literally be another character objects give_damage(); function call.   
    int random_between(int min, int max){
        srand(time(NULL));
        return (rand() % max + min);
    }
    int give_attack_damage(){return random_between(attack_min, attack_max);}
    int give_ability_damage(){return random_between(ability_min,ability_max);}
    int give_potion_health(){return random_between(potion_min,potion_max);}
    int use_potion(){
      int potion = give_potion_health();
      if(potion + hp > max_hp){
        int deduction = (potion + hp) - max_hp;
        potion = potion - deduction;
      }
      hp += potion;
      number_of_potions--;
      if(number_of_potions < 0) number_of_potions = 0;
      return potion;
      } 

    void display(){
      cout << "--------" << endl;
      cout << name << " " << hp << " " <<  ability << endl;
      cout << "--------" << endl;
    }
    string show_name(){return name;}
    int show_hp(){return hp;}
    int show_max_hp(){return max_hp;}
    string show_ability(){return ability;}
    int show_number_of_potions(){return number_of_potions;}
    bool out_of_potions() {
      if(number_of_potions <= 0) return true;
      return false;
    }

//this will use the private variables potion_min and potion_max as min/max limits for a random healing ability
  private:
    string name, ability;
    int max_hp, hp, attack_min, attack_max, ability_min, ability_max, potion_min, potion_max, number_of_potions;
};