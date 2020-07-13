#include<iostream>
#include "cardGameWar.hh"
#include "cards.hh"
#include "player.hh"


void test_cards_hh(){
  /// Tests cards.hh and cards.cc functionality
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
  /// Tests player.hh and player.cc functionality

  bool player1_starts_with_empty_deck = false;
  Player player1 {player1_starts_with_empty_deck, 2020};
  
  // Test printing -- Works
  std::cout << player1 << std::endl;

  // test transferring deck -- Works
  /*
  player1.empty_playing_deck();
  std::cout << player1 << std::endl;
  player1.transfer_win_to_play();
  std::cout << player1 << std::endl;
  */

  Player player2 {false, 2019};

  player1.top_card();
  player2.top_card();
  // testing the >, < and == operators: -- Works
  std::cout << "> " << (player1 >  player2) << std::endl
	    << "< " << (player1 <  player2) << std::endl
  	    << "== "<< (player1 == player2) << std::endl;
}

void test_card_game_war_hh(){
  /// Tests player.hh and player.cc functionality
  CardGameWar game {2020};

  // Testing printing methods
  // split_deck() validated through constructor
  // constructor validated
  std::cout << game << std::endl;

  // testing other functionality
  // allocate_winnings() NOT WORKING!!!
  game.play_war();
  std::cout << game << std::endl;

  
  return;
}

int main(int argc, char* argv[]){
  // test_cards_hh();
  // test_player_hh();

  test_card_game_war_hh();


  // --------------------- end ---------------------
  return 0;
}
