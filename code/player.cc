#include "player.hh"


// --------------------------printing methods-----------------------

std::ostream & operator<<(std::ostream & out, const Player & player) {
  /// Prints the current playing and winning decks of a player
  out << "Current playing deck: " << std::endl
      << player.play_deck
      << std::endl << "Current winnings deck: " << std::endl
      << player.win_deck
      << std::endl;
  
  return out;
}

// overloading >, < and == for determining the winners

bool Player::operator> (Player & player2){
  /// Test if the top card of one players deck has a
  /// value grater than the top card of the other player

  // check if decks need switching
  if (deck_size() == 0){
    transfer_win_to_play();
    // if deck still empty, the player lost
    if(deck_size() == 0) return false;
  }
  if (player2.deck_size() == 0){
    player2.transfer_win_to_play();
    // if deck still empty, the player lost
    if(deck_size() == 0) return true;
  }
  return (play_deck.top_card().face >
	  player2.play_deck.top_card().face);
}

bool Player::operator< (Player & player2){
  /// Test if the top card of one players deck has a
  /// value smaller than the top card of the other player

  if (this->deck_size() == 0){
    this->transfer_win_to_play();
    // if deck still empty, the player lost
    if(deck_size() == 0) return true;
  }
  if (player2.deck_size() == 0){
    player2.transfer_win_to_play();
    // if deck still empty, the player lost
    if(deck_size() == 0) return false;
  }
  return (play_deck.top_card().face <
	  player2.play_deck.top_card().face);
}

bool Player::operator== (Player & player2){
  /// Test if the top card of one players deck has a
  /// value equal than the top card of the other player

  if (this->deck_size() == 0){
    this->transfer_win_to_play();
    // if deck still empty, the player lost
    if(deck_size() == 0) return false;
  }
  if (player2.deck_size() == 0){
    player2.transfer_win_to_play();
    // if deck still empty, the player lost
    if(deck_size() == 0) return false;
  }
  return (play_deck.top_card().face ==
	  player2.play_deck.top_card().face);
}


// Other methods

bool Player::add_winnings(Player & player){
  /// Removes the top card from the player's play_deck
  /// and adds it to *this's win_deck
  ///
  /// The return type indicates whether the winnings
  /// were transferred correctly:
  ///   -> true:  transfer made
  ///   -> false: player ran out of cards

  // Test if the player's hand is empty and furthermore
  // if he has no cards in general. Returns false if so
  if(player.deck_size() == 0){
    player.transfer_win_to_play();
    if(player.deck_size() == 0) return false;
  }

  // push the card onto the deck
  this->win_deck.push_deck(player.play_deck.pop_deck()); 
  
  return true;
}


void Player::top_card() const{
  /// prints the top card of the players playing deck
  std::cout << play_deck.top_card() <<  std::endl;
  return;
}

unsigned int Player::deck_size() const{
  /// Returns the play_deck's size
  return play_deck.deck_size(); 
}

void Player::transfer_win_to_play(){
  /// Transfers the winning to the playing decks.
  /// Will be called when either one is empty.
  /// Crutial assuption:
  /// That the playing deck is empty

  // check that play deck really empty
  // RM: This is from before when I though this method
  //     would switch the winning and playing decks
  // assert(play_deck.deck_size() == 0);

  //go through winnings deck and transfer
  unsigned int win_deck_size = win_deck.deck_size();
  for(unsigned int i = 0; i < win_deck_size; ++i){
    play_deck.push_deck(win_deck.pop_deck());
  }
  
  return;
}

