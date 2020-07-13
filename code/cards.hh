///
/// Class containing playing cards
/// First idea: To have it as a stack, all programmed with
///             enums holding the definitions of the cards.
/// Note: This class will ahve to keep track of the deck size at all times.
///



#ifndef _CARDS_HH_
#define _CARDS_HH_

#include<cstdlib>
#include<cassert>
#include<iostream>

class Cards{
private:
  struct card_; // forward declaration of the struct
                // so that other methods can even define it. 

  
public:

  // shuffle strategies made open to be used in player.hh
  // THE ONLY REASON WHY THIS IS PUBLIC IS BECAUSE
  // I WANTED IT PRIVATE BUT PLAYER.HH COULD NOT MAKE USE OF IT
  enum class shuffle_strategy { //use this later!
    no_shuffle,
    quick_shuffle,
    dumb_shuffle,
  };
  
  Cards(int seed = 0){
    /// returns a whole stack of cards if not initializing with an object
    /// use for loop to iterate through the enums and fill in the cards, then shuffle them
    /// RM: Turns out in C++ you can't easily iterate through enums unless
    ///     you also overload the ++ operator ... Better to just hard code the sizes

    //iterate through suits 
    for (unsigned int suit = 0; suit < 4; ++suit){
      //iterate through faces
      for(unsigned int face = 2; face <= 14; ++face){
	deck_[deck_size_].suit = static_cast<card_suit_>(suit);
	deck_[deck_size_].face = static_cast<card_face_>(face);
	++deck_size_;
      }
    }
    // RM: to make shuffle_deck() work we MUST fill this in by default
    shuffle_deck(shuffle_strategy::quick_shuffle, seed);

    //also init the empty card; 
  }
  ~Cards(){}

  // printing methods
  void print_cards() const;
  friend std::ostream& operator<< (std::ostream & out, const Cards & cards);
  friend std::ostream & operator<< (std::ostream & out, const card_ & card); //must be a friend to access card_, card_face_ etc.

  // card and deck manipulation methods
  card_ top_card() const;
  void shuffle_deck(shuffle_strategy strategy, int seed);
  void empty_deck();
  card_ & pop_deck();
  void push_deck(const card_ & card);
  // possible transfer_deck function which does many pushes & pops in game class 
  
  int deck_size() const {
    // RM: This assumes that the deck_ is always filled with something.
    // RM: maybe if make an if here that triggers if deck_size_ is out of bounds?
    return deck_size_;
  }  

private:
  /// cards
  //contains the card's value
  enum class card_face_{
    empty = 0,
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
  };
  //contains the card's suit
  enum class card_suit_{
    clubs,
    diamonds,
    hearts,
    spades
  };
  
  
  // what a card is - it has a value and a suit 
  struct card_{
    card_face_ face;
    card_suit_ suit;
  };

  
  //a complete deck of cards
  card_ deck_[53];
  card_ empty_card_ = {card_face_::empty, card_suit_::clubs};
  int deck_size_ = 0;
};



#endif //_CARDS_HH_
