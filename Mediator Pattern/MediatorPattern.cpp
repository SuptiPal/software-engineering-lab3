#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward declaration
class Student;

// Mediator interface
class Mediator {
public:
    virtual void sendMessage(string message, Student* sender) = 0;

    virtual ~Mediator() {}
};

// Student class
class Student {
private:
    string name;
    Mediator* mediator;

public:
    Student(string name, Mediator* mediator) {
        this->name = name;
        this->mediator = mediator;
    }

    void send(string message) {
        cout << name << " sends: " << message << endl;
        mediator->sendMessage(message, this);
    }

    void receive(string message) {
        cout << name << " receives: " << message << endl;
    }
};

// Concrete Mediator
class CourseMediator : public Mediator {
private:
    vector<Student*> students;

public:
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void sendMessage(string message, Student* sender) override {
        for (Student* student : students) {
            if (student != sender) {
                student->receive(message);
            }
        }
    }
};

// Client code
int main() {

    CourseMediator mediator;

    Student rahim("Rahim", &mediator);
    Student karim("Karim", &mediator);
    Student sadia("Sadia", &mediator);

    mediator.addStudent(&rahim);
    mediator.addStudent(&karim);
    mediator.addStudent(&sadia);

    rahim.send("Exam will start at 10 AM.");

    return 0;
}