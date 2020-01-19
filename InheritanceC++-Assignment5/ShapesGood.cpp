#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;

// Shape
Shape::Shape() : length(0), width(0), outlineColor("") {} // Empty Constructor
Shape::Shape(int len, int wid, string color) : length(len), width(wid), outlineColor(color) {} // Constructor
Shape::~Shape() {} // Destructor
// Accessors
int Shape::getLength() { return length; }
int Shape::getWidth() { return width; }
string Shape::getOutlineColor() const { return outlineColor; }
// Draw print statements
void Shape::drawColor() const { cout << "\nDrawing a " << getOutlineColor(); }
void Shape::draw() const { cout << "Not referring to a specific shape object" << endl; }

// Fill
Fillable::Fillable() : color("") {} // Empty Constructor
Fillable::Fillable(string fillColor) : color(fillColor) {} // Constructor
Fillable::~Fillable() {} // Destructor
string Fillable::getFillColor() const { return color; } // Accessor
void Fillable::getFillString() const { cout << "With " << getFillColor() << " fill. "; } // Draw print statement

// Text
Text::Text() : text("") {} // Empty Constructor
Text::Text(string fillText) : text(fillText) {} // Constructor
Text::~Text() {} // Destructor
string Text::getText() const { return text; } // Accessor
void Text::textString() const { cout << "Containing text: \"" << getText() << "\"."; } // Draw print statement

// Square
Square::Square() : Shape() {} // Empty Constructor
Square::Square(int len, int wid, string color) : Shape(len, wid, color) {} // Constructor
Square::~Square() {} // Destructor
// Draw print statements
void Square::draw() const{
    drawColor();
    cout << " square. ";
}

// Filled Square
FilledSquare::FilledSquare() : Square(), Fillable() {} // Empty Constructor
FilledSquare::FilledSquare(int len, int wid, string outlineCol, string fillCol) : Square(len, wid, outlineCol), Fillable(fillCol) {} // Constructor
FilledSquare::~FilledSquare() {} // Destructor
// Draw print statements
void FilledSquare::draw() const{
    Square::draw();
    getFillString();
}

// Filled Square with text
FilledTextSquare::FilledTextSquare() : FilledSquare(), Text("") {}  // Empty Constructor
FilledTextSquare::FilledTextSquare(int len, int wid, string outlineCol, string fillCol, string fillText) : FilledSquare(len, wid, outlineCol, fillCol), Text(fillText) {} // Constructor
FilledTextSquare::~FilledTextSquare() {} // Destructor
// Draw print statements
void FilledTextSquare::draw() const{
    FilledSquare::draw();
    textString();
}

// Circle
Circle::Circle() : Shape() {} // Empty Constructor
Circle::Circle(int len, int wid, string color) : Shape(len, wid, color) {} // Constructor
Circle::~Circle() {} // Destructor
// Draw print statements
void Circle::draw() const{
    drawColor();
    cout << " circle. ";
}

// Filled Circle
FilledCircle::FilledCircle() : Circle(), Fillable() {} // Empty Constructor
FilledCircle::FilledCircle(int len, int wid, string outlineCol, string fillCol) : Circle(len, wid, outlineCol), Fillable(fillCol) {} // Constructor
FilledCircle::~FilledCircle() {} // Destructor
// Draw print statements
void FilledCircle::draw() const{
    Circle::draw();
    getFillString();
}

// Arc
Arc::Arc() : Shape() {} // Empty Constructor
Arc::Arc(int len, int wid, string color) : Shape(len, wid, color) {} // Constructor
Arc::~Arc() {} // Destructor
// Draw print statements
void Arc::draw() const{
    drawColor();
    cout << " arc. ";
}