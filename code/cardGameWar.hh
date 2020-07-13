

#ifndef _CARDGAMEWAR_HH_
#define _CARDGAMEWAR_HH_

#include "cards.hh"
#include "player.hh"

class CardGameWar{

public:
  CardGameWar(int seed = 2020){
    
    // Initialize both players with empty hands (hence the true)
    player1_ = Player{true};
    player2_ = Player{true};

    // Initialize dealer with full hand
    // and shuffle the deck
    dealer_ = Player{false, seed};
    dealer_.shuffle_deck();

    // Split the dealer's deck between both players
    split_deck();
    player1_.transfer_win_to_play();
    player2_.transfer_win_to_play();
    
    // Now both players should have half of a shuffled deck
    //
    // Set the game state variable
    game_over_ = false;
  }

  // Printing methods
  friend std::ostream & operator<<(std::ostream & out, const CardGameWar & game);
  
  // Method to run the game
  void play_war(); 

  
  
private:
  //For now just look at getting the game working for 2 players
  // RM Query old: Can these player references become const?
  //               See learn c++ section on agregation for answer...

  // For now, players will be maintained by the class (see the README.md)
  Player player1_;
  Player player2_;

  // Player who deals with the cards and keep a stack of
  // the winnings to distribute to the players
  Player dealer_;

  // Game state variables
  bool game_over_ = false;
  
  // Methods called from playWar()
  bool find_winner();
  void allocate_winnings();
  
  // When players get initialized their hands get split in 2
  void split_deck();

  // enum keeping track of the winner of the round
  enum class Winner{
    none,
    player1,
    player2
  };

  Winner winner = Winner::none;

  // printing operator for Winner
  friend std::ostream & operator<< (std::ostream & out, Winner winner);

};

#endif //_CARDGAMEWAR_HH_
