#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string name;
    float grade;

    Student(string n, float g) {
        name = n;
        grade = g;
    }
};

class GradeManager {
private:
    vector<Student> students;

public:
    void addStudent(string name, float grade) {
        if (grade < 0 || grade > 100) {
            cout << "Invalid grade! Must be between 0 and 100.\n";
            return;
        }
        students.push_back(Student(name, grade));
        cout << "Student " << name << " with grade " << grade << " added.\n";
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        cout << "\nStudent Records:\n";
        cout << "-------------------\n";
        for (const auto& student : students) {
            cout << "Name: " << student.name << ", Grade: " << student.grade << "\n";
        }
        cout << "-------------------\n";
    }

    void calculateAverageGrade() {
        if (students.empty()) {
            cout << "No grades to calculate average.\n";
            return;
        }

        float total = 0;
        for (const auto& student : students) {
            total += student.grade;
        }

        float average = total / students.size();
        cout << "Average Grade: " << average << "\n";
    }
};

int main() {
    GradeManager manager;
    int choice;

    do {
        cout << "\nStudent Grade Manager\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Exit\n";
        cout << "Choose an option (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                float grade;
                cout << "Enter student's name: ";
                cin >> name;
                cout << "Enter student's grade: ";
                cin >> grade;
                manager.addStudent(name, grade);
                break;
            }
            case 2:
                manager.displayStudents();
                break;
            case 3:
                manager.calculateAverageGrade();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
