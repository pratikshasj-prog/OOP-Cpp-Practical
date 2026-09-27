#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream inputFile("message.txt");

    if (!inputFile) {
        std::cerr << "Error: Could not open message.txt\n";
        return 1;
    }

    std::ofstream outputFile("copy.txt");

    if (!outputFile) {
        std::cerr << "Error: Could not create copy.txt\n";
        return 1;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        outputFile << line << '\n';
    }

    inputFile.close();
    outputFile.close();

    std::cout << "File copied successfully.\n";

    return 0;
}