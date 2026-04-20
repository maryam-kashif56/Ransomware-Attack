#include <iostream>
#include <fstream>
#include "operation.h"

// Function to encrypt the file
void encrypt_file(const std::string &filename) {
    std::ifstream file_in(filename, std::ios::in | std::ios::binary);
    std::ofstream file_out("encrypted_" + filename, std::ios::out | std::ios::binary);

    if (!file_in || !file_out) {
        std::cerr << "Error: Could not open file(s)!" << std::endl;
        return;
    }

    char ch;
    while (file_in.get(ch)) {
        ch ^= 0xFF;  // Simple XOR encryption
        file_out.put(ch);
    }

    file_in.close();
    file_out.close();
    std::cout << "File encrypted successfully!" << std::endl;
}

// Function to decrypt the file
void decrypt_file(const std::string &filename) {
    std::ifstream file_in(filename, std::ios::in | std::ios::binary);
    std::ofstream file_out("decrypted_" + filename.substr(10), std::ios::out | std::ios::binary); // skip "encrypted_" prefix

    if (!file_in || !file_out) {
        std::cerr << "Error: Could not open file(s)!" << std::endl;
        return;
    }

    char ch;
    while (file_in.get(ch)) {
        ch ^= 0xFF;  // Same operation as in encryption
        file_out.put(ch);
    }

    file_in.close();
    file_out.close();
    std::cout << "File decrypted and restored successfully!" << std::endl;
}

// Function to create a backup of the original file
void backup_file(const std::string &original, const std::string &backup) {
    std::ifstream src(original, std::ios::binary);
    std::ofstream dest(backup, std::ios::binary);

    if (!src || !dest) {
        std::cerr << "Error: Could not open file(s) for backup!" << std::endl;
        return;
    }

    char ch;
    while (src.get(ch)) {
        dest.put(ch);
    }

    src.close();
    dest.close();
    std::cout << "Backup created successfully!" << std::endl;
}
