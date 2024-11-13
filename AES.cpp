#include "AES.h"
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <iomanip>
#include <sstream>

std::string AES_encrypt(const std::string& plaintext, const std::string& key) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &encryptKey);

    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    int len = plaintext.size();
    int padded_len = (len / AES_BLOCK_SIZE + 1) * AES_BLOCK_SIZE;
    unsigned char* encrypted = new unsigned char[padded_len];

    AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(plaintext.c_str()), encrypted, len, &encryptKey, iv, AES_ENCRYPT);

    std::stringstream ss;
    for (int i = 0; i < padded_len; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)encrypted[i];
    }

    delete[] encrypted;
    return ss.str();
}

std::string AES_decrypt(const std::string& ciphertext, const std::string& key) {
    AES_KEY decryptKey;
    AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &decryptKey);

    int len = ciphertext.size() / 2;
    unsigned char* encrypted = new unsigned char[len];

    for (int i = 0; i < len; i++) {
        encrypted[i] = std::stoi(ciphertext.substr(i * 2, 2), nullptr, 16);
    }

    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    unsigned char* decrypted = new unsigned char[len];
    AES_cbc_encrypt(encrypted, decrypted, len, &decryptKey, iv, AES_DECRYPT);

    std::string decryptedText(reinterpret_cast<char*>(decrypted), len);
    delete[] encrypted;
    delete[] decrypted;

    return decryptedText;
}