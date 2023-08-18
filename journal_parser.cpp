#include "stuff.h"
#include <cinttypes>
#include <filesystem>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    // Refer to https://chat.openai.com/?model=text-davinci-002-render-sha to handle tgz files, that is next
    // TODO implement tgz open and search. Then I can archive all these bloody files.
    const std::filesystem::path journals{"/home/lemon/Documents/Notes/journal/home/"};
    for (auto const &dir_entry : std::filesystem::directory_iterator{journals})
    {
        /* std::cout << dir_entry.path() << std::endl; */
        String                  line;
        std::vector<Quick_Line> lines;
        auto                    s{getStream(dir_entry.path())};
        if (s.is_open())
        {
            while (std::getline(s, line))
            {
                if (line.find("server") != std::string::npos)
                {
                    lines.push_back(Quick_Line{line});
                }
            }
            s.close();
        }
        else {
            std::cout << "Unable to open file.";
        }
        for (auto &l : lines) {
            std::cout << l.print() << std::endl;
        }
    }
    return 0;
}
