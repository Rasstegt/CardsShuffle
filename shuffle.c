/* Student Name: Arslan Khalikov
 * Student Number: 991530126
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SUITS 4
#define RANKS 13
#define DECK_SIZE 52

typedef struct {
  char *rank;
  char *suit;
  char *colour;
} Card;

Card *make_deck ();
void print (Card *);
void shuffle (Card *);

int main () {

  Card *deck = make_deck();

  printf(" *************** Original Deck ***************\n");
  print (deck);

  printf("\n\n *************** Shuffled Deck ***************\n");
  shuffle (deck);
  print (deck);

  // To free the allocated memory from Card* make_deck()
  free(deck);
  deck = NULL;

  return 0;
}

Card* make_deck() {
  // Char arrays to fill out the pointers in Card struct
  char *ranks[] = {"King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2", "Ace"};
  char *suits[] = {"Spades", "Clubs", "Hearts", "Diamods"};
  char *colour[] = {"Black", "Red"};

  // To allocate the space for the pointer
  Card *deck = (Card*) malloc(DECK_SIZE*RANKS * sizeof(DECK_SIZE));

  // Assigning the indexes of char arrays to index of deck pointer
    int s=0, r=0, c=0;
    for(int x = 0; x < DECK_SIZE; x++){
      deck[x].suit = suits[s];
      deck[x].rank = ranks[r++];
      deck[x].colour = colour[c];

      if(r == RANKS) {
        r = 0;
        s++;
        if(s == SUITS/2)
        c++;
      }
  }
  return deck;
}

// Printing out the decks. Matches the length of DECK_SIZE constant
void print(Card *deck) {
	for (int i=0; i < DECK_SIZE; i++){
			printf("\t%s\t%s\t%s\n", deck[i].colour, deck[i].suit, deck[i].rank); 
	}
}

// Shuffles the cards one by one using temp char pointers and randomizes it by srand();
void shuffle (Card *deck) {
    char *tempSuit, *tempRank, *tempColor;
    srand(time(0)); 

    for(int i = 0; i < DECK_SIZE; i++){

      int ranPos = rand() % DECK_SIZE;
      tempColor = deck[i].colour;
      tempSuit = deck[i].suit;
      tempRank = deck[i].rank;
      deck[i] = deck[ranPos];
      deck[ranPos].colour = tempColor;
      deck[ranPos].suit = tempSuit;
      deck[ranPos].rank = tempRank;
    }

}
