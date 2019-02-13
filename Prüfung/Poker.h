#pragma once
#include "Card.h"

const static size_t DECK_SIZE = 52;
const static size_t SEVEN_STUD_SIZE = 7;

class Poker {
public:
    Poker();
    void shuffle();
    void deal();
    Hand identifyHand();
    std::string deckToString() const;
    std::string sevenStudToString() const;
    std::string handToString();

private:
    array <Card, DECK_SIZE> deck;
    array <Card, SEVEN_STUD_SIZE> sevenStud;
};