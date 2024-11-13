#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <string>

std::string encryptFile(const std::string& filename, const std::string& key);
std::string decryptFile(const std::string& filename, const std::string& key);

#endif