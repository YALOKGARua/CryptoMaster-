Here’s a simple `README.md` for your project in English:

```markdown
# CryptoMaster - AES Encryption and Decryption

CryptoMaster is a C++ project that demonstrates the use of AES (Advanced Encryption Standard) encryption and decryption for securely handling sensitive data. This project includes encryption/decryption functionality for both plain text and file contents using the OpenSSL library.

## Features

- AES-128 encryption and decryption using CBC mode.
- File encryption and decryption support.
- Simple command-line interface for testing encryption on strings and files.

## Requirements

- **C++ Compiler** (e.g., `g++` or `clang++`).
- **OpenSSL** library for cryptographic functions.

### Installation of OpenSSL:

#### On Linux:
```bash
sudo apt-get install libssl-dev
```

#### On Windows:
1. Download and install OpenSSL from [OpenSSL's website](https://www.openssl.org/).
2. Set up the environment variables to link the libraries.

## File Structure

```
/crypto_project
│
├── main.cpp            # Main program file for testing encryption/decryption
├── AES.h               # Header file for AES encryption/decryption functions
├── AES.cpp             # Implementation of AES encryption/decryption
├── crypto_utils.h      # Header file for file encryption utilities
└── crypto_utils.cpp    # Implementation of file encryption utilities
```

## Compilation

To compile the project, use the following command:

```bash
g++ main.cpp AES.cpp crypto_utils.cpp -o crypto_program -lssl -lcrypto
```

## Usage

1. **Run the Program:**
   After compiling the program, run the executable:

   ```bash
   ./crypto_program
   ```

2. **Encrypt a string**:
   The program will ask for a string to encrypt. Enter the string and the encryption key.

3. **Decrypt the string**:
   After encryption, the program will output the decrypted string to verify the result.

4. **Encrypt and Decrypt Files**:
   You can modify the program to encrypt and decrypt files using the provided `encryptFile` and `decryptFile` functions.

## Example

**Input:**

```plaintext
Enter plaintext: This is a secret message!
Enter key: 1234567890abcdef
```

**Output:**

```plaintext
Encrypted: 3a1f34b6a...
Decrypted: This is a secret message!
```

## Author

CryptoMaster was created by [YALOKGAR]. Feel free to contribute by submitting pull requests or opening issues.
```

This `README.md` includes an overview of the project, installation instructions, and how to compile and use it. You can adapt it as needed for your specific requirements.
