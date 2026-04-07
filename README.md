Multithreaded File Processor
📖 Overview
The Multithreaded File Processor is a C++17 project designed to demonstrate professional multithreading practices. It processes multiple files in parallel, computing statistics (line count, word count, character count) and generating a simple hash fingerprint for each file. Results are aggregated and logged in a thread-safe manner.

This project showcases:
Thread management with a custom ThreadPool.
File analysis with FileStats.
Lightweight hashing with FileHasher.
Safe result collection via ResultAggregator.
Centralized logging using Logger.

✨ Features:
Parallel file processing using a thread pool.
Line, word, and character counting.
Simple FNV-1a based hash fingerprint.
Thread-safe result aggregation.
Timestamped logging with INFO, WARNING, and ERROR levels.
Modular, header-only design for easy reuse.

🛠️ Build Instructions:
Requirements:
C++17 or later
CMake ≥ 3.10
Standard library only (no external dependencies)
Build:
git clone https://github.com/yourusername/MultithreadedFileProcessor.git
cd MultithreadedFileProcessor
mkdir build && cd build
cmake ..
make
Usage : 
Run the processor with a list of files : 
./file_processor file1.txt file2.txt file3.txt
example output : 
[2026-04-07 07:10:00] INFO: Processed file1.txt
[2026-04-07 07:10:00] INFO: Processed file2.txt
[2026-04-07 07:10:00] INFO: Processed file3.txt

=== Final Report ===
File: file1.txt | Lines: 10 | Words: 50 | Chars: 300 | Hash: 9f86d081884c7d65
File: file2.txt | Lines: 5  | Words: 20 | Chars: 120 | Hash: 5d41402abc4b2a76
File: file3.txt | Lines: 8  | Words: 35 | Chars: 200 | Hash: 7d793037a0760186
project structure : 
/MultithreadedFileProcessor
  ├── include/
  │   ├── ThreadPool.hpp
  │   ├── FileStats.hpp
  │   ├── FileHasher.hpp
  │   ├── ResultAggregator.hpp
  │   └── Logger.hpp
  ├── src/
  │   └── main.cpp
  ├── tests/
  │   └── basic_tests.cpp
  ├── README.md
  ├── LICENSE
  └── CMakeLists.txt
🧪 Testing
./file_processor tests/sample1.txt tests/sample2.txt

🤝 Contributing
Contributions are welcome!

Fork the repository.
Create a feature branch.
Submit a pull request with clear description.

📜 License
This project is licensed under the MIT License. See LICENSE for details.


