//#include <iostream>
#include "character_list.cpp" // I wanted to make a "character_list.h" but I couldn't figure out the header file template for c++ on repl.it
#include <fstream>

using namespace std;

// This function will take a file path and an empty list of characters, and fill
// the list from the file
int download_characters(string input_file_name, ofstream & battle_results_file, character &champ_a, character &champ_b) {
  ifstream character_info_file(input_file_name);
  string a_name, a_ability, b_name, b_ability;
  int a_hp, b_hp, attack_min, attack_max, ability_min, ability_max, potion_min,
      potion_max;

  a_hp = b_hp = attack_min = attack_max = ability_min = ability_max =
      potion_min = potion_max = 0; // clearing out previous values

  character_info_file >> a_name >> a_hp >> a_ability >> b_name >> b_hp >>
      b_ability >> attack_min >> attack_max >> ability_min >> ability_max >>
      potion_min >>
      potion_max; // grabbing and storing values of one character from the file

  //these "read_info" functions are defined in the character class
  champ_a.read_info(a_name, a_hp, a_ability, attack_min, attack_max,
                    ability_min, ability_max, potion_min, potion_max);
  champ_b.read_info(b_name, b_hp, b_ability, attack_min, attack_max,
                    ability_min, ability_max, potion_min, potion_max);
  battle_results_file << champ_a.show_name() << " (" << champ_a.show_hp() << " hp)" << " will battle " << champ_b.show_name() << " (" << champ_b.show_hp() << " hp)" << endl;  //Writing to the output file
  return 0;
}

//This function acts as the menu interface for the user
//It uses a switch statement and a recursive call (with the positions switched so
//the current champ will be the enemy upon each function call)

//--------------------------------
//---------BEGIN MENU FUNC---------
//--------------------------------
bool champ_menu(character champ, character enemy, bool & game_over, ofstream  
& battle_results_file) { 
  cout << "It's " << champ.show_name()
       << "'s turn.  Current HP = " << champ.show_hp() << endl;
  cout << "1. Attack\n"
       << "2. Use " << champ.show_ability() << endl
       << "3: Use a Potion " << "(" << champ.show_number_of_potions() << " remaining) " << endl;
       cout << "Enter action: ";
  int action = 0;
  cin >> action;
  cin.clear();
  cin.ignore(100, '\n');
  int damage_dealt = 0;
    switch (action) {  // switch statement to parse user input and deal with invalid input
    case 1:
      damage_dealt = champ.give_attack_damage();
      cout << champ.show_name() << " attacks!  ";
      battle_results_file << champ.show_name() << " attacks!  ";
      if (enemy.recieve_damage(damage_dealt) == -1) {
        cout << champ.show_name() << " Wins the Match!\n";
        battle_results_file << champ.show_name() << " Wins the Match!\n";  //Writing to ouptut file
        game_over = true;
        break;
      }
      cout << enemy.show_name() << " takes " << damage_dealt << " damage! New hp = " << enemy.show_hp() << endl;
      battle_results_file << enemy.show_name() << " takes " << damage_dealt << " damage! New hp = " << enemy.show_hp() << endl; //Writing to output file
      break;

    case 2:
      damage_dealt = champ.give_ability_damage();
      cout << champ.show_name() << " uses " << champ.show_ability() << "! ";
      battle_results_file << champ.show_name() << " uses " << champ.show_ability() << "! ";
      if (enemy.recieve_damage(damage_dealt) == -1) {
        cout << champ.show_name() << " Wins the Match!\n";
        battle_results_file << champ.show_name() << " Wins the Match!\n";  //Writing to output file
        game_over = true;
        break;
      }
      cout << enemy.show_name() << " takes " << damage_dealt << " damage! New hp = " << enemy.show_hp() << endl;
      battle_results_file << enemy.show_name() << " takes " << damage_dealt << " damage! New hp = " << enemy.show_hp() << endl; //Writing to output file
      break;

    case 3:   
      if (champ.out_of_potions()) { //this is false until the champ is fully out of potions
        cout << champ.show_name() << " is out of potions.\n";
        champ_menu(champ, enemy, game_over, battle_results_file);
      break;
      }
      if(champ.show_hp() == champ.show_max_hp()){ //making sure the champ doesn't already have max health
        cout << champ.show_name() << " already has max health.\n";
        champ_menu(champ, enemy, game_over, battle_results_file); //conditional recursive call, basically starting the menu over
        break;
      }
      cout << champ.show_name() << " chugs a potion and recovers "
           << champ.use_potion() << " hp!  New hp = " << champ.show_hp()
           << endl;
      battle_results_file << champ.show_name() << " chugs a potion and recovers "
           << champ.use_potion() << " hp!  New hp = " << champ.show_hp()
           << endl;
      break;

    default:
      cout << "Bad input." << endl;
      champ_menu(champ, enemy, game_over, battle_results_file);
      break;
    }
  cout << endl;
  if(!game_over) champ_menu(enemy, champ, game_over, battle_results_file);   //It is likely unorthodox to use recursion here. But it seems to work fine.  
  //Notice the enemy and champ are in opposite spots from where they were passed in.
  battle_results_file.close();
  return game_over; // this returns true if game is over
}
//--------------------------------
//-----------END MENU FUNC----------
//--------------------------------

int main() {
  bool game_over = false;
  character champ_a, champ_b;
  string character_info_file = "characterInfo.txt";
  ofstream battle_results_file("battleResults.txt");
  download_characters(character_info_file, battle_results_file, champ_a, champ_b);

  cout << champ_a.show_name() << " (" << champ_a.show_hp() << " hp)" << " will battle " << champ_b.show_name() << " (" << champ_b.show_hp() << " hp)" << endl;
  
  champ_menu(champ_a, champ_b, game_over, battle_results_file);
  battle_results_file.close();
  return 0;
}