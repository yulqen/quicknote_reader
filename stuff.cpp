#include "stuff.h"
#include <iostream>
#include <fstream>
#include <string>

std::ifstream getStream(const std::string path)
{
    std::ifstream f(path);
    return f;
}

// Adding member functions to Quick_Line
Quick_Line::Quick_Line(const std::string s) { line = s; };
void        Quick_Line::insert(const std::string s) { line = s; };
std::string Quick_Line::print() { return line; };
