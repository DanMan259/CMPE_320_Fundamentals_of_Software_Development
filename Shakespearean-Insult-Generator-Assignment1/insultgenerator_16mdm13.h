//
// Created by Daniyal Maniar on 2019-09-30.
// Netid: 16mdm13
// Student #: 20064993
//
#pragma once

#ifndef ASSIGNMENT1_INSULTGENERATOR_16MDM13_H
#define ASSIGNMENT1_INSULTGENERATOR_16MDM13_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <time.h>

using namespace std;

// This is the class definition for the InsultGenerator class
// All my comments for each function are located in the cpp implementation cifile
class InsultGenerator {
private:
    vector<string> col1, col2, col3;
    int n;
    string genMapping (const int i, const int j, const int k);
public:
    void initialize ();
    string talkToMe ();
    vector<string> generate (const int value);
    void generateAndSave(const string fileName, const int value);
};

// Class definition of FileException Class
class FileException{
public:
    FileException (const string& msg);
    string what() const;
private:
    string msg_;
};

// Class definition of NumInsultsOutOfBounds Class
class NumInsultsOutOfBounds {
public:
    NumInsultsOutOfBounds (const string& msg);
    string what() const;
private:
    string msg_;
};

#endif //ASSIGNMENT1_INSULTGENERATOR_16MDM13_H
