#pragma once

#include <iostream>
#include <string>

void printUsage(const std::string& executable_name);
void resetStream(std::istream& input_stream);
int readStream(std::istream& input_stream, int low, int high);
int getUniformRandomNumber(int low, int high);