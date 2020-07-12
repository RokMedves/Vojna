///
/// definitions of certaing methods from cards.hh
///

#include "cards.hh"
#include <cassert>

// ------------------- printing methods -------------------
void Cards::print_cards() const {
  std::cout << "size of hand: " << deck_size_ << std::endl;
  for (int i = 0; i < deck_size_; ++i){
    std::string suit = "error";

    if(deck_[i].suit == card_suit_::clubs)         suit = "clubs";
    else if(deck_[i].suit == card_suit_::hearts)   suit = "hearts";
    else if(deck_[i].suit == card_suit_::diamonds) suit = "diamond";
    else if(deck_[i].suit == card_suit_::spades)   suit = "spades";
      
    std::cout << suit << "\t" << static_cast<int>(deck_[i].face) << std::endl;
  }
  return;
}

//ostream already defined in cards.hh
std::ostream & operator<< (std::ostream & out, const Cards & cards){
 for (int i = 0; i < cards.deck_size_; ++i){
    std::string suit = "error";

    if(cards.deck_[i].suit == cards.card_suit_::clubs)         suit = "clubs";
    else if(cards.deck_[i].suit == cards.card_suit_::hearts)   suit = "hearts";
    else if(cards.deck_[i].suit == cards.card_suit_::diamonds) suit = "diamond";
    else if(cards.deck_[i].suit == cards.card_suit_::spades)   suit = "spades";
      
    out << suit << "\t" << static_cast<int>(cards.deck_[i].face) << std::endl;
  }
 return out;
}

std::ostream & operator<< (std::ostream & out, const Cards::card_ & card){

  std::string suit = "error";
  if(card.suit == Cards::card_suit_::clubs) suit = "clubs";
  else if(card.suit == Cards::card_suit_::hearts) suit = "hearts";
  else if(card.suit == Cards::card_suit_::diamonds) suit = "diamond";
  else if(card.suit == Cards::card_suit_::spades) suit = "spades";

  out << suit << '\t' << static_cast<int>(card.face) << std::endl;
  
  return out;
}

// ------------------- end ~ printing methods --------------


// deck manipulation methods
void Cards::shuffle_deck(shuffle_strategy strategy, int seed = 0){
  /// shuffles the deck
  srand(seed);
  if (strategy == shuffle_strategy::no_shuffle){return;}
  else if (strategy == shuffle_strategy::quick_shuffle){
    unsigned int size = deck_size();
    unsigned int active_size = size;

    card_ placeholder_card;
    for(unsigned i = 0; i < size; ++i){
      // get the rand_pos and switch it to the last position & reduce
      // the active_size by 1
    
      unsigned int rand_pos = rand() % active_size;
      placeholder_card = deck_[rand_pos];
      deck_[rand_pos] = deck_[active_size - 1];
      deck_[active_size - 1] = placeholder_card;
   
      --active_size;
    }
  return;
  }
  else if(strategy == shuffle_strategy::dumb_shuffle){return;} //TO BE IMPLEMENTED
}

void Cards::empty_deck(){
  /// empties the deck, sets deck size to 0

  // replace all cards to empty cards, just in case
  // RM: is this necessary?
  for(unsigned int i = 0; i < deck_size_; ++i ){
    deck_[i] = empty_card_;
  }
  deck_size_ = 0;
  return;
}

void Cards::push_deck(const card_ & card){
  /// Adds a card to the top of the deck and
  /// increments the deck size by 1

  // if the deck is too big, kill it!
  assert(deck_size_ < 52 && "deck size too big!");

  deck_[deck_size_] = card;
  // RM: how will this work if it's now a reference though?
  //     will this get dereferenced for some reason?
  //     next day: Yes, so this is now implemented with a reference
  
  // increment deck size by 1
  ++deck_size_;

}

Cards::card_ & Cards::pop_deck(){
  /// Removes the top card from the deck
  /// and returns that card via a reference
  
  //check that there are cards to pop
  assert(deck_size_ > 0 && "deck is empty!");
  card_ & top_card = deck_[deck_size_ - 1];
  
  // Query RM: Is is wrong not setting the card to zero?
  // 
  // deck_[deck_size_ - 1] = empty_card_;
  // ^                   ^
  // SOURCE OF POTENTIAL ERRORS!!!!!!
  --deck_size_;
  return top_card;

}
