#pragma once

#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <fstream>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <atomic>


bool checkFile(const std::filesystem::path filePath);
std::string getFileContent(const std::filesystem::path& filePath);
void modifyFileContent(const std::filesystem::path& filePath, std::string toWrite);

std::filesystem::path getPath();
bool isPathGood();

#endif