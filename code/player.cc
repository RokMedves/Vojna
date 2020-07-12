#include "player.hh"


// --------------------------printing methods-----------------------

std::ostream & operator<<(std::ostream & out, const Player & player) {
  /// Prints the current playing and winning decks of a player
  out << "Current playing deck: " << player.play_deck
      << std::endl << "Current winnings deck: " << player.win_deck
      << std::endl;
  
  return out;
}

// overloading >, < and == for determining the winners

bool Player::operator> (const Player & player2) const{
  /// Test if the top card of one players deck has a
  /// value grater than the top card of the other player
  return (play_deck.top_card().face >
	  player2.play_deck.top_card().face);
}

bool Player::operator< (const Player & player2) const{
  /// Test if the top card of one players deck has a
  /// value smaller than the top card of the other player
  return (play_deck.top_card().face <
	  player2.play_deck.top_card().face);
}

bool Player::operator== (const Player & player2) const{
  /// Test if the top card of one players deck has a
  /// value equal than the top card of the other player
  return (play_deck.top_card().face ==
	  player2.play_deck.top_card().face);
}


// Other methods

void Player::top_card() const{
  /// prints the top card of the players playing deck
  std::cout << play_deck.top_card() <<  std::endl;
  return;
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

