# Collatz Cryptography Suite

This repository contains a C++ security application implementing encryption and decryption algorithms based on the Collatz Conjecture. The project applies number theory to password hashing and strength analysis, emphasizing modern programming paradigms and memory safety.

The primary project files and source code are located in the CollatzAssignment directory.

## Technical Specifications

### Implementation Details
The solution is built using Modern C++ with a focus on memory safety and functional design patterns:
- Memory Management: Utilises Smart Pointers to ensure a leak-free architecture.
- Abstraction: Employs Polymorphism to decouple the encryption logic from the analysis tools.
- Functional Programming: Uses Lambda functions for high-performance data transformations and brute-force iterations.
- Scalability: The brute-force analyser is optimised to handle 20,000+ entries.

### Cryptographic Logic
The encryption algorithm maps the hailstone sequence of the Collatz Conjecture to data transformations. The application leverages the non-linear path each seed value takes toward the 4-2-1 loop to generate unique hash states.



The core mathematical function used is:
- If n is even: n / 2
- If n is odd: 3n + 1

## File Structure
- CollatzAssignment/
  - main.cpp: Entry point for the cryptography suite and brute-force testing.
  - CollatzEncryptor.h / .cpp: Logic for sequence-based data transformation.
  - StrengthAnalyser.h / .cpp: Module for evaluating hash vulnerability and performance.
  - Utilities.h: Helper functions and lambda definitions for data processing.
- Documentation/: Technical overview and mathematical background.

## Controls
- W, A, S, D: Navigate menu options (if applicable in console UI).
- Input Seed: Provide a numerical value to begin the hailstone sequence generation.
- Analysis Mode: Run the brute-force module to test system scalability.

## Setup and Installation

### 1. Prerequisites
- A C++ compiler supporting C++17 or higher (such as GCC, Clang, or MSVC).

### 2. Installation Steps
1. Clone the repository:
   git clone https://github.com/Rohin-Gillgallon/CollatzCryptography

2. Navigate to the project folder:
   cd CollatzCryptography

3. Compile the suite:
   g++ -std=c++17 main.cpp -o collatz_suite

4. Run the application:
   ./collatz_suite

## Key Features
- High-performance hashing based on number theory.
- Robust validation for password strength and vulnerability.
- Decoupled architecture allowing for easy extension of cryptographic methods.

---
Author: Rohin Gillgallon
