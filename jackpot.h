#ifndef JACKPOT_H_
#define JACKPOT_H_

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Bet {
    vector<int> numbers;
    string player;
public:
    Bet(vector<int> ns, string p);
    vector<int> getNumbers() const;
    string getPlayer() const;
};

//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
struct betHash
{
    // Hash function
    // TODO
	int operator() (const Bet& b) const {
        int valor = 0;
        for (int i : b.getNumbers()) {
            valor += i;
        }
        return valor;
	}

    // Equality function
    // TODO
	bool operator() (const Bet& b1, const Bet& b2) const {
        vector<int> nb1 = b1.getNumbers();
        vector<int> nb2 = b2.getNumbers();
        sort(nb1.begin(),nb1.end());
        sort(nb2.begin(),nb2.end());
        return ( ( nb1 == nb2 ) && ( b1.getPlayer() == b2.getPlayer() ) );
	}
};


typedef unordered_set<Bet, betHash, betHash> tabHBet;

class Jackpot
{
	tabHBet bets;
public:
	Jackpot();
	void addBet(const Bet& ap);
	unsigned betsInNumber(unsigned num) const;
	vector<string> drawnBets(vector<int> draw) const;
    unsigned getNumBets() const;
};

#endif 
