// PAD1 Weber WS 17/18
// Poker Statistiken
#include <iostream>
#include "Poker.h"
#include "ctime"

int main() {
    array<unsigned int, 10> counter = { 0 };
    srand(static_cast<unsigned int>(time(nullptr)));
    int gameAmount = 1000000;

    for (unsigned int i = 1; i <= gameAmount; i++) {
        Poker spiel;
        spiel.shuffle();
        spiel.deal();

             if (spiel.identifyHand() == HIGH_CARD) counter[0]++;
        else if (spiel.identifyHand() == ONE_PAIR) counter[1]++;
        else if (spiel.identifyHand() == TWO_PAIR) counter[2]++;
        else if (spiel.identifyHand() == THREE_OF_A_KIND) counter[3]++;
        else if (spiel.identifyHand() == STRAIGHT) counter[4]++;
        else if (spiel.identifyHand() == FLUSH) counter[5]++;
        else if (spiel.identifyHand() == FULL_HOUSE) counter[6]++;
        else if (spiel.identifyHand() == FOUR_OF_A_KIND) counter[7]++;
        else if (spiel.identifyHand() == STRAIGHT_FLUSH) counter[8]++;
        else if (spiel.identifyHand() == ROYAL_FLUSH) counter[9]++;
    }

    cout << "Beste Karte\t" << "Anzahl" << "\t" << "Warscheinlichkeit" << "\n"
        << "High Card"      << "\t" << counter[0] << "\t" << (float)counter[0] / gameAmount * 100 << "%\n"
        << "One Pair"       << "\t" << counter[1] << "\t" << (float)counter[1] / gameAmount * 100 << "%\n"
        << "Two Pairs"      << "\t" << counter[2] << "\t" << (float)counter[2] / gameAmount * 100 << "%\n"
        << "Three Of A Kind"<< "\t" << counter[3] << "\t" << (float)counter[3] / gameAmount * 100 << "%\n"
        << "Straight"       << "\t" << counter[4] << "\t" << (float)counter[4] / gameAmount * 100 << "%\n"
        << "Flush\t"        << "\t" << counter[5] << "\t" << (float)counter[5] / gameAmount * 100 << "%\n"
        << "Full House"     << "\t" << counter[6] << "\t" << (float)counter[6] / gameAmount * 100 << "%\n"
        << "Four Of A Kind" << "\t" << counter[7] << "\t" << (float)counter[7] / gameAmount * 100 << "%\n"
        << "Straight Flush" << "\t" << counter[8] << "\t" << (float)counter[8] / gameAmount * 100 << "%\n"
        << "Royal Flush"    << "\t" << counter[9] << "\t" << (float)counter[9] / gameAmount * 100 << "%\n";
}