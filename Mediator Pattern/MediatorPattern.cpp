#include <iostream>
#include <string>
using namespace std;

class Student;

class Mediator {
public:
    Student* student1;
    Student* student2;

    void send(string message, Student* sender);
};

class Student {
public:
    string name;
    Mediator* mediator;

    Student(string n, Mediator* m) {
        name = n;
        mediator = m;
    }

    void send(string message) {
        cout << name << " sends: " << message << endl;
        mediator->send(message, this);
    }

    void receive(string message) {
        cout << name << " receives: " << message << endl;
    }
};

void Mediator::send(string message, Student* sender) {

    if (sender == student1)
        student2->receive(message);
    else
        student1->receive(message);
}

int main() {

    Mediator mediator;

    Student rahim("Rahim", &mediator);
    Student karim("Karim", &mediator);

    mediator.student1 = &rahim;
    mediator.student2 = &karim;

    rahim.send("Hello Karim!");

    return 0;
}