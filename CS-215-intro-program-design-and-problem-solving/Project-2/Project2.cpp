/*
 * Course:  CS215-002
 * Project: Project 2
 * Purpose: Play the card game war
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
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main()
{
    const int HANDS = 26; //number of cards in a hand at the start
    const int BOTH_HANDS = HANDS * 2; //number of cards in the deck
    bool gameOver = false;
    Deck playDeck; //initialize deck object called playDeck
    playDeck.createDeck(); //create the deck
    playDeck.shuffleDeck(); //shuffle deck
    //playDeck.print(); //prints deck for debugging purposes
    //std::cout << endl << endl; //formatting for readability when debugging


    vector<Card> p1cards, p2cards;
    for (int i = 0; i < BOTH_HANDS; i++)
    {
        if (i % 2 == 0 || i == 0) //give player1 every other card (even numbers)
        {
            p1cards.push_back(playDeck.deal_a_card()); //deal player1's cards
        }
        else //give player2 every other other card (odd numbers)
        {
            p2cards.push_back(playDeck.deal_a_card()); //deal player2's cards
        }
    }

    Player player1(p1cards);
    Player player2(p2cards);
    //player1.print(); //prints player1's hand for debugging purposes
    //player2.print(); //prints player2's hand for debugging purposes

    int round = 0; //initialize round variable starting at 0 
    //(used to present user with continue message all but first round)
    int num_pile = 0; //initialize variable for number of cards in the pile
    const int norm_cards_played = 2; //cards layed down normally
    const int draw_cards_played = 6; //cards layed down in a draw
    int p1_cards_b4_draw = 0; //initialize variable to store player1's number of cards before laying down draw cards
    int p2_cards_b4_draw = 0; //initialize variable to store player2's number of cards before laying down draw cards

    while (gameOver == false) //while both players still have cards
    {
        // /* //start of comment out for testing
        if (round > 0) //don't present message first round
        {
            std::cout << "\nDo you want to continue...for the next round? (N or n to quit)";
            //present continue message

            //get input answer from continue message
            string input;
            getline(cin, input);
            stringstream ss(input);

            //if quit input detected then exit the loop and end program
            if (input == "N" || input == "n")
            {
                break;
            }
        }
        // */ //end of comment out for testing

        round++; //increase round marker, activating continue message
        const int MAX_ROUNDS = HANDS * 100; //prevents infinte game by setting maximum number of hands to be played to 100 hands

        if (player1.getNumCards() == 0 || player2.getNumCards() == 0) //if one player is out of cards end game
        {
            break; //end game
        }
        Card c1 = player1.play_a_card(); //play player1's card
        Card c2 = player2.play_a_card(); //play player2's card
        num_pile = norm_cards_played; //set number of cards in the pile to how many were played

        std::cout << "Player 1 plays: ";
        c1.print(); //display what card player1 played
        std::cout << endl; //formatting
        std::cout << "Player 2 plays: ";
        c2.print(); //display what card player2 played
        std::cout << endl; //formatting
        std::cout << "----------------------------------------------" << endl; //formatting
        std::cout << endl; //formatting
        std::cout << "There are " << num_pile << " cards on the pile!" << endl; //display number of cards in the pile currently
        std::cout << endl; //formatting
        std::cout << "----------------------------------------------" << endl; //formatting

        vector<Card> pile = { c1, c2 }; //put played cards into vector together for comparison
        int result = c1.compareTo(c2); //compare cards

        int draws = 0; //initialize and set to 0 draw counter
        int tie_result = 2; //initialize with insignificant value
        while (result == 0)
        {
            draws++; //increase draw count
            num_pile = (draw_cards_played * draws) + (norm_cards_played * draws); //number of cards in the pile accounting for how many draws there have been

            p1_cards_b4_draw = player1.getNumCards(); //store player1's number of cards before laying down draw cards
            p2_cards_b4_draw = player2.getNumCards(); //store player2's number of cards before laying down draw cards

            std::cout << "It is a tie...for this round!" << endl; //display tie result
            std::cout << "Each player drops three cards(face down) on the pile, then play one more card (face up)" << endl; //subsequent tie instructions
            std::cout << "----------------------------------------------" << endl; //formatting
            std::cout << endl; //formatting
            std::cout << "There are " << num_pile << " cards on the pile!" << endl; //display number of cards in the pile currently
            std::cout << endl; //formatting
            std::cout << "----------------------------------------------" << endl; //formatting

            //player1.print(); //prints player1's hand for debugging purposes
            //player2.print(); //prints player2's hand for debugging purposes

            if (player1.getNumCards() < 4 || player2.getNumCards() < 4) //if one player is out of cards end game
            {
                gameOver = true;
                break; //end game
            }
            if (player1.getNumCards() == 0 || player2.getNumCards() == 0) //if one player is out of cards end game
            {
                gameOver = true;
                break; //end game
            }
            if (gameOver) {
                break;  // exit the while (result == 0) loop too!
            }

            for (int i = 0; i < 3; i++) //repeat three times
            {
                if (player1.getNumCards() > 0) //double check player1 has enough cards
                {
                    if (player1.getNumCards() == 0 || player2.getNumCards() == 0) //if one player is out of cards end game
                    {
                        gameOver = true;
                        break; //end game
                    }
                    pile.push_back(player1.play_a_card()); //add player1's card to pile
                }
                if (player2.getNumCards() > 0) //double check player2 had enough cards
                {
                    if (player1.getNumCards() == 0 || player2.getNumCards() == 0) //if one player is out of cards end game
                    {
                        gameOver = true;
                        break; //end game
                    }
                    pile.push_back(player2.play_a_card()); //add player2's card to pile
                }
            }

            if (gameOver)
            {
                break;  // exit the while (result == 0) loop too!
            }
            if (num_pile >= BOTH_HANDS)
            {
                gameOver = true;
                break; //end game if the pile is full
            }

            std::cout << "Player1 has " << player1.getNumCards() << " cards in hand!" << endl; //display how many cards player1 has
            std::cout << "Player2 has " << player2.getNumCards() << " cards in hand!" << endl; //display how many cards player2 has
            std::cout << endl; //formatting

            // /* //start of comment out for testing
            //check for quit/continue input again
            std::cout << "\nDo you want to continue...for the next round? (N or n to quit)";
            string input;
            getline(cin, input);
            stringstream ss(input);
            //if quit input detected then exit the loop and end program
            if (input == "N" || input == "n")
            {
                break;
            }
            // */ //end of comment out for testing

            if (player1.getNumCards() == 0 || player2.getNumCards() == 0) //if one player is out of cards end game
            {
                gameOver = true;
                break; //end game
            }
            c1 = player1.play_a_card(); //play player1's card
            c2 = player2.play_a_card(); //play player2's card
            pile.push_back(c1); //add player1's card to pile
            pile.push_back(c2); //add player2's card to pile

            std::cout << "Player 1 plays: ";
            c1.print(); //display what card player1 played
            std::cout << endl; //formatting
            std::cout << "Player 2 plays: ";
            c2.print(); //display what card player2 played
            std::cout << endl; //formatting

            num_pile = (draw_cards_played * draws) + (norm_cards_played * (draws + 1)); //number of cards in the pile accounting for how many draws there have been
            std::cout << "----------------------------------------------" << endl; //formatting
            std::cout << endl; //formatting
            std::cout << "There are " << num_pile << " cards on the pile!" << endl; //display number of cards in the pile currently
            std::cout << endl; //formatting
            std::cout << "----------------------------------------------" << endl; //formatting

            tie_result = c1.compareTo(c2); //compare cards
            if (tie_result != 0) //if it is not a draw
            {
                if (tie_result == 1) //if player1 wins
                {
                    player1.addCards(pile); //add won cards to player1's hand
                    std::cout << "Player 1 wins...get all cards from the current round!" << endl; //display player1 win message
                    break; //exit while tied loop
                }
                if (tie_result == -1) //if player2 wins
                {
                    player2.addCards(pile); //add won cards to player1's hand
                    std::cout << "Player 2 wins...get all cards from the pile!" << endl; //display player2 win message
                    break; //exit while tied loop
                }
            }

        }

        if (result == 0) //if tied
        {
            if (tie_result == 0) //if still tied
            {
                gameOver = true;
                break; //end game
            }
            std::cout << "Player1 has " << player1.getNumCards() << " cards in hand!" << endl; //display how many cards player1 has
            std::cout << "Player2 has " << player2.getNumCards() << " cards in hand!" << endl; //display how many cards player2 has
        }

        if (result != 0) //if it is not a draw
        {
            if (result == 1) //if player1 wins
            {
                player1.addCards(pile); //add won cards to player1's hand
                std::cout << "Player 1 wins...get all cards from the current round!" << endl; //display player1 win message
            }
            if (result == -1) //if player2 wins
            {
                player2.addCards(pile); //add won cards to player1's hand
                std::cout << "Player 2 wins...get all cards from the pile!" << endl; //display player2 win message
            }
            std::cout << "Player1 has " << player1.getNumCards() << " cards in hand!" << endl; //display how many cards player1 has
            std::cout << "Player2 has " << player2.getNumCards() << " cards in hand!" << endl; //display how many cards player2 has
        }
        if (player1.getNumCards() == 0 || player2.getNumCards() == 0) //if one player is out of cards end game
        {
            break; //end game
        }
        if (round > MAX_ROUNDS)
        {
            std::cout << "\nGame has gone on too long and players are bored, game has ended." << endl;
            break; //end game if there is no winner after 100 hands have been played
        }
    }

    std::cout << "\nGame is over!" << endl; //display game over message

    if (player1.getNumCards() > player2.getNumCards()) //if player1 has more cards
    {
        std::cout << "Player 1 wins!" << endl; //display player1 win message
        if ((player1.getNumCards() + player2.getNumCards()) == BOTH_HANDS)
        {
            std::cout << "Player1 has " << player1.getNumCards() << " cards." << endl; //display how many cards player1 has
            std::cout << "Player2 has " << player2.getNumCards() << " cards." << endl; //display how many cards player2 has
        }
        else
        {
            p1_cards_b4_draw++;
            p2_cards_b4_draw++;
            std::cout << "Player1 has " << p1_cards_b4_draw << " cards." << endl; //display how many cards player1 has
            std::cout << "Player2 has " << p2_cards_b4_draw << " cards." << endl; //display how many cards player2 has
        }

    }
    else if (player1.getNumCards() < player2.getNumCards()) //if player2 has more cards
    {
        std::cout << "Player 2 wins!" << endl; //display player2 win message
        if ((player1.getNumCards() + player2.getNumCards()) == BOTH_HANDS)
        {
            std::cout << "Player1 has " << player1.getNumCards() << " cards." << endl; //display how many cards player1 has
            std::cout << "Player2 has " << player2.getNumCards() << " cards." << endl; //display how many cards player2 has
        }
        else
        {
            p1_cards_b4_draw++;
            p2_cards_b4_draw++;
            std::cout << "Player1 has " << p1_cards_b4_draw << " cards." << endl; //display how many cards player1 has
            std::cout << "Player2 has " << p2_cards_b4_draw << " cards." << endl; //display how many cards player2 has
        }
    }
    else
    {
        std::cout << "It is a tie game!" << endl; //display tie game message
        std::cout << "Player1 has " << p1_cards_b4_draw << " cards." << endl; //display how many cards player1 has
        std::cout << "Player2 has " << p2_cards_b4_draw << " cards." << endl; //display how many cards player2 has

    }

    return 0;
}
