#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student class
class Student {
public:
    string name;

    Student(string n) {
        name = n;
    }
};

// Student Collection
class StudentCollection {
public:
    vector<Student> students;

    void addStudent(string name) {
        students.push_back(Student(name));
    }
};

// Iterator
class StudentIterator {
private:
    StudentCollection* collection;
    int position;

public:
    StudentIterator(StudentCollection* c) {
        collection = c;
        position = 0;
    }

    bool hasNext() {
        return position < collection->students.size();
    }

    Student next() {
        return collection->students[position++];
    }
};

int main() {

    StudentCollection students;

    students.addStudent("Rahim");
    students.addStudent("Karim");
    students.addStudent("Sadia");

    StudentIterator iterator(&students);

    while (iterator.hasNext()) {
        Student student = iterator.next();
        cout << student.name << endl;
    }

    return 0;
}