//
// Created by Daniyal Maniar on 2019-11-08.
// Netid: 16mdm13
// Student #: 20064993
//
#include "jumble.h"

JumblePuzzle::JumblePuzzle(const JumblePuzzle& Puzzle){
    // Copy constructor
    // Copy all the values to the new object
    this->size = Puzzle.getSize();
    this->rowPos = Puzzle.getRowPos();
    this->colPos = Puzzle.getColPos();
    this->direction = Puzzle.getDirection();
    // Copy the contents of the array
    this->jumble = new charArrayPtr[this->size];
    for (int i = 0; i < this->size ; i++){
        this->jumble[i] = new char[this->size];
        for (int j = 0 ;  j < this->size ; j++) { this->jumble[i][j] = Puzzle.jumble[i][j]; }
    }
}

JumblePuzzle::JumblePuzzle(const string& toHide, const string& difficulty){
    // Check if the inputs are correct
    if (toHide.length() < 3)
        throw BadJumbleException("The length of the imputed string is too short");
    else if(toHide.length() > 10)
        throw BadJumbleException("The length of the imputed string is too long");
    if (difficulty != "hard" && difficulty != "medium" && difficulty != "easy")
        throw BadJumbleException("Incorrect difficulty specified");
    // Check if the input string is correct
    for (char letter : toHide){
        if (letter > 'z') {
            throw BadJumbleException("Incorrect input string");
        } else if(letter < 'a') {
            if (letter < 'A' || letter > 'Z') {
                throw BadJumbleException("Incorrect input string");
            }
        }
    }
    // Make sure they are random each time
    srand(time(NULL));
    // Assign the size of the matrix
    this->size = ((difficulty == "easy") ? (2*toHide.length()) : ((difficulty == "medium") ? (3*toHide.length()) : (4*toHide.length())));
    // Make a the matrix of random letters
    this->jumble = new charArrayPtr[this->size];
    for (int i = 0; i < this->size; i++){
        this->jumble[i] = new char[this->size];
        for (int j = 0; j < this->size; j++){
            this->jumble[i][j] = 'a' + rand()%26;
        }
    }
    // Assign the direction
    int dirNum = rand() % 4;
    this->direction =  ((dirNum == 0) ? 'n' : ((dirNum == 1) ? 's' : ((dirNum == 2) ? 'e' : 'w')));
    // Assign the starting location of the word
    if (this->direction == 'n') { // North
        this->rowPos = toHide.length() + rand() % (this->size-toHide.length());
        this->colPos = rand() % this->size;
    } else if (this->direction == 's') { // South
        this->rowPos = rand() % (this->size-toHide.length());
        this->colPos = rand() % this->size;
    } else if (this->direction == 'e') { // East
        this->rowPos = rand() % this->size;
        this->colPos = rand() % (this->size-toHide.length());
    } else if (this->direction == 'w') { // West
        this->rowPos = rand() % this->size;
        this->colPos = toHide.length() + rand() % (this->size-toHide.length());
    }
    int row = rowPos;
    int col = colPos;
    // Put the word to hid to the matrix
    for(char letter : toHide){
        this->jumble[((this->direction == 'n') ? row-- : ((this->direction == 's') ?  row++ : row))][((this->direction == 'w') ? col-- : ((this->direction == 'e') ?  col++ : col))] = tolower(letter);
    }
}

JumblePuzzle::~JumblePuzzle(){
    // Delete the matrix
    for (int i = 0; i < this->size; i++){
        delete[] this->jumble[i];
    }
    delete[] this->jumble;
    // Assign null to each property
    this->jumble = nullptr;
    this->size = NULL;
    this->rowPos = NULL;
    this->colPos = NULL;
    this->direction = NULL;
}

// Accessors
charArrayPtr * JumblePuzzle::getJumble() const { return jumble; }
int JumblePuzzle::getSize() const { return size; }
int JumblePuzzle::getRowPos() const { return rowPos; }
int JumblePuzzle::getColPos() const { return colPos; }
char JumblePuzzle::getDirection() const { return direction; }

// Equals operator
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& assign){
    // If the object is not the same one
    if(this != &assign){
        // Reset the object
        delete this;
        // Assign all the properties
        this->rowPos = assign.getRowPos();
        this->colPos = assign.getColPos();
        this->direction = assign.getDirection();
        this->size = assign.getSize();
        this->jumble = new charArrayPtr[this->size];
        for(int row = 0; row < this->size; row++){
            this->jumble[row] = new char[this->size];
            for(int col = 0; col < this->size; col++){
                this->jumble[row][col] = assign.jumble[row][col];
            }
        }
    }
    return *this;
}
// BadJumbleException error class that prints out an error message that is passed in
BadJumbleException::BadJumbleException(const string &msg) : msg_(msg) {}

string BadJumbleException::what() const {
    return msg_;
}