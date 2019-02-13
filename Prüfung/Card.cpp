#include "Card.h"

Card::Card() {}

Card::Card(Suit _suit, Face _face) {
    suit = _suit;
    face = _face;
}

Suit Card::getSuit() const { return suit; }

Face Card::getFace() const { return face; }

string Card::toString() const {
    const array<string, 4> suitAsString = { "Karo", "Herz", "Pik", "Kreuz" };
    const array<string, 13> faceAsString = { "Zwei", "Drei", "Vier", "Fuenf", "Sechs", "Sieben", "Acht", "Neun", "Zehn", "Bube", "Dame", "Koenig", "Ass" };

    return suitAsString[getSuit()] + " " + faceAsString[getFace()];
}

bool Card::operator<(const Card& _c) const { return face < _c.face; }
bool Card::operator==(const Card& _c) const { return face == _c.face; }