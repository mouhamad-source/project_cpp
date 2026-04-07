\# Contributing to Multithreaded File Processor



Thank you for your interest in contributing! We welcome improvements, bug fixes, and new ideas.  

This document outlines the process and best practices for contributing to the project.



\---



\## 🛠️ How to Contribute



1\. \*\*Fork the repository\*\*  

&#x20;  Create your own copy of the project under your GitHub account.



2\. \*\*Create a branch\*\*  

&#x20;  Use a descriptive branch name for your changes:  



3\. \*\*Make changes\*\*  

\- Follow the existing coding style (C++17, header-only modules where possible).

\- Write clear, modular, and well-documented code.

\- Add unit tests for new functionality (Google Test framework).



4\. \*\*Run tests locally\*\*  

Ensure all tests pass before submitting:



5\. \*\*Commit changes\*\*  

Write meaningful commit messages:



6\. \*\*Push your branch\*\*  





7\. \*\*Open a Pull Request (PR)\*\*  

\- Provide a clear description of your changes.

\- Reference related issues if applicable.

\- Ensure CI checks pass (GitHub Actions will run automatically).



\---



\## 📐 Coding Guidelines

\- Use \*\*C++17\*\* standard.

\- Prefer \*\*header-only utilities\*\* for modularity.

\- Follow RAII principles for resource management.

\- Ensure thread safety when dealing with shared data.

\- Write clean, readable code with comments where necessary.



\---



\## 🧪 Testing

\- All new features must include unit tests.

\- Use \*\*Google Test\*\* (`gtest`) framework.

\- Run `ctest` to verify correctness before submitting.



\---



\## 📜 License

By contributing, you agree that your contributions will be licensed under the \*\*MIT License\*\* of this project.



\---



\## 🤝 Community Standards

\- Be respectful and constructive in discussions.

\- Provide context when reporting issues or suggesting changes.

\- Collaborate openly — we value learning and improvement.





