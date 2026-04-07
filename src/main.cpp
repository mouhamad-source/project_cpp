#include "ThreadPool.hpp"
#include "FileStats.hpp"
#include "FileHasher.hpp"
#include "ResultAggregator.hpp"
#include "Logger.hpp"

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        Logger::instance().log(LogLevel::ERROR, "No files provided");
        return 1;
    }

    ThreadPool pool(4);
    ResultAggregator aggregator;

    std::vector<std::future<void>> futures;

    for (int i = 1; i < argc; ++i) {
        std::string filename = argv[i];

        futures.push_back(pool.enqueue([filename, &aggregator]() {
            try {
                auto stats = FileStats::analyze(filename);
                auto hash = FileHasher::simpleHash(filename);

                FileReport report{
                    stats.filename,
                    stats.lineCount,
                    stats.wordCount,
                    stats.charCount,
                    hash
                };

                aggregator.add(report);
                Logger::instance().log(LogLevel::INFO, "Processed " + filename);
            } catch (const std::exception& e) {
                Logger::instance().log(LogLevel::ERROR,
                    "Failed to process " + filename + ": " + e.what());
            }
        }));
    }

    // Wait for all tasks
    for (auto& f : futures) {
        f.get();
    }

    // Print results
    auto results = aggregator.getAll();
    std::cout << "\n=== Final Report ===\n";
    for (const auto& r : results) {
        std::cout << "File: " << r.filename
                  << " | Lines: " << r.lineCount
                  << " | Words: " << r.wordCount
                  << " | Chars: " << r.charCount
                  << " | Hash: " << r.hash << "\n";
    }

    return 0;
}
