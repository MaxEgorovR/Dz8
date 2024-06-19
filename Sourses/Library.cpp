#include "Library.h"

Library::Library(std::shared_ptr<Book[]> books, std::shared_ptr<Member[]> members) {
	this->books = std::make_shared<Book[]>(books);

	this->members = std::make_shared<Member[]>(members);
}

void Library::addBook(const Book& book) {
	this->lengthB++;
	std::shared_ptr<Book[]> tmp = std::make_shared<Book[]>(this->lengthB);
	for (int i = 0; i < this->lengthB - 1; i++) {
		tmp[i] = this->books[i];
	}
	tmp[lengthB - 1] = book;
	this->books = tmp;
}

void Library::removeBook(const std::string& isbn) {
	this->lengthB--;
	int counter = 0;
	std::shared_ptr<Book[]> tmp = std::make_shared<Book[]>(this->lengthB);
	for (int i = 0; i < this->lengthB; i++) {
		if (this->books[i].getIsbn() == isbn || counter != 0) {
			counter++;
			tmp[i] = this->books[i + 1];
		}
		else {
			tmp[i] = this->books[i];
		}
	}
	this->books = tmp;
}

std::shared_ptr<Book> Library::findBook(const std::string& isbn) {
	std::shared_ptr<Book> book{ nullptr };
	for (int i = 0; i < this->lengthB; i++) {
		if (this->books[i].getIsbn() == isbn) {
			book = std::make_shared<Book>(this->books[i]);
		}
	}
	return book;
}

void Library::registerMember(const Member& member) {
	this->lengthM++;
	std::shared_ptr<Member[]> tmp = std::make_shared<Member[]>(this->lengthM);
	for (int i = 0; i < this->lengthM - 1; i++) {
		tmp[i] = this->members[i];
	}
	tmp[lengthB - 1] = member;
	this->members = tmp;
}

void Library::unregisterMember(const std::string& memberId) {
	this->lengthM--;
	std::shared_ptr<Member[]> tmp = std::make_shared<Member[]>(this->lengthM);
	int counter = 0;
	for (int i = 0; i < this->lengthM - 1; i++) {
		if (this->members[i].getMemberId() == memberId || counter != 0) {
			counter++;
			tmp[i] = this->members[i + 1];
		}
		else {
			tmp[i] = this->members[i];
		}
	}
	this->members = tmp;
}

void Library::displayAllBooks() {
	for (int i = 0; i < lengthB; i++) {
		books[i].displayDetails();
		std::cout << std::endl;
	}
}