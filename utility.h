#pragma once

#include <iostream>
#include <string>

void printUsage(const std::string& executable_name);
void resetStdin();
int getUniformRandomNumber(int low, int high);