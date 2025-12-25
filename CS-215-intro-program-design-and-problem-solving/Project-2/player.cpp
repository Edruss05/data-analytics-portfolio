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
#include "player.h"

Player::Player() {}

Player::Player(vector<Card> ini_cards)
{
    for (auto c : ini_cards)
        cards.push_back(c);
    numCards = cards.size();
}

int Player::getNumCards() const
{
    return numCards;
}

Card Player::play_a_card()
{
    Card top = cards.front();
    cards.pop_front();
    numCards--;
    return top;
}

void Player::addCards(const vector<Card>& wonCards)
{
    for (auto c : wonCards)
        cards.push_back(c);
    numCards = cards.size();
}

vector<Card> Player::dropCards()
{
    vector<Card> dropped;
    while (!cards.empty())
    {
        dropped.push_back(cards.front());
        cards.pop_front();
    }
    numCards = 0;
    return dropped;
}

void Player::print() const
{
    for (Card c : cards) {
        c.print();
        std::cout << " ";
    }
    std::cout << endl;
}