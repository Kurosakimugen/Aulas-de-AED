#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}


//=============================================================================
// Exercise 1: Dictionary
//=============================================================================
//TODO
bool WordMean::operator< (const WordMean& wm2) const {
    if(word < wm2.word ) {
        return true;
    }
     return false;
}

//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
//TODO
void Dictionary::readFile(ifstream &f) {
    string line;
    string mean;
    while (!f.eof()) {
        getline(f, line);
        getline(f, mean);
        addWord(WordMean (line, mean));
    }
}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
//TODO
void Dictionary::print() const {
    for (WordMean wm : words) {
        cout << wm.getWord() << "\n";
        cout << wm.getMeaning() << "\n";
    }
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    string res = "word not found";
    for (WordMean total : words) {
        if (total.getWord() == w1) {
            res = total.getMeaning();
            return res;
        }
    }
    WordMean vazio = WordMean("", "");
    for (auto i = words.begin(); i != words.end();i++) {
        if (i->getWord() < w1) {
            previous = *i;
        }
        else {
            next = *i;
            break;
        }
    }
    return res;
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
//TODO
bool Dictionary::update(string w1, string m1) {
    for (auto total = words.begin(); total != words.end(); total++) {
        if (total->getWord() == w1) {
            //total->setMeaning(m1);
            //WordMean wm = WordMean(w1, m1);
            WordMean wm = *total;
            words.erase(total);
            wm.setMeaning(m1);
            addWord(wm);

            //cout << total.getMeaning() << " <- Significado atribuído para w1" <<"\n";
            return true;
        }
    }
    addWord(WordMean(w1,m1));
    return false;
}
