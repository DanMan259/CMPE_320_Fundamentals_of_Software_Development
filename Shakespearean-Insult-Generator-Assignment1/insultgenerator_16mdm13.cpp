//
// Created by Daniyal Maniar on 2019-09-30.
// Netid: 16mdm13
// Student #: 20064993
//
#include "insultgenerator_16mdm13.h"

using namespace std;

string InsultGenerator::genMapping(const int i, const int j, const int k) {
    // This generates a string based off 3 values representing different indexs
    return "Thou " + col1[i] + " " + col2[j] + " " + col3[k] + "!";
}

void InsultGenerator::initialize() {
    // All the file I/O stuff
    // This takes every line in the file and splits it based off tab spaces
    // The result of each line is saved onto three vectors col1, col2, col3
    string line, token;
    string delimiter = "\t";
    int pos;
    ifstream myfile;
    myfile.open("InsultsSource.txt");
    if (myfile.is_open()){
        while (!myfile.eof()) {
            getline(myfile, line);
            if (line.size()){
                pos = line.find(delimiter);
                token = line.substr(0, pos);
                col1.push_back(token);
                line.erase(0, pos + 1);
                pos = line.find(delimiter);
                token = line.substr(0, pos);
                col2.push_back(token);
                line.erase(0, pos + 1);
                line.pop_back();
                col3.push_back(line);
            }
        }
        n = col1.size();
    }else{
        // If file cannot be opened then throw error
        throw FileException("File had an error in opening");
    }
    myfile.close();
}

string InsultGenerator::talkToMe() {
    // This makes three random numbers to get a random combination string
    srand(time(NULL));
    return genMapping(rand() % 50, rand() % 50, rand() % 50);
}

vector<string> InsultGenerator::generate(const int value) {
    // If an incorrect value is passed in then throw an error
    if (value > 10000 || value < 0)
        throw NumInsultsOutOfBounds("Out of bounds number passed in");
    // Generate 50 random numbers that between 0 and n^3 (50x50x50), and they are always
    // are always in increasing order.
    // Once you generate a random number, map it to a string via a base 50 number system
    // For instance the if you map number 0 - 49 the coordinates will be col1 [0], col2 [0], col3 [0-49]
    // and the 50th number will map to col1 [0], col2 [1], col3 [0]
    vector<string> results;
    int i, j, k, jk, n2, coord, prev = 0;
    srand(time(NULL));
    for (int number = 1; number <= value; number++) {
        // This always finds a random number between previous generated
        // value and n^3/(number of values left to generate)
        coord = (rand() % (((n*n*n) - prev) / (value - number + 1))) + prev;
        prev = coord + 1;
        n2 = n*n;
        i = coord / n2;
        jk = coord % n2;
        j = jk / n;
        k = jk % n;
        // Once you get the i,j,k coordinates generate a unique string
        results.push_back(genMapping(i, j, k));
        // This keeps the values in alphabetical order since
        // the test file provides the words in alphabetical order
    }
    // Return the vector with all the values
    return results;
};

void InsultGenerator::generateAndSave(const string fileName, const int value){
    // This calls the generate function and it appends each index of the result to the file
    vector<string> results;
    try{
        results = InsultGenerator::generate(value);
    } catch (NumInsultsOutOfBounds& e) {
        throw NumInsultsOutOfBounds(e.what());
    }
    ofstream output_file(fileName);
    if (output_file.fail()){
        throw FileException("File had an error in opening");
    }
    ostream_iterator<string> output_iterator(output_file, "\n");
    copy(results.begin(), results.end(), output_iterator);
}

// FileException error class that prints out an error message that is passed in
FileException::FileException(const string &msg) : msg_(msg) {}

string FileException::what() const {
    return msg_;
}

// NumInsultsOutOfBounds error class that prints out an error message that is passed in
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string &msg) : msg_(msg) {}

string NumInsultsOutOfBounds::what() const {
    return msg_;
}