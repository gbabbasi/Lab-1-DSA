#include <iostream>
#include <string>

using namespace std;

class LibraryItem {
protected:
	string title;
	string author;
	int id;
	bool isBorrowed;

public:
	LibraryItem(const string& t, const string& a, int i)
		: title(t), author(a), id(i), isBorrowed(false) {}

	virtual void borrow() = 0;
	virtual void returnItem() = 0;

	virtual void displayInfo() const {
		cout << "Title: " << title << "\n"
			<< "Author: " << author << "\n"
			<< "ID: " << id << "\n"
			<< "Status: " << (isBorrowed ? "Borrowed" : "Available") << "\n";
	}

	virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
public:
	Book(const string& t, const string& a, int i)
		: LibraryItem(t, a, i) {}

	void borrow() override {
		if (isBorrowed) {
			cout << "Book \"" << title << "\" is already borrowed.\n";
		}
		else {
			isBorrowed = true;
			cout << "You have borrowed the book \"" << title << "\".\n";
		}
	}

	void returnItem() override {
		if (!isBorrowed) {
			cout << "Book \"" << title << "\" was not borrowed.\n";
		}
		else {
			isBorrowed = false;
			cout << "You have returned the book \"" << title << "\".\n";
		}
	}
};

class Journal : public LibraryItem {
public:
	Journal(const string& t, const string& a, int i)
		: LibraryItem(t, a, i) {}

	void borrow() override {
		if (isBorrowed) {
			cout << "The Journal you want \"" << title << "\" is already borrowed.\n";
		}
		else {
			isBorrowed = true;
			cout << "You have borrowed the journal \"" << title << "\".\n";
		}
	}

	void returnItem() override {
		if (!isBorrowed) {
			cout << "The Journal named \"" << title << "\" was not borrowed.\n";
		}
		else {
			isBorrowed = false;
			cout << "You have returned the journal \"" << title << "\".\n";
		}
	}
};

int main() {
	string title, author;
	int id;
	int typeChoice, actionChoice;

	cout << "Library System\n";
	cout << "==============\n";
	cout << "Choose item type:\n";
	cout << "1. Book\n2. Journal\nEnter choice: ";
	cin >> typeChoice;
	cin.ignore(); // Ignore leftover newline

	cout << "Enter title: ";
	getline(cin, title);

	cout << "Enter author: ";
	getline(cin, author);

	cout << "Enter ID: ";
	cin >> id;

	LibraryItem* item = nullptr;

	if (typeChoice == 1) {
		item = new Book(title, author, id);
	}
	else if (typeChoice == 2) {
		item = new Journal(title, author, id);
	}
	else {
		cout << "Invalid item type selected.\n";
		return 1;
	}

	cout << "\nChoose an action:\n";
	cout << "1. Borrow item\n2. Return item\nEnter choice: ";
	cin >> actionChoice;

	cout << "\n--- Performing Action ---\n";
	if (actionChoice == 1) {
		item->borrow();
	}
	else if (actionChoice == 2) {
		item->returnItem();
	}
	else {
		cout << "Invalid action selected.\n";
		delete item;
		return 1;
	}

	cout << "\n--- Item Information ---\n";
	item->displayInfo();

	delete item;

	return 0;
}
