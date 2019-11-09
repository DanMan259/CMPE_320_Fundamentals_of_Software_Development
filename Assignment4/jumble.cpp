//
// Created by Daniyal Maniar on 2019-11-08.
// Netid: 16mdm13
// Student #: 20064993
//
#include "jumble.h"

JumblePuzzle::JumblePuzzle(const JumblePuzzle& Puzzle){
    this->toHide = Puzzle.getToHide();
    this->difficulty = Puzzle.getDifficulty();
    this->size = Puzzle.getSize();
    this->rowPos = Puzzle.getRowPos();
    this->colPos = Puzzle.getColPos();
    this->direction = Puzzle.getDirection();
    this->jumble = nullptr;
}

JumblePuzzle::JumblePuzzle(const string& toHide, const string& difficulty){
    if (toHide.length() <= 3)
        throw BadJumbleException("The length of the imputed string is too short");
    else if(toHide.length() >= 10)
        throw BadJumbleException("The length of the imputed string is too long");
    if (difficulty != "hard" && difficulty != "medium" && difficulty != "easy")
        throw BadJumbleException("Incorrect difficulty specified");
    this->toHide = toHide;
    this->difficulty = difficulty;
    this->size = ((difficulty == "easy") ? (2*toHide.length()) : ((difficulty == "medium") ? (3*toHide.length()) : (4*toHide.length())));

    this->rowPos = 0;
    this->colPos = 0;
    this->direction = 'u';
    this->jumble = nullptr;
    //generatePuzzle();
}

void JumblePuzzle::generatePuzzle(){
    this->rowPos = 0;
    this->colPos = 0;
    this->direction = 'u';
    this->jumble = nullptr;
}

charArrayPtr * JumblePuzzle::getJumble() const { return jumble; }
int JumblePuzzle::getSize() const { return size; }
int JumblePuzzle::getRowPos() const { return rowPos; }
int JumblePuzzle::getColPos() const { return colPos; }
char JumblePuzzle::getDirection() const { return direction; }
string JumblePuzzle::getToHide() const { return toHide; }
string JumblePuzzle::getDifficulty() const { return difficulty; }
// BadJumbleException error class that prints out an error message that is passed in
BadJumbleException::BadJumbleException(const string &msg) : msg_(msg) {}

string BadJumbleException::what() const {
    return msg_;
}