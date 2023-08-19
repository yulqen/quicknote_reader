#include "stuff.h"
#include <archive.h>
#include <archive_entry.h>
#include <cinttypes>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <zlib.h>

int main(int argc, char *argv[])
{
    std::string       searchTerm{"madness"};
    const std::string archivePath = "/tmp/toss.tgz";

    struct archive       *a;
    struct archive_entry *entry;

    a = archive_read_new();
    archive_read_support_filter_gzip(a);
    archive_read_support_format_tar(a);
    int r = archive_read_open_filename(a, archivePath.c_str(), 10240); // Use appropriate buffer size
    if (r != ARCHIVE_OK)
    {
        std::cerr << "Failed to open archive: " << archivePath << std::endl;
        return 1;
    }

    std::vector<Quick_Line> lines;
    while (archive_read_next_header(a, &entry) == ARCHIVE_OK)
    {
        const char *filename = archive_entry_pathname(entry);
        if (filename)
        {
            // Perform any necessary checks here
            if (archive_entry_filetype(entry) == AE_IFREG)
            {                                   // Regular file
                const size_t bufferSize = 1024; // Adjust as needed
                char         buffer[bufferSize];

                std::string content = "";
                size_t      bytesRead;
                while ((bytesRead = archive_read_data(a, buffer, bufferSize)) > 0)
                {
                    content.append(buffer, bytesRead);
                }

                // Now you can search through the content for specific text
                if (content.find(searchTerm) != std::string::npos)
                {
                    String line;
                    {
                        std::istringstream ss{content};
                        while (std::getline(ss, line))
                        {
                            if (line.find(searchTerm) != std::string::npos)
                            {
                                lines.push_back(Quick_Line{line});
                            }
                        }
                        std::cout << "\"" << searchTerm << "\""
                                  << " Found in file: " << filename << std::endl;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }
    for (auto &l : lines)
    {
        std::cout << l.print() << std::endl;
    }
    archive_read_close(a);
    archive_read_free(a);
    return 0;
}

/* return 0; */
/* } */

/* auto getSearchedLine(const std::string filepath) */
/* { */
/*     // Refer to https://chat.openai.com/?model=text-davinci-002-render-sha to handle tgz files, that is next */
/*     // TODO implement tgz open and search. Then I can archive all these bloody files. */
/*     const std::filesystem::path journals{filepath}; */
/*     for (auto const &dir_entry : std::filesystem::directory_iterator{journals}) */
/*     { */
/*         /1* std::cout << dir_entry.path() << std::endl; *1/ */
/*         String                  line; */
/*         std::vector<Quick_Line> lines; */
/*         auto                    s{getStream(dir_entry.path())}; */
/*         if (s.is_open()) */
/*         { */
/*             while (std::getline(s, line)) */
/*             { */
/*                 if (line.find("Harvey") != std::string::npos) */
/*                 { */
/*                     lines.push_back(Quick_Line{line}); */
/*                 } */
/*             } */
/*             s.close(); */
/*         } */
/*         else */
/*         { */
/*             std::cout << "Unable to open file."; */
/*         } */
/*         for (auto &l : lines) */
/*         { */
/*             std::cout << l.print() << std::endl; */
/*         } */
/*     } */
/*     return 0; */
/* } */
