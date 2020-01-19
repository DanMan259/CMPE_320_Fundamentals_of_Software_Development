#pragma once

#include <string>
using namespace std;

// Shape Class that all the other shapes will inherit
class Shape {
public:
    Shape();
    Shape(int, int, string);
    virtual ~Shape();
    int getLength();
    int getWidth();
    string getOutlineColor() const;
    virtual void draw() const;
protected:
    void drawColor() const;
private:
    const int length, width;
    const string outlineColor;
};

// Fill Class that all the other fillable shapes will inherit
class Fillable {
public:
    Fillable();
    Fillable(string);
    ~Fillable();
    string getFillColor() const;
protected:
    void getFillString() const;
private:
    const string color;
};

// Text Class that all the other text shapes will inherit
class Text {
public:
    Text();
    Text(string);
    ~Text();
    string getText() const;
protected:
    void textString() const;
private:
    const string text;
};


// Square Class
class Square : public Shape {
public:
    Square();
    Square(int, int, string);
    ~Square();
    virtual void draw() const;
};

// Filled Square Class
class FilledSquare : public Square, Fillable {
public:
    FilledSquare();
    FilledSquare(int, int, string, string);
    ~FilledSquare();
    virtual void draw() const;
};

// Filled Square with text Class
class FilledTextSquare : public FilledSquare, Text {
public:
    FilledTextSquare();
    FilledTextSquare(int, int, string, string, string);
    ~FilledTextSquare();
    virtual void draw() const;
};

// Circle Class
class Circle : public Shape {
public:
    Circle();
    Circle(int, int, string);
    ~Circle();
    virtual void draw() const;
};

// Filled Circle Class
class FilledCircle : public Circle, Fillable {
public:
    FilledCircle();
    FilledCircle(int, int, string, string);
    ~FilledCircle();
    virtual void draw() const;
};

// Arc Class
class Arc : public Shape {
public:
    Arc();
    Arc(int, int, string);
    ~Arc();
    virtual void draw() const;
};