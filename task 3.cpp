#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Record {
public:
	virtual void input() = 0;
	virtual void display() const = 0;
	virtual void saveToFile(ofstream& outFile) const = 0;
	virtual ~Record() {}  

class StudentRecord : public Record {
private:
	string name;
	int rollNo;
	float marks;

public:
	void input() override {
		cout << "Enter student name: ";
		getline(cin, name);
		cout << "Enter roll number: ";
		cin >> rollNo;
		cout << "Enter marks: ";
		cin >> marks;
		cin.ignore();  

	}

	void display() const override {
		cout << "Student Name: " << name << endl;
		cout << "Roll Number: " << rollNo << endl;
		cout << "Marks: " << marks << endl;
	}

	void saveToFile(ofstream& outFile) const override {
		outFile << "StudentRecord\n";
		outFile << name << "\n" << rollNo << "\n" << marks << "\n";
	}
};

class EmployeeRecord : public Record {
private:
	string name;
	int id;
	float salary;

public:
	void input() override {
		cout << "Enter employee name: ";
		getline(cin, name);
		cout << "Enter employee ID: ";
		cin >> id;
		cout << "Enter salary: ";
		cin >> salary;
		cin.ignore();  
	}

	void display() const override {
		cout << "Employee Name: " << name << endl;
		cout << "Employee ID: " << id << endl;
		cout << "Salary: " << salary << endl;
	}

	void saveToFile(ofstream& outFile) const override {
		outFile << "EmployeeRecord\n";
		outFile << name << "\n" << id << "\n" << salary << "\n";
	}
};

int main() {
	Record* records[2];

	records[0] = new StudentRecord();
	records[0]->input();

	records[1] = new EmployeeRecord();
	records[1]->input();

	cout << "\nDisplaying Records:\n";
	for (int i = 0; i < 2; i++) {
		records[i]->display();
		cout << endl;
	}

	ofstream outFile("records.txt");
	if (!outFile) {
		cerr << "Error opening file for writing.\n";
		return 1;
	}
	for (int i = 0; i < 2; i++) {
		records[i]->saveToFile(outFile);
	}
	outFile.close();

	for (int i = 0; i < 2; i++) {
		delete records[i];
	}

	cout << "Data saved to records.txt" << endl;

	return 0;
}
