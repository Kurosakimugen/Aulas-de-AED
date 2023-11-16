#include "jackpot.h"


Bet::Bet(vector<int> ns, string p): numbers(ns), player(p) {}

vector<int> Bet::getNumbers() const {
    return numbers;
}

string Bet::getPlayer() const {
    return player;
}

Jackpot::Jackpot()  {}

unsigned Jackpot::getNumBets() const {
    return bets.size();
}


//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
// Subexercise 2.1: Add Bet
//=============================================================================
// TODO
void Jackpot::addBet(const Bet& b) {
    if (bets.find(b) == bets.end()) {
        bets.insert(b);
    }
}

//=============================================================================
// Subexercise 2.2: Bets in Number
//=============================================================================
// TODO
unsigned Jackpot::betsInNumber(unsigned num) const {
	unsigned count = 0;
    for (auto b : bets) {
        vector<int> nb = b.getNumbers();
        if (find(nb.begin(),nb.end(), num) != nb.end()) {
            count++;
        }
    }
	return count;
}

//=============================================================================
// Subexercise 2.3: Drawn Bets
//=============================================================================
// TODO
vector<string> Jackpot::drawnBets(vector<int> draw) const {
	vector<string> res;
    for (auto b : bets) {
        int contador = 0;
        for (auto i : draw) {
            vector<int> nb = b.getNumbers();
            if (find(nb.begin(),nb.end(), i) != nb.end()) {
                contador++;
            }
        }
        if (contador > 3) {
            res.push_back(b.getPlayer());
        }
    }
	return res;
}
