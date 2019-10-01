//
// Created by daniyal on 2019-09-30.
//
#pragma once

#ifndef ASSIGNMENT1_INSULTGENERATOR_16MDM13_H
#define ASSIGNMENT1_INSULTGENERATOR_16MDM13_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class InsultGenerator {
private:
    vector<string> col1, col2, col3;
    int n;
    string genMapping (int i, int j, int k);
public:
    void initialize ();
    string talkToMe ();
    vector<string> generate (int value);
    void generateAndSave(string fileName, int value);
};

class FileException{
public:
    FileException (const string& msg);
    string what() const;
private:
    string msg_;
};

class NumInsultsOutOfBounds {
public:
    NumInsultsOutOfBounds (const string& msg);
    string what() const;
private:
    string msg_;
};

#endif //ASSIGNMENT1_INSULTGENERATOR_16MDM13_H
