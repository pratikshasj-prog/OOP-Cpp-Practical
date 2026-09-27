// Program 7: Static Member
// Scenario: Count how many objects are created.

#include <iostream>
using namespace std;

class Student {
public:
    static int count;

    Student() {
        count++;
    }
};

int Student::count = 0;

int main() {
    Student s1, s2, s3;

    cout << Student::count;

    return 0;
}