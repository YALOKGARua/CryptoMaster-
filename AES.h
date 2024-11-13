#ifndef AES_H
#define AES_H

#include <string>

std::string AES_encrypt(const std::string& plaintext, const std::string& key);
std::string AES_decrypt(const std::string& ciphertext, const std::string& key);

#endif 