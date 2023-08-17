#ifndef STUFF_H
#define STUFF_H

#include <string>

class Quick_Line
{
  private:
    std::string line;

  public:
    // constructor
    explicit Quick_Line(const std::string s);
    // Print out the line - can probably do this differently
    std::string print();
    // Insert the line
    void        insert(const std::string x);
};

#endif
