#ifndef FILEHASHER_HPP
#define FILEHASHER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

class FileHasher {
public:
    static std::string simpleHash(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file: " + filename);
        }

        // FNV-1a 64-bit parameters
        const uint64_t FNV_offset_basis = 1469598103934665603ULL;
        const uint64_t FNV_prime = 1099511628211ULL;

        uint64_t hash = FNV_offset_basis;
        char buffer[8192];

        while (file.good()) {
            file.read(buffer, sizeof(buffer));
            std::streamsize bytesRead = file.gcount();
            for (std::streamsize i = 0; i < bytesRead; ++i) {
                hash ^= static_cast<unsigned char>(buffer[i]);
                hash *= FNV_prime;
            }
        }

        std::ostringstream oss;
        oss << std::hex << std::setw(16) << std::setfill('0') << hash;
        return oss.str();
    }
};

#endif // FILEHASHER_HPP
