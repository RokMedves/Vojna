# Vojna
Simulation of card game War in C++

## Structure of Code

### General structure
1. main.cc creates a CardGameWar() object.
2. CardGameWar() creates two Player() objects by composition.
   The class also creates two card objects. One gets emptied out
   and the other gets shuffled --> Half the deck gets popped to
   the other empty half. This gets passed to the two Player()
   objects via their constructor.
3. Players have two decks - a play deck, where they play cards from
   and a win_deck, which gets the winnings
4. CardGameWar::play() gets called from main.cc
   - checks if game is over
   - calls find_winner() until a winner is found 
     - This compares the two players and determined a winner
       (via overloaded >, < or ==). When the result is known
       an appropriate amount of cards get popped and pushed from
       one player to another.
   - once winner found, give him the cards.
   - repeat until game over 

### main.cc
- Runs the code
- as of 12/07/2020 also has test functions to test separate pieces of code
  (the below .hh and associated .cc files)
  [Todo: move these to a separate .hh included in main.cc]

### cards.hh, cards.cc
- Definition of cards (faces and values are enum classes)
- Objects are interpreted as a deck or a stack of cards which players use in a game
- Defined functions:
  1. print_cards() and overloaded operator<< for a single card and a Card object (a stack of cards)
  2. shuffle_deck()
  3. empty_deck()
  4. pop_deck(): removed a card at the top of the deck and returns it as a reference
  5. push_deck(): accepts a card and puts it on top of the deck
  6. deck_size()
  7. top_card(): gets the top card of the deck (not a reference to it!)

### player.hh, player.cc
- Defined functions:
  1. operator<<(): prints the playing and winning decks
  2. operator>(), operator<(), operator==():
     compares the top card of the play_decks of two players
  3. transfer_win_to_play(): transfers the win deck to the play deck
     (to be used when the play deck is empty)
  4. top_card(): prints the top card of the players play_deck
  5. empty_playing_deck(): [FOR TESTING] empties the play_deck

### cardGameWar.hh, cardGameWar.cc
- Outlines the rules of the game. Plays the game via playWar()
- Since Players would not be used anywhere outside of the game,
  they are introduced via composition (uses-a relationship) rather
  than being passed as a reference.
  This could change if the user wanted to customize the player i.e.
  by adding names etc. _For now will all be managed from inside CardGameWar_

## To Do

### cards.hh, cards.cc
- implement dumb_shuffle shuffling strategy

### player.hh, player.cc

- when testing for >, <, == between players, these operators should handle
  the win_deck and play_deck interactions.
  If both become empty, an internal bool has_lost in Player should be
  triggered and tested for in CardGameWar.

## Issues

### cards.hh, cards.cc

- It is important to think about how the game class will create and distribute cards between players. While it is easy to create a whole deck in the constructor, one should also have a method that splits the deck in two, three, etc. equal parts. Then a copy constructor would need to be used for the players hands. 
- a function would be enough which gets a deck, does a size check, and returns an array of card objects. These are used to init the hands. 

### player.hh, player.cc
- There might be an issue with how we check in cardGameWar, which player has the stronger card....
  I got it - the > operator!!
- Still might need to figure our the logic, because saying that player1 is beter than player2
  in real life is a bit of a stretch... It is the current hands which are better/worse in reality... Can this be implemented?

# Things learnt

- If you have an enum defined in the private section of a class,
  then friend functions can make use of them; You _do not_ need
  to use an object!
  Example: friends std::ostream & operator<< () in CardGameWar will
  	   be able to use the Winner type, though it is private and
	   the function does not accept an object! Super nice