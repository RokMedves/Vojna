

#ifndef _PLAYER_HH_
#define _PLAYER_HH_
#include "cards.hh"

class Player{

public:

  Player (bool empty_start = true, int seed = 0){
    play_deck = Cards {seed};
    win_deck = Cards {seed};

    // 
    if(empty_start){
      win_deck.empty_deck();
      play_deck.empty_deck();
    }
  }

  // printing methods
  friend std::ostream & operator<< (std::ostream & out, const Player & player);

  // methods for comparing who has the better cards in cardGameWar.hh/.cc
  bool operator> (const Player & player2) const;
  bool operator< (const Player & player2) const;
  bool operator== (const Player & player2) const;

  // other methods

  // switches the winning and playing deck,
  // initing the win_deck again
  void transfer_win_to_play();
  void top_card() const;

  // for testing purposes
  void empty_playing_deck(){
    play_deck.empty_deck();
  }
private:
  /// Each player had a deck they play with, i.e. a play_deck
  /// and a deck they put their winnings in - the win_deck
  ///
  /// The game will check whether the play_deck is empty and if so,
  /// will switch out the play and win decks, modulo a shuffle. 
  Cards play_deck;
  Cards win_deck;
  
};


#endif // _PLAYER_HH
