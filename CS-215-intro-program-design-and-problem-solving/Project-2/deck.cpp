/* File:    desk.cpp
 * Course:  CS215-002
 * Project: Project 2
 * Purpose: the implementation of member functions for the Desk class.
 * Author:  Elijah Russell
 */

#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "deck.h"
#include "card.h"

Deck::Deck() {}

void Deck::createDeck() 
{
    const char suits[] = { 'D', 'C', 'H', 'S' };
    for (int p = 2; p <= 14; p++)
    {
        for (char s : suits)
        {
            deck.push_back(Card(s, p));
        }
    }
};

// shuffle the cards in 52-card deck
void Deck::shuffleDeck()
{
    srand(time(0));
    random_shuffle(deck.begin(), deck.end());
};

// return a card from the tail of the deck
Card Deck::deal_a_card() 
{
    Card c = deck.back();
    deck.pop_back();
    return c;
};

void Deck::print() const        
{
    for (size_t i = 0; i < deck.size(); ++i) {
        deck[i].print();
        std::cout << "\t";
        if ((i + 1) % 13 == 0)
            std::cout << endl;
    }
}