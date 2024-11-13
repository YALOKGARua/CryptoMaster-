#include <iostream>
#include <fstream>
#include "AES.h"
#include "crypto_utils.h"

int main() {
    std::string plaintext = "This is a secret message!";
    std::string key = "1234567890abcdef"; 

    std::string encrypted = AES_encrypt(plaintext, key);
    std::cout << "Encrypted: " << encrypted << std::endl;

    std::string decrypted = AES_decrypt(encrypted, key);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}