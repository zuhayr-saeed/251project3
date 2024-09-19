#include "shape.h"
#include <string>

using namespace std;

// Default constructor initializing shape with default position
Shape::Shape() {
    x = 0;
    y = 0;
}

// Parameterized constructor for shape with specified position
Shape::Shape(int x, int y) {
    this->x = x;
    this->y = y;
}

// Destructor for Shape
Shape::~Shape() {
    // No dynamic memory allocation, so empty destructor
}

// Copy method to duplicate the shape
Shape* Shape::copy() {
   return new Shape(x, y);
}

// Getter for x-coordinate
int Shape::getX() const {
    return x;
}

// Getter for y-coordinate
int Shape::getY() const {
    return y;
}

// Setter for x-coordinate
void Shape::setX(int x) {
    this->x = x;
}

// Setter for y-coordinate
void Shape::setY(int y) {
    this->y = y;
}

// String representation of shape
string Shape::as_string() const {
    return "It's a Shape at x: " + to_string(x) + ", y: " + to_string(y);
}

// Circle class constructors and methods
Circle::Circle() { 
    radius = 0; // Default radius
}

Circle::Circle(int r) { 
    radius = r; // Circle with specified radius
}

Circle::Circle(int x, int y, int r) : Shape(x, y) {
    radius = r; // Circle with specified position and radius
}

// Destructor for Circle
Circle::~Circle(){
    // Empty destructor as no dynamic memory is used
}

// Copy method for Circle
Circle* Circle::copy() {
    return new Circle(x, y, radius);
}

// Getter for Circle radius
int Circle::getRadius() const { 
    return radius;
}

// Setter for Circle radius
void Circle::setRadius(int r) { 
    radius = r;
}

// String representation of Circle
string Circle::as_string() const {
    return "It's a Circle at x: " + to_string(x) + ", y: " + to_string(y) + ", radius: " + to_string(radius);
}

// Rect class constructors and methods
Rect::Rect() {
    width = 0; // Default width
    height = 0; // Default height
}

Rect::Rect(int w, int h) { 
    width = w; // Rectangle with specified width and height
    height = h;
}

Rect::Rect(int x, int y, int w, int h) : Shape(x, y) {
    width = w; // Rectangle with specified position, width, and height
    height = h;
}

// Destructor for Rect
Rect::~Rect() {
    // Empty destructor as no dynamic memory is used
}

// Copy method for Rect
Rect* Rect::copy() {
    return new Rect(x, y, width, height);
}

// Getter for Rectangle width
int Rect::getWidth() const {
    return width;
}

// Getter for Rectangle height
int Rect::getHeight() const { 
    return height;
}

// Setter for Rectangle width
void Rect::setWidth(int w) { 
    width = w;
}

// Setter for Rectangle height
void Rect::setHeight(int h) { 
    height = h;
}

// String representation of Rectangle
string Rect::as_string() const {
    return "It's a Rectangle at x: " + to_string(x) + ", y: " + to_string(y) + " with width: " + to_string(width) + " and height: " + to_string(height);
}

// RightTriangle class constructors and methods
RightTriangle::RightTriangle() { 
    base = 0; // Default base
    height = 0; // Default height
}

RightTriangle::RightTriangle(int b, int h) { 
    base = b; // RightTriangle with specified base and height
    height = h;
}

RightTriangle::RightTriangle(int x, int y, int b, int h) : Shape(x, y) {
    base = b; // RightTriangle with specified position, base, and height
    height = h;
}

// Destructor for RightTriangle
RightTriangle::~RightTriangle() {
    // Empty destructor as no dynamic memory is used
}

// Copy method for RightTriangle
RightTriangle* RightTriangle::copy() {
    return new RightTriangle(x, y, base, height);
}

// Getter for RightTriangle base
int RightTriangle::getBase() const { 
    return base;
}

// Getter for RightTriangle height
int RightTriangle::getHeight() const { 
    return height;
}

// Setter for RightTrianglebase
void RightTriangle::setBase(int b) { 
    base = b; // Set a new base for the triangle
}

// Setter for RightTriangle height
void RightTriangle::setHeight(int h) { 
    height = h; // Set a new height for the triangle
}

// String representation of RightTriangle
string RightTriangle::as_string() const { 
    return "It's a Right Triangle at x: " + to_string(x) + ", y: " + to_string(y) + " with base: " + to_string(base) + " and height: " + to_string(height);
}

