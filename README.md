Quantum Flip-Bit Encryption Simulator

A quantum-inspired encryption tool built in C++ using randomized alpha-beta bit-flip logic.

---

Project Summary

This project is a simulation of quantum-style encryption. Inspired by the unpredictability of quantum computation, the program encrypts text by transforming it into binary and applying random bit-flip operations drawn from a predefined set of *alpha-beta* pairs.


## 🔍 How It Works

### 1. **Message Encoding**

* A plaintext message (e.g. `"this is an encrypted message"`) is read from a file.
* Each character is mapped into binary (`0` and `1`) and saved in a binary file.

### 2. **Alpha-Beta Flip Pairs**

* A second file contains 128 lines of *alpha-beta* pairs (e.g. `0 1 1 0 1 0 ...`).
* Each line represents a specific pattern of bit flips.

### 3. **Quantum-Like Transformation**

* A pseudorandom generator (`srand`) is used to simulate quantum unpredictability.
* A line is selected from the flip-bit file using:

  ```
  index = rand() % 128
  ```
* The selected flip pattern is applied to the message's binary bits to simulate a "quantum operation."

---

## 📁 File Structure

```bash
📦 cop3003bit
├── flip_pairs.txt         # 128 alpha-beta flip-bit lines
├── message.txt            # Plaintext message to encrypt
├── binary_output.bin      # Binary version of the input message
├── encrypted_output.bin   # Encrypted message using flip-bit logic
└── main.cpp               # Main encryption algorithm
```

---

## ⚙️ Getting Started

* C++11 or later
* g++ or any C++ compiler

### 🛠️ Compile the Program

```bash
g++ -std=c++11 main.cpp -o quantum_encryptor
```

// Run the Program

```bash
./quantum_encryptor
```

Ensure the following files are present in the same directory:

* `message.txt`
* `flip_pairs.txt`

---
**Process**:

1. Convert `"hello"` to binary.
2. Randomly pick a line from `flip_pairs.txt`.
3. Flip bits using the selected alpha-beta line.
4. Save result to `encrypted_output.bin`.

---

##  Key Concepts

| Concept          | Description                                        |
| ---------------- | -------------------------------------------------- |
| `alpha-beta`     | Pairs defining flip rules for each binary position |
| `rand()`         | Simulates the "quantum" randomness                 |
| `srand(time(0))` | Seeds RNG for pseudo-randomness                    |
| `% 128`          | Selects one of 128 flip-bit rules                  |


