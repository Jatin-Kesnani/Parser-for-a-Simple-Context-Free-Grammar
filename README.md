# Parser for a Simple Context-Free Grammar

A C++ implementation of a parser that verifies whether input strings conform to a specified context-free grammar (CFG). The parser checks syntax validity and provides meaningful error messages for invalid structures.

## Features

- Validates strings against a defined CFG using Backus-Naur Form (BNF) notation
- Detects and reports syntax errors including:
  - Mismatched parentheses
  - Invalid operator placement
  - Illegal character sequences
  - Grammar violations
- Provides step-by-step derivation for valid inputs
- Handles 20+ valid input patterns (see examples below)

## Grammar Rules

The parser implements the following grammar:\n
E → E + T | T \n
T → T * F | F \n
F → ( E ) | a


## Valid Input Examples

1. `a`  
2. `(a)`  
3. `a+a`  
4. `a*a`  
5. `a*a+a`  
6. `((a))`  
7. `(a)*a`  
8. `a+(a)`  
9. `a+a*a`  
10. `(a+a)`  
... (up to 20 valid patterns)

## Usage

Clone the repository:
```bash
git clone https://github.com/Jatin-Kesnani/Parser-for-a-Simple-Context-Free-Grammar.git
```
