#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>

void encrypt_file(const std::string &filename);
void decrypt_file(const std::string &filename);
void backup_file(const std::string &original, const std::string &backup);

#endif // FILE_OPERATIONS_H
