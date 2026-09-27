#include <fstream>
#include <iostream>

struct StudentRecord {
    int rollNumber;
    char name[30];
    double marks;
};

int main() {
    StudentRecord student = {
        101,
        "Amit",
        85.5
    };

    std::ofstream outputFile(
        "students.dat",
        std::ios::binary
    );

    if (!outputFile) {
        std::cerr << "Error: Could not create students.dat\n";
        return 1;
    }

    outputFile.write(
        reinterpret_cast<char*>(&student),
        sizeof(student)
    );

    outputFile.close();

    StudentRecord readStudent{};

    std::ifstream inputFile(
        "students.dat",
        std::ios::binary
    );

    if (!inputFile) {
        std::cerr << "Error: Could not open students.dat\n";
        return 1;
    }

    inputFile.read(
        reinterpret_cast<char*>(&readStudent),
        sizeof(readStudent)
    );

    inputFile.close();

    std::cout << "Roll Number: "
              << readStudent.rollNumber << '\n';

    std::cout << "Name: "
              << readStudent.name << '\n';

    std::cout << "Marks: "
              << readStudent.marks << '\n';

    return 0;
}