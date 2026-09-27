#include <fstream>
#include <iostream>

struct StudentRecord {
    int rollNumber;
    char name[30];
    double marks;
};

int main() {
    StudentRecord students[3] = {
        {101, "Amit", 85},
        {102, "Neha", 91},
        {103, "Rahul", 78}
    };

    std::ofstream outputFile(
        "student_records.dat",
        std::ios::binary
    );

    if (!outputFile) {
        std::cerr << "Error: Could not create binary file.\n";
        return 1;
    }

    outputFile.write(
        reinterpret_cast<char*>(students),
        sizeof(students)
    );

    outputFile.close();

    int recordNumber;

    std::cout << "Enter record number to read (1 to 3): ";
    std::cin >> recordNumber;

    if (recordNumber < 1 || recordNumber > 3) {
        std::cout << "Invalid record number.\n";
        return 0;
    }

    std::ifstream inputFile(
        "student_records.dat",
        std::ios::binary
    );

    if (!inputFile) {
        std::cerr << "Error: Could not open binary file.\n";
        return 1;
    }

    StudentRecord selectedStudent{};

    std::streamoff offset =
        (recordNumber - 1) * sizeof(StudentRecord);

    inputFile.seekg(offset, std::ios::beg);

    inputFile.read(
        reinterpret_cast<char*>(&selectedStudent),
        sizeof(selectedStudent)
    );

    if (!inputFile) {
        std::cerr << "Error: Could not read selected record.\n";
        return 1;
    }

    std::cout << "Roll Number: "
              << selectedStudent.rollNumber << '\n';

    std::cout << "Name: "
              << selectedStudent.name << '\n';

    std::cout << "Marks: "
              << selectedStudent.marks << '\n';

    return 0;
}