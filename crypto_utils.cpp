#include "crypto_utils.h"
#include <fstream>
#include <sstream>
#include "AES.h"

std::string encryptFile(const std::string& filename, const std::string& key) {
    std::ifstream inputFile(filename, std::ios::in | std::ios::binary);
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string fileContents = buffer.str();

    return AES_encrypt(fileContents, key);
}

std::string decryptFile(const std::string& filename, const std::string& key) {
    std::ifstream inputFile(filename, std::ios::in | std::ios::binary);
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string fileContents = buffer.str();

    return AES_decrypt(fileContents, key);
}