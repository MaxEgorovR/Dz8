#include "Member.h"

Member::Member(std::string & name, std::string& memberId, std::shared_ptr<Book> & books, int& length)
{
	this->name = name;

	this->memberId = memberId;

	this->length = length;

	this->borrowedBooks = std::make_shared<Book[]>(books);
}

std::string Member::getName() {
	return this->name;
}

void Member::setName(std::string & name) {
	this->name = name;
}

std::string Member::getMemberId() {
	return this->memberId;
}

void Member::setMemeberId(std::string& id) {
	this->memberId = id;
}

int Member::getLength() {
	return this->length;
}

void Member::setLength(int& id) {
	this->length = id;
}

std::shared_ptr<Book[]> Member::getBorrowedBooks() {
	return this->borrowedBooks;
}

void Member::setBorrowedBooks(std::shared_ptr<Book[]>& books) {
	this->borrowedBooks = books;
}

void Member::borrowBook(Book& book) {
	this->length++;
	std::shared_ptr<Book[]> tmp = std::make_shared<Book[]>(this->length);
	for (int i = 0; i < this->length - 1; i++) {
		tmp[i] = this->borrowedBooks[i];
	}
	tmp[length - 1] = book;
	this->borrowedBooks = tmp;
}

void Member::returnBook(Book & book) {
	this->length--;
	int counter = 0;
	std::shared_ptr<Book[]> tmp = std::make_shared<Book[]>(this->length);
	for (int i = 0; i < this->length; i++) {
		if (this->borrowedBooks[i].getTitle() == book.getTitle() || counter != 0) {
			counter++;
			tmp[i] = this->borrowedBooks[i+1];
		}
		else {
			tmp[i] = this->borrowedBooks[i];
		}
	}
	this->borrowedBooks = tmp;
}