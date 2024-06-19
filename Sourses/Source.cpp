#include "Library.h"
using namespace std;

int main() {
	int choise, length, temp;
	string tmp;
	Library* lib = new Library();
	Book* book = new Book();
	Member* member = new Member();
	std::shared_ptr<Book[]> borrowedBooks{ nullptr };
	while (true) {
		cout << "1 - Add member\n2 - Add book\n3 - Remove member\n4 - Remove book\n5 - Search book\n6 - Show all info\nElse - Exit\n";
		cin >> choise;
		if (choise == 1) {
			cout << "Enter the name: ";
			cin >> tmp;
			member->setName(tmp);
			cout << "Enter the member ID: ";
			cin >> tmp;
			member->setMemeberId(tmp);
			cout << "Enter the count of borrowed books: ";
			cin >> length;
			member->setLength(length);
			for (int i = 0; i < length; i++) {
				cout << "Enter the title: ";
				cin >> tmp;
				book->setTitle(tmp);
				cout << "Enter the author: ";
				cin >> tmp;
				book->setAuthor(tmp);
				cout << "Enter the isbn: ";
				cin >> tmp;
				book->setIsbn(tmp);
				cout << "Enter the available: ";
				cin >> temp;
				book->setIsAvailable(temp);
				member->borrowBook(*book);
			}
			lib->registerMember(*member);
		}
		else if (choise == 2) {
			cout << "Enter the title: ";
			cin >> tmp;
			book->setTitle(tmp);
			cout << "Enter the author: ";
			cin >> tmp;
			book->setAuthor(tmp);
			cout << "Enter the isbn: ";
			cin >> tmp;
			book->setIsbn(tmp);
			cout << "Enter the available: ";
			cin >> temp;
			book->setIsAvailable(temp);
			lib->addBook(*book);
		}
		else if (choise == 3) {
			cout << "Enter the member ID: ";
			cin >> tmp;
			lib->unregisterMember(tmp);
		}
		else if (choise == 4) {
			cout << "Enter the isbn: ";
			cin >> tmp;
			lib->removeBook(tmp);
		}
		else if (choise == 5) {
			cout << "Enter the isbn: ";
			cin >> tmp;
			lib->findBook(tmp);
		}
		else if (choise == 6) {
			lib->displayAllBooks();
		}
		else {
			break;
		}
	}
}