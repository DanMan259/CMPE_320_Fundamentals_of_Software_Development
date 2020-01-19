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

// Make the charArrayPtr type
typedef char* charArrayPtr;

// Make the JumblePuzzle type
class JumblePuzzle {
private:
    charArrayPtr* jumble; // The placeholder for the puzzle
    int size; // The size of the jumble matrix
    int rowPos; // Start the word at this row position
    int colPos; // Start the word at this col position
    char direction; // Start the word at this row position
public:
    JumblePuzzle(const JumblePuzzle& Puzzle);     // Copy Constructor
    JumblePuzzle(const string& toHide, const string& difficulty);     // Double Input Constructor
    ~JumblePuzzle(); // Deconstructor
    // Accessors
    charArrayPtr* getJumble() const;
    int getSize() const;
    int getRowPos() const;
    int getColPos() const;
    char getDirection() const;
    // Operators
    JumblePuzzle& operator=(const JumblePuzzle& assign);
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
