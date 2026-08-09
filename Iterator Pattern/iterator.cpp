#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Student class
class Student {
private:
    string name;

public:
    Student(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }
};


// Forward declaration
class StudentCollection;


// Iterator class
class StudentIterator {
private:
    StudentCollection* collection;
    int position;

public:
    StudentIterator(StudentCollection* collection);

    bool hasNext();

    Student next();
};


// Student Collection class
class StudentCollection {
private:
    vector<Student> students;

public:
    void addStudent(string name) {
        students.push_back(Student(name));
    }

    int size() {
        return students.size();
    }

    Student getStudent(int index) {
        return students[index];
    }

    StudentIterator createIterator() {
        return StudentIterator(this);
    }
};


// StudentIterator constructor
StudentIterator::StudentIterator(StudentCollection* collection) {
    this->collection = collection;
    position = 0;
}


// Check whether another student exists
bool StudentIterator::hasNext() {
    return position < collection->size();
}


// Return the next student
Student StudentIterator::next() {
    return collection->getStudent(position++);
}


// Client code
int main() {

    StudentCollection students;

    students.addStudent("Rahim");
    students.addStudent("Karim");
    students.addStudent("Sadia");

    StudentIterator iterator = students.createIterator();

    cout << "Student List:" << endl;

    while (iterator.hasNext()) {
        Student student = iterator.next();
        cout << student.getName() << endl;
    }

    return 0;
}
