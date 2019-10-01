//
// Created by daniyal on 2019-09-30.
//
#include "insultgenerator_16mdm13.h"

using namespace std;

string InsultGenerator::genMapping(int i, int j, int k) {
    return "Thou " + col1[i] + " " + col2[j] + " " + col3[k] + "!";
}

void InsultGenerator::initialize() {
    // All the file I/O stuff
    string line, token;
    string delimiter = "\t";
    int pos;
    ifstream myfile;
    myfile.open("../InsultsSource.txt");
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
                //replace(line.begin(), line.end(), '\r', '\0');
                line.pop_back();
                col3.push_back(line);
            }
        }
        n = col1.size();
    }else{
        throw FileException("File had an error in opening");
    }
    myfile.close();
}

string InsultGenerator::talkToMe() {
    int i = rand() % 50;
    int j = rand() % 50;
    int k = rand() % 50;
    return genMapping(i, j, k);
}

vector<string> InsultGenerator::generate(int value) {
    if (value > 10000 || value < 0)
        throw NumInsultsOutOfBounds("Incorrect value passed in");
    vector<string> results;
    int i, j, k, jk, coord, prev = 0;
    for (int number = 1; number <= value; number++) {
        coord = (rand() % int(((pow(n,3) - prev) / (value - number + 1)))) + prev;
        prev = coord + 1;
        i = coord / int(pow(n,2));
        jk = coord % int(pow(n,2));
        j = jk / n;
        k = jk % n;
        results.push_back(genMapping(i, j, k));
    }
    return results;
};

void InsultGenerator::generateAndSave(string fileName, int value){
    vector<string> results;
    try{
        results = InsultGenerator::generate(value);
    } catch (NumInsultsOutOfBounds& e) {
        throw NumInsultsOutOfBounds(e.what());
    }
    ofstream output_file("./"+fileName);
    ostream_iterator<string> output_iterator(output_file, "\n");
    copy(results.begin(), results.end(), output_iterator);
}

FileException::FileException(const string &msg) : msg_(msg) {}

string FileException::what() const {
    return msg_;
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string &msg) : msg_(msg) {}

string NumInsultsOutOfBounds::what() const {
    return msg_;
}