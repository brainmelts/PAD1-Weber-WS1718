#pragma once
#include <string>
#include <array>

using namespace std;

enum Suit { KARO = 0, HERZ = 1, PIK = 2, KREUZ = 3 };
enum Face { ZWEI = 0, DREI = 1, VIER = 2, FUENF = 3, SECHS = 4, SIEBEN = 5, ACHT = 6, NEUN = 7, ZEHN = 8, BUBE = 9, DAME = 10, KOENIG = 11, ASS = 12, NONE = 13 };
enum Hand { HIGH_CARD = 0, ONE_PAIR = 1, TWO_PAIR = 2, THREE_OF_A_KIND = 3, STRAIGHT = 4, FLUSH = 5, FULL_HOUSE = 6, FOUR_OF_A_KIND = 7, STRAIGHT_FLUSH = 8, ROYAL_FLUSH = 9 };

class Card {
public:
    Card();
    Card(Suit, Face);
    Suit getSuit() const;
    Face getFace() const;
    std::string toString() const;
    bool operator<(const Card&) const;
    bool operator==(const Card&) const;

private:
    Suit suit;
    Face face;
};