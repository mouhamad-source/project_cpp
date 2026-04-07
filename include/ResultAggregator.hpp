#ifndef RESULTAGGREGATOR_HPP
#define RESULTAGGREGATOR_HPP

#include <vector>
#include <mutex>
#include <string>


struct FileReport {
    std::string filename;
    size_t lineCount;
    size_t wordCount;
    size_t charCount;
    std::string hash;
};

class ResultAggregator {
public:
    void add(const FileReport& report) {
        std::lock_guard<std::mutex> lock(mtx);
        reports.push_back(report);
    }

    std::vector<FileReport> getAll() {
        std::lock_guard<std::mutex> lock(mtx);
        return reports; 
    }

private:
    std::vector<FileReport> reports;
    std::mutex mtx;
};

#endif // RESULTAGGREGATOR_HPP
