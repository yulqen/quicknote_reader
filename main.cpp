#include "stuff.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

using String = std::string;

std::ifstream getStream(const String path)
{
    std::ifstream f(path);
    return f;
}

// Adding member functions to Quick_Line
void        Quick_Line::insert(const std::string x) { line = x; };
std::string Quick_Line::print() { return line; };
Quick_Line::Quick_Line(const std::string s) { line = s; };

int main(int argc, char *argv[])
{
    String                  line;
    std::vector<Quick_Line> lines;
    auto                    s{getStream("/home/lemon/Documents/Notes/quicknote.md")};
    if (s.is_open())
    {
        while (std::getline(s, line))
        {
            /* std::cout << "link -> " + line << '\n'; */
            lines.push_back(Quick_Line{line});
        }
        s.close();
    }
    else
        std::cout << "Unable to open file";

    int size = lines.size();
    int which = std::stoi(argv[1]);
    std::cout << which << std::endl;
    if (which > size)
    {
        std::cout << "You are asking for a line that isn't there!" << std::endl;
        std::cout << "The maximum number you can ask for is " << size - 1 << std::endl;

        return 0;
    }
    else
    {
        std::cout << "There are " << size - 1 << " lines in this file" << std::endl;
        std::cout << "Here is " << which << std::endl;
        std::cout << lines[which].print() << std::endl;
        return 0;
    }
}
