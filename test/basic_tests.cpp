#include "FileStats.hpp"
#include "FileHasher.hpp"
#include "ResultAggregator.hpp"
#include "Logger.hpp"

#include <gtest/gtest.h>
#include <fstream>

// Helper: create a temporary file with content
void createTempFile(const std::string& filename, const std::string& content) {
    std::ofstream out(filename);
    out << content;
    out.close();
}

// --- Tests ---

TEST(FileStatsTest, CountLinesWordsChars) {
    std::string filename = "temp_test.txt";
    createTempFile(filename, "Hello world\nThis is a test\n");

    FileResult result = FileStats::analyze(filename);

    EXPECT_EQ(result.lineCount, 2);
    EXPECT_EQ(result.wordCount, 5);
    EXPECT_EQ(result.charCount, 26); // includes newline chars
}

TEST(FileHasherTest, HashChangesWithContent) {
    std::string filename1 = "temp_hash1.txt";
    std::string filename2 = "temp_hash2.txt";

    createTempFile(filename1, "abc");
    createTempFile(filename2, "abcd");

    std::string hash1 = FileHasher::simpleHash(filename1);
    std::string hash2 = FileHasher::simpleHash(filename2);

    EXPECT_NE(hash1, hash2); // different content → different hash
}

TEST(ResultAggregatorTest, AddAndRetrieveReports) {
    ResultAggregator aggregator;
    FileReport r1{"file1.txt", 10, 50, 300, "hash1"};
    FileReport r2{"file2.txt", 5, 20, 120, "hash2"};

    aggregator.add(r1);
    aggregator.add(r2);

    auto results = aggregator.getAll();
    ASSERT_EQ(results.size(), 2);
    EXPECT_EQ(results[0].filename, "file1.txt");
    EXPECT_EQ(results[1].filename, "file2.txt");
}

TEST(LoggerTest, LogOutputsMessage) {
    // This test just ensures Logger compiles and runs.
    // Visual inspection of console output is needed.
    Logger::instance().log(LogLevel::INFO, "Test log message");
    SUCCEED(); // Always passes
}

// --- main for Google Test ---
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
