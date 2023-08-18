#include "stuff.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>


int main(int argc, char *argv[])
{
    // Check for the correct arguments passed
    if (argc < 2)
    {
        std::cout << "No argument provided. Provide one." << std::endl;
        return 0;
    };

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
