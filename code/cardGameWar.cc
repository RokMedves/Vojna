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


  //for(unsigned int i = 0; i < 5; i++){
  while(!game_over_){
    // Find a winner by comparing the top cards of each players 
    // deck the winnings get allocated to the dealer_ and with
    // allocate_winnings() get distributed to the winner of the 
    // round. Who wins the round is stored in the winner enum
    find_winner();

    // at this point I have checked that the dealer_ does
    // indeed have 2 car ds and a deck_size() = 2
    allocate_winnings();
    // std::cout << *this << std::endl;
  }
  std::cout << "\tgame over!" << std::endl
	    << "Winner is " << winner << std::endl;
  return;
}

void CardGameWar::play_top_cards(){
  /// The dealer gets the top two cards and of each
  /// players deck.
  /// Checks if the game is over (cards could not be given).

  // Transfer cards to dealer and flip his win/play deck
  bool player1_transfer_success = dealer_.add_winnings(player1_);
  bool player2_transfer_success = dealer_.add_winnings(player2_);
  dealer_.transfer_win_to_play();

  // If any of the players could not transfer cards,
  // the game is over 
  if(!player1_transfer_success){
    winner = Winner::player2;
    game_over_ = true;
  }else if(!player2_transfer_success){
    winner = Winner::player1;
    game_over_ = true;
  }
   
  
  
  return;
}

bool CardGameWar::find_winner(){
  /// Checks whether player1 wins the round
  /// and writes that into into winner enum
  ///
  /// RM TODO:
  /// The return type tells you if the game is over
  

  // RM: TODO
  //     For now will NOT handle if the decks are empty.
  //     This functionality will be part of >, <, == later

  // Loop until the round is over
  // This is to get a winner even if == is called
  bool winner_decided = false;
  
  while(!winner_decided && !game_over_){
    
    if(player1_ > player2_){
      // If player 1 wins
      winner = Winner::player1;
      winner_decided = true;
    }else if( player1_ == player2_ ){
      // If the top cards are of equal power, then
      // do store two cards and compare the next
      play_top_cards();
      play_top_cards();
      winner_decided = false;
      continue;
    }else{
      // If player 2 wins
      winner = Winner::player2;
      winner_decided = true;
    }
  }
  
  // Take the top two cards off of each player
  play_top_cards();
  return game_over_;
}

void CardGameWar::allocate_winnings(){
  /// Allocates the winnings after a round
  /// from the dealer to the winning player
  ///
  /// To be used in conjuction with find_winner()

  // If no winner, there was an error in the code
  if(game_over_){return;}
  assert(winner != Winner::none &&
	 "alloacte_winnings() was called, but without a set winner");

  // If there was a winner, give him the winnings
  // point to the winner via a reference
  //
  // Has to be set by default, so lets make it to
  // the dealer to be safe
  //
  // Player & winning_player = dealer_;
  // ^ This was the source of the error! Cannot do this
  //   and then switch reference to something else!!!

  // Can accomplish the same with pointers
  Player * winning_player = nullptr;
  if(winner == Winner::player1){
    winning_player = &player1_;
  }else if (winner == Winner::player2){
    winning_player = &player2_;
  }
  // Give winnings to player referenced
  unsigned int n = dealer_.deck_size();
  for(unsigned int i = 0; i < n; ++i){
        winning_player->add_winnings(dealer_);    
  }

  // When done, set the winner to nobody
  winner = Winner::none;
  
  return;
}


