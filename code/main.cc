#include<iostream>
// #include "cardGameWar.hh"
#include "cards.hh"
#include "player.hh"


void test_cards_hh(){
    /*
    RM: Things that have been tested:
        ~cards.cc
        - deck constructor
	- print_cards
	- << operator for card class
	
	- shuffle deck() (called from constructor)
	- empty_deck()
	- push_deck(pop_deck())
	- pop_deck()
	- push_deck(pop_deck()) for two different decks 
  */
  std::cout << "works" << std::endl;

  // testing creating the object with a seed
  // testing shuffle deck
  Cards deck {2020};
  Cards deck2 {2019};

  // testing printing the cards
  // deck.print_cards();
  std::cout << deck << std::endl;

  // testing popping and pushing the deck
  deck.push_deck(deck.pop_deck());
  std::cout << deck << std::endl;

  // testing << operator for card_
  std::cout << std::endl << std::endl;
  std::cout << deck.pop_deck() << std::endl; 

  // testing emptying the deck
  deck.empty_deck();
  std::cout << deck << std::endl;
  deck.push_deck(deck2.pop_deck());
  std::cout << deck << std::endl;

}

void test_player_hh(){

  Player player1 {2020};
}

int main(int argc, char* argv[]){
  // test_cards_hh();
  test_player_hh();

  // --------------------- end ---------------------
  return 0;
}
