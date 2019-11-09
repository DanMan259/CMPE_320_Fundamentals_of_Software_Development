//
// Created by Daniyal Maniar on 2019-11-08.
// Netid: 16mdm13
// Student #: 20064993
//
#pragma once

#ifndef ASSIGNMENT4_JUMBLE_H
#define ASSIGNMENT4_JUMBLE_H

#include <string>

using namespace std;

typedef char* charArrayPtr;

class JumblePuzzle {
private:
    charArrayPtr* jumble;
    string toHide;
    string difficulty;
    int size;
    int rowPos;
    int colPos;
    char direction;
    void generatePuzzle();
public:
    JumblePuzzle(const JumblePuzzle& Puzzle);     // Copy Constructor
    JumblePuzzle(const string& toHide, const string& difficulty);     // Double Input Constructor
    charArrayPtr* getJumble() const;
    int getSize() const;
    int getRowPos() const;
    int getColPos() const;
    char getDirection() const;
    string getToHide() const;
    string getDifficulty() const;
};

// Class definition of FractionException Class
class BadJumbleException{
public:
    BadJumbleException (const string& msg);
    string what() const;
private:
    string msg_;
};

#endif //ASSIGNMENT4_JUMBLE_H
