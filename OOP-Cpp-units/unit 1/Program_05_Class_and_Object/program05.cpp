// Program 5: Class and Object
// Scenario: Store student details using class and object.

#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void show() {
        cout << name << " " << age << endl;
    }
};

int main() {
    Student s1;

    s1.name = "Amit";
    s1.age = 20;

    s1.show();

    return 0;
}