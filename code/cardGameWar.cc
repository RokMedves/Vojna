#include "cardGameWar.hh"

// Printing methods
std::ostream & operator<<(std::ostream & out, const CardGameWar & game){
  /// Prints the players hands and the game state 
  out << "######### Printing Players #########"  << std::endl
      << "Player1:"<< std::endl << game.player1_ << std::endl
      << "Player2:"<< std::endl << game.player2_ << std::endl
      << std::endl << std::endl << std::endl     << std::endl
    
      << "######### Printing Game State #########" << std::endl
      << std::endl  << "The dealer:" << std::endl 
      << game.dealer_ << std::endl   << std::endl
      << "is game over: " << game.game_over_ << std::endl
      << "player1 play_deck size: " << game.player1_.deck_size()
      << std::endl
      << "player2 play_deck size: " << game.player2_.deck_size()
      << std::endl
      << "dealer  play_deck size: " << game.dealer_.deck_size()
      << std::endl;
    
  return out;
}

std::ostream & operator<< (std::ostream & out, CardGameWar::Winner winner){
  /// Makes the Winner type readable
  /// this is a friend function so that it can access the Winner type
  if(winner == CardGameWar::Winner::none){
    out << "none";
  }else if(winner == CardGameWar::Winner::player1){
    out << "player1";
  }else if(winner == CardGameWar::Winner::player2){
    out << "player2";
  }else{
    out << "Major error. winner is not set properly";
  }
  return out;
}



void CardGameWar::split_deck(){
  /// Splits the dealer's cards equally between
  /// both players

  unsigned int n = dealer_.deck_size();
  for(unsigned int i = 0; i < n; ++i){

    if(i % 2 == 0) {
      player1_.add_winnings(dealer_);
    }else{
      player2_.add_winnings(dealer_);
    }
    
  }
    
  return;
}

void CardGameWar::play_war(){
  /// Runs the game
  dealer_.add_winnings(player1_);
  dealer_.add_winnings(player2_);
  dealer_.transfer_win_to_play();
  winner = Winner::player1;
  std::cout << "the winner is " << winner << std::endl;
  this->allocate_winnings(); //NOT WORKING!
  
  return;
}

bool CardGameWar::find_winner(){
  /// Checks whether player1 wins the round
  
  return true;
}

void CardGameWar::allocate_winnings(){
  /// Allocates the winnings after a round
  /// from the dealer to the winning player
  ///
  /// To be used in conjuction with find_winner()

  // If no winner, there was an error in the code
  assert(winner != Winner::none &&
	 "alloacte_winnings() was called, but without a set winner");

  // If there was a winner, give him the winnings
  // point to the winner via a reference
  //
  // Has to be set by default, so lets make it to
  // the dealer to be safe
  Player & winning_player = dealer_; 
  if(winner == Winner::player1){
    winning_player = player1_;
  }else if (winner == Winner::player2){
    winning_player = player2_;
  }

  // Give winnings to player referenced
  unsigned int n = dealer_.deck_size();
  for(unsigned int i = 0; i < n; ++i){
    winning_player.add_winnings(dealer_);    
  }

  // When done, set the winner to nobody
  winner = Winner::none;
  
  return;
}


