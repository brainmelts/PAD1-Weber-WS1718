#include <cstdlib>
#include <algorithm>
#include "Poker.h"

Poker::Poker() {
    for (unsigned int i = 0; i <= 3; i++) {
        for (unsigned int j = 0; j <= 12; j++) {
            deck[i * 13 + j] = Card((Suit)i, (Face)j);
        }
    }
}

void Poker::shuffle() {
    size_t randIndex;
    Card temp;

    for (size_t deckIndex = 0; deckIndex < DECK_SIZE; deckIndex++) {
        randIndex = rand() % 52;
        temp = Card(deck[deckIndex].getSuit(), deck[deckIndex].getFace());
        deck[deckIndex] = deck[randIndex];
        deck[randIndex] = temp;
    }
}

void Poker::deal() {
    for (unsigned int i = 0; i <= 6; i++) sevenStud[i] = deck[i];

    sort(sevenStud.begin(), sevenStud.end());
}

Hand Poker::identifyHand() {
    Face onePairCache1 = NONE, onePairCache2 = NONE, threeOAKCache = NONE;
    Hand bestHand;
    short unsigned int counter;
    array <short int, 4> suitCounter; // KARO = 0, HERZ = 1, PIK = 2, KREUZ = 3
    bool isHighCard = false, isOnePair = false, isTwoPair = false, isThreeOfAKind = false, isStraight = false, isFlush = false, isFullHouse = false, isFourOfAKind = false, isStraightFlush = false, isRoyalFlush = false;

    // HIGH_CARD
    isHighCard = true;

    // ONE_PAIR
    for (unsigned int i = 0; i <= 5; i++) {
        for (unsigned int j = i + 1; j <= 6; j++) {
            if (sevenStud[i].getFace() == sevenStud[j].getFace()) {
                isOnePair = true;
                if (onePairCache1 != NONE) onePairCache2 = sevenStud[j].getFace();
                else onePairCache1 = sevenStud[j].getFace();
            }
        }
    }

    // TWO_PAIR
    counter = 0;

    for (unsigned int i = 0; i <= 5; i++) {
        for (unsigned int j = i + 1; j <= 6; j++) {
            if (sevenStud[i].getFace() == sevenStud[j].getFace()) {
                counter++;
                break;
            }
        }
    }

    if (counter == 2) isTwoPair = true;;

    // THREE_OF_A_KIND
    for (unsigned int i = 0; i <= 4; i++) {
        for (unsigned int j = i + 1; j <= 5; j++) {
            for (unsigned int k = j + 1; k <= 6; k++) {
                if (sevenStud[i].getFace() == sevenStud[j].getFace() && sevenStud[j].getFace() == sevenStud[k].getFace()) {
                    isThreeOfAKind = true;
                    threeOAKCache = sevenStud[k].getFace();
                }
            }
        }
    }

    // STRAIGHT
    for (unsigned int i = 0; i <= 2; i++) {
        if (
            sevenStud[i + 0].getFace() == (sevenStud[i + 1].getFace() - 1) &&
            sevenStud[i + 1].getFace() == (sevenStud[i + 2].getFace() - 1) &&
            sevenStud[i + 2].getFace() == (sevenStud[i + 3].getFace() - 1) &&
            sevenStud[i + 3].getFace() == (sevenStud[i + 4].getFace() - 1)
            ) isStraight = true;
        else if (
            sevenStud[6 + 0].getFace() == ASS &&
            sevenStud[i + 0].getFace() == ZWEI &&
            sevenStud[i + 1].getFace() == DREI &&
            sevenStud[i + 2].getFace() == VIER &&
            sevenStud[i + 3].getFace() == FUENF
            ) isStraight = true;
    }

    // FLUSH
    for (unsigned int i = 0; i <= 3; i++) {
        suitCounter[i] = 0;
    }

    for (unsigned int i = 0; i <= 6; i++) {
        if (sevenStud[i].getSuit() == KARO) suitCounter[0]++;
        if (sevenStud[i].getSuit() == HERZ) suitCounter[1]++;
        if (sevenStud[i].getSuit() == PIK) suitCounter[2]++;
        if (sevenStud[i].getSuit() == KREUZ) suitCounter[3]++;
    }

    for (unsigned int i = 0; i <= 3; i++) if (suitCounter[i] == 5) isFlush = true;

    // FULL_HOUSE
    if (isOnePair == true && isThreeOfAKind == true && (onePairCache1 != threeOAKCache || onePairCache2 != threeOAKCache)
        ) isFullHouse = true;

    // FOUR_OF_A_KIND
    for (unsigned int i = 0; i <= 3; i++) {
        for (unsigned int j = i + 1; j <= 4; j++) {
            for (unsigned int k = j + 1; k <= 5; k++) {
                for (unsigned int l = k + 1; l <= 6; l++) {
                    if (sevenStud[i].getFace() == sevenStud[j].getFace() &&
                        sevenStud[j].getFace() == sevenStud[k].getFace() &&
                        sevenStud[k].getFace() == sevenStud[l].getFace())
                        isFourOfAKind = true;
                }
            }
        }
    }

    // STRAIGHT_FLUSH
    for (unsigned int i = 0; i <= 2; i++) {
        if (
            sevenStud[i + 0].getFace() == (sevenStud[i + 1].getFace() - 1) &&
            sevenStud[i + 1].getFace() == (sevenStud[i + 2].getFace() - 1) &&
            sevenStud[i + 2].getFace() == (sevenStud[i + 3].getFace() - 1) &&
            sevenStud[i + 3].getFace() == (sevenStud[i + 4].getFace() - 1) &&
            sevenStud[i + 0].getSuit() == sevenStud[i + 1].getSuit() &&
            sevenStud[i + 1].getSuit() == sevenStud[i + 2].getSuit() &&
            sevenStud[i + 2].getSuit() == sevenStud[i + 3].getSuit() &&
            sevenStud[i + 3].getSuit() == sevenStud[i + 4].getSuit()
            ) isStraightFlush = true;
        else if (
            sevenStud[6 + 0].getFace() == ASS &&
            sevenStud[i + 0].getFace() == ZWEI &&
            sevenStud[i + 1].getFace() == DREI &&
            sevenStud[i + 2].getFace() == VIER &&
            sevenStud[i + 3].getFace() == FUENF &&
            sevenStud[6 + 0].getSuit() == sevenStud[i + 0].getSuit() &&
            sevenStud[i + 0].getSuit() == sevenStud[i + 1].getSuit() &&
            sevenStud[i + 1].getSuit() == sevenStud[i + 2].getSuit() &&
            sevenStud[i + 2].getSuit() == sevenStud[i + 3].getSuit()
            ) isStraightFlush = true;
    }

    // ROYAL_FLUSH
    for (unsigned int i = 0; i <= 2; i++) {
        if (
            sevenStud[i + 0].getFace() == ZEHN &&
            sevenStud[i + 1].getFace() == BUBE &&
            sevenStud[i + 2].getFace() == DAME &&
            sevenStud[i + 3].getFace() == KOENIG &&
            sevenStud[i + 4].getFace() == ASS &&
            sevenStud[i + 0].getSuit() == sevenStud[i + 1].getSuit() &&
            sevenStud[i + 1].getSuit() == sevenStud[i + 2].getSuit() &&
            sevenStud[i + 2].getSuit() == sevenStud[i + 3].getSuit() &&
            sevenStud[i + 3].getSuit() == sevenStud[i + 4].getSuit()
            )  isRoyalFlush = true;
    }

    if (isHighCard) bestHand = HIGH_CARD;
    if (isOnePair) bestHand = ONE_PAIR;
    if (isTwoPair) bestHand = TWO_PAIR;
    if (isThreeOfAKind) bestHand = THREE_OF_A_KIND;
    if (isStraight) bestHand = STRAIGHT;
    if (isFlush) bestHand = FLUSH;
    if (isFullHouse) bestHand = FULL_HOUSE;
    if (isFourOfAKind) bestHand = FOUR_OF_A_KIND;
    if (isStraightFlush) bestHand = STRAIGHT_FLUSH;
    if (isRoyalFlush) bestHand = ROYAL_FLUSH;

    return bestHand;
}

string Poker::deckToString() const {
    string deckString;

    deckString += "Deck:\n";
    for (unsigned int i = 0; i <= 51; i++) {
        deckString += deck[i].toString() + ", ";
    }
    deckString += "\n\n";

    return deckString;
}

string Poker::sevenStudToString() const {
    string sevenStudString;

    sevenStudString += "SevenStud:\n";
    for (unsigned int i = 0; i <= 6; i++) {
        sevenStudString += sevenStud[i].toString() + ", ";
    }
    sevenStudString += "\n\n";

    return sevenStudString;
}

string Poker::handToString() {
    string handString;
    const array<string, 10> handAsString = { "High Card", "One Pair", "Two Pairs", "Three Of A Kind", "Straight", "Flush", " Full House", "Four Of A Kind", "Straight Flush", "Royal Flush" };

    handString += "Best Hand:\n";
    handString += handAsString[identifyHand()];
    
    return handString;
}