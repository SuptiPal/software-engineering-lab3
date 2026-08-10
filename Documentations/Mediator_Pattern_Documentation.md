# Lab 03 -- Mediator Pattern ## 1. Pattern Name **Mediator Pattern** ## 2. Category **Behavioral Design Pattern** ## 3. Intent The Mediator Pattern provides a central object that manages communication between other objects. Instead of objects communicating directly with each other, they communicate through the mediator. ## 4. Problem Statement Suppose two students need to communicate with each other. If one student directly depends on another student, the objects become tightly connected. As a system becomes larger, direct communication between many objects can make the program difficult to manage and maintain. The Mediator Pattern solves this problem by introducing a central mediator that handles the communication. ## 5. Motivation Consider two students, Rahim and Karim. Instead of Rahim directly sending a message to Karim, Rahim sends the message to a Mediator. The mediator checks who sent the message and forwards it to the other student. Therefore, the communication becomes: Rahim -> Mediator -> Karim This keeps the communication logic inside the mediator. ## 6. Pattern Structure (UML Class Diagram)
mermaid
classDiagram
    class Mediator {
        +Student* student1
        +Student* student2
        +send(string, Student*)
    }

    class Student {
        +string name
        +Mediator* mediator
        +Student(string, Mediator*)
        +send(string)
        +receive(string)
    }

    Student --> Mediator : sends through
    Mediator --> Student : forwards message
## 7. Class Responsibilities - **Mediator** -- Stores references to the two students and controls message delivery between them. - **Student** -- Represents a student. A student can send a message through the mediator and receive a message from the mediator. - **Client (****main****)** -- Creates the mediator and students, connects the students to the mediator, and starts the communication. ## 8. Code Implementation
cpp
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
### Output
text
Rahim sends: Hello Karim!
Karim receives: Hello Karim!
## 9. Execution Flow (Object Interaction) 1. A Mediator object is created. 2. Two Student objects, Rahim and Karim, are created. 3. Both students receive the address of the mediator. 4. The mediator stores references to Rahim and Karim as student1 and student2. 5. Rahim calls send("Hello Karim!"). 6. Rahim's send() method passes the message and the sender to the mediator. 7. Mediator::send() checks which student sent the message. 8. Since Rahim is student1, the mediator calls Karim's receive() method. 9. Karim receives and displays the message. ## 10. Advantages - Reduces direct communication between objects. - Keeps communication logic in one central place. - Makes the interaction between objects easier to understand. - Reduces dependency between the communicating students. - Makes communication easier to manage. ## 11. Limitations - Adds an extra mediator object to the program. - The mediator can become complicated if many objects and communication rules are added. - This simple implementation is designed for only two students. ## 12. Real-life Applications - Chat systems. - Online classroom communication. - Customer support systems. - Air traffic control systems. - Communication between GUI components. ## 13. Industry Examples - Messaging and chat applications. - Collaboration systems. - GUI applications where components communicate through a controller. - Notification and event-management systems. ## 14. Conclusion The Mediator Pattern provides a central object for communication between other objects. In this example, Rahim does not directly call Karim to send the message. Instead, Rahim sends the message to the Mediator, and the mediator forwards it to Karim. This reduces direct dependency between the students and keeps the communication logic in one place.