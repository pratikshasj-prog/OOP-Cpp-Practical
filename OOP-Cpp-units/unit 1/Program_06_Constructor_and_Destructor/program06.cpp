// Program 6: Constructor and Destructor
// Scenario: Show automatic object initialization and cleanup.

#include <iostream>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Constructor called" << endl;
    }

    ~Demo() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Demo d;

    return 0;
}