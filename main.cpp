#include <iostream>
#include "operation.h"

int main() {
    std::string filename;

    std::cout << "Enter the filename to simulate ransomware attack (must be a text file): ";
    std::cin >> filename;

    // Create a backup of the original file
    backup_file(filename, "backup_" + filename);

    // Encrypt the original file
    encrypt_file(filename);

    // Uncomment to test decryption:
    // decrypt_file("encrypted_" + filename);

    // Uncomment to restore from the backup:
    // backup_file("backup_" + filename, filename);

    return 0;
}
