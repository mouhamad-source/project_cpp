#ifndef FILESTATS_HPP
#define FILESTATS_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

struct FileResult {
    std::string filename;
    size_t lineCount;
    size_t wordCount;
    size_t charCount;
};

class FileStats {
public:
    static FileResult analyze(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file: " + filename);
        }

        size_t lines = 0, words = 0, chars = 0;
        std::string line;

        while (std::getline(file, line)) {
            lines++;
            chars += line.size() + 1; // +1 for newline
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                words++;
            }
        }

        return FileResult{filename, lines, words, chars};
    }
};

#endif // FILESTATS_HPP
