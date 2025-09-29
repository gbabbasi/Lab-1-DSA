// task_1 (1)
#include <iostream>
#include <cmath>      
using namespace std;

class Shape {
protected:
	string name;

public:	virtual void input() = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual void display() = 0;

	virtual ~Shape() {}
};
class Circle : public Shape {
private:
	double radius;

public:
	void input() override {
		cout << "\nEnter radius of Circle: ";
		cin >> radius;
		name = "Circle";
	}

	double area() override {
		return M_PI * radius * radius;
	}

	double perimeter() override {
		return 2 * M_PI * radius;
	}

	void display() override {
		cout << "\nShape: " << name << endl;
		cout << "Radius: " << radius << endl;
		cout << "Area: " << area() << endl;
		cout << "Perimeter: " << perimeter() << endl;
	}
};

class Rectangle : public Shape {
private:
	double length, width;

public:
	void input() override {
		cout << "\nEnter length and width of Rectangle: ";
		cin >> length >> width;
		name = "Rectangle";
	}

	double area() override {
		return length * width;
	}

	double perimeter() override {
		return 2 * (length + width);
	}

	void display() override {
		cout << "\nShape: " << name << endl;
		cout << "Length: " << length << ", Width: " << width << endl;
		cout << "Area: " << area() << endl;
		cout << "Perimeter: " << perimeter() << endl;
	}
};

class Triangle : public Shape {
private:
	double a, b, c;

public:
	void input() override {
		cout << "\nEnter the sides of the Triangle (a, b, c): ";
		cin >> a >> b >> c;
		name = "Triangle";
	}

	double area() override {
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c)); 
	}

	double perimeter() override {
		return a + b + c;
	}

	void display() override {
		cout << "\nShape: " << name << endl;
		cout << "Sides: a=" << a << ", b=" << b << ", c=" << c << endl;
		cout << "Area: " << area() << endl;
		cout << "Perimeter: " << perimeter() << endl;
	}
};

int main() {
	Shape* shapePtr;

	shapePtr = new Circle();
	shapePtr->input();
	shapePtr->display();
	delete shapePtr;

	shapePtr = new Rectangle();
	shapePtr->input();
	shapePtr->display();
	delete shapePtr;

	shapePtr = new Triangle();
	shapePtr->input();
	shapePtr->display();
	delete shapePtr;

	return 0;
}

//task-1(2)


class BankAccount {
protected:
	string name;

public:	virtual void input() = 0;
		virtual double deposit() = 0;
		virtual double withdraw() = 0;
		virtual void display() = 0;

		virtual ~BankAccount() {}
};
class SavingsAccount : public BankAccount {
private:
	double balance;
	double account_number;
	double sum;
	double withdraw;
public:
	void input() override {
		cout << "\nEnter Account Number: ";
		cin >> account_number;
		cout << "\nEnter Account Balance: ";
		cin >> balance;
		cout << "\nEnter New Amount to add in balance: ";
		cin >> sum;
		cout << "Enter Amount to be Withdrawn;";
		cin >> withdraw;
		name = "Balance in Account with Number: ";

	}

	double deposit() override {
		return balance=sum+balance;
	}
	double withdraw() override {
		return balance = balance - withdraw;
	}
	void display() override {
		cout << "\nAccount Number is " << account_number << endl;
		cout << "Balance in Account : " << balance << endl;
		cout << "Withdrawn Amount:  " << withdraw << endl;
		cout << "Balance After Amount is withdrawn: " << withdraw() << endl;
	};