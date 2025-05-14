Quantum Flip-Bit Encryption Simulator
Overview
This project simulates a quantum-inspired encryption technique using binary transformation and randomized bit-flipping logic. It's designed as part of the COP3003 coursework and mimics the behavior of quantum bit operations through classical means.

The core concept revolves around encoding messages as binary, applying randomized alpha-beta flip-bit operations, and using pseudorandom selection logic to simulate quantum unpredictability.

How It Works
Message Encoding:

A plaintext message (e.g., "this is an encrypted message") is converted into binary (0s and 1s), with each character mapped accordingly.

The result is stored in a binary file representing the encrypted content.

Flip-Bit Pair File:

A separate file contains 128 lines of "alpha-beta" pairs.

Each line has a sequence of flip instructions, such as 0, 1, 1, 0, ..., which determine how bits will be flipped during transformation.

Quantum-like Algorithm:

A pseudorandom number generator (seeded with srand) is used to simulate quantum randomness.

The modulo operator selects a random line (0–127) from the flip-bit file for each byte or bit group in the binary message.

Encryption Process:

The selected alpha-beta pair is applied to the message bits.

This transforms the bits according to predefined flip logic, yielding an encrypted output.

File Structure
main.cpp — Main program logic for file I/O, binary conversion, and quantum simulation.

flip_pairs.txt — Contains the 128 flip-bit alpha-beta pairs.

message.txt — Input message to be encrypted.

binary_output.bin — Binary-encoded message.

encrypted_output.bin — Encrypted binary after applying flip-bit transformation.

Compilation
Make sure you have a C++ compiler installed (supporting at least C++11):

bash
Copy
Edit
g++ -std=c++11 main.cpp -o quantum_encryptor
Running the Program
Once compiled, run the program:

bash
Copy
Edit
./quantum_encryptor
Make sure your message.txt and flip_pairs.txt are correctly formatted and located in the working directory.

