#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string indexNumber;
    string name;
    string programme;

public:
    void registerStudent() {
        cout << "Enter Index Number: ";
        cin >> indexNumber;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Programme: ";
        getline(cin, programme);

        saveToFile();
    }

    void saveToFile() {
        ofstream file("students.txt", ios::app);
        file << indexNumber << "," << name << "," << programme << endl;
        file.close();
        cout << "Student registered successfully!\n";
    }

    static void viewStudents() {
        ifstream file("students.txt");
        string line;

        cout << "\n--- Registered Students ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }
};

int main() {
    int choice;

    do {
        cout << "\n--- Student Management ---\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Student s;
            s.registerStudent();
            break;
        }
        case 2:
            Student::viewStudents();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option!\n";
        }

    } while (choice != 3);

    return 0;
}
