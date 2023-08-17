#ifndef STUFF_H
#define STUFF_H

#include <string>

using String = std::string;

// This is container for the line of text after it has been extracted from the file.
class Quick_Line
{
  private:
    // The line
    std::string line;

  public:
    // This is the default constructor
    explicit Quick_Line(const std::string s);

    // Prints out the line - can probably do this differently
    std::string print();
    // Insert the line
    void        insert(const std::string x);
};

// Gets an ifstream from a file at path.
std::ifstream getStream(const String path);

#endif
