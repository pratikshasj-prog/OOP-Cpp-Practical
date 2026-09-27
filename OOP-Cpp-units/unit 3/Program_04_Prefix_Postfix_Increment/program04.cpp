#include <iostream>

class Counter {
private:
    int value;

public:
    explicit Counter(int initialValue = 0)
        : value(initialValue) {}

    Counter& operator++() {
        ++value;
        return *this;
    }

    Counter operator++(int) {
        Counter old = *this;
        ++value;
        return old;
    }

    void display() const {
        std::cout << value << '\n';
    }
};

int main() {
    Counter counter(5);

    std::cout << "After prefix increment: ";
    ++counter;
    counter.display();

    std::cout << "Value returned by postfix increment: ";
    Counter oldValue = counter++;
    oldValue.display();

    std::cout << "Counter after postfix increment: ";
    counter.display();

    return 0;
}