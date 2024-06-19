#include "Book.h"

Book::Book(std::string title, std::string author, std::string isbn, int isAvailable)
{
	this->title = title;
	this->author = author;
	this->isAvailable = isAvailable;
	this->isbn = isbn;
}

std::string Book::getTitle() {
	return this->title;
}

void Book::setTitle(std::string title) {
	this->title = title;
}

std::string Book::getAuthor() {
	return this->author;
}

void Book::setAuthor(std::string author) {
	this->author = author;
}

std::string Book::getIsbn() {
	return this->isbn;
}

void Book::setIsbn(std::string isbn) {
	this->isbn = isbn;
}

int Book::getIsAvailable() {
	return this->isAvailable;
}

void Book::setIsAvailable(int isAvailable) {
	this->isAvailable = isAvailable;
}

void Book::displayDetails() {
	std::cout << "Title: " << this->title;

	std::cout << "Author: " << this->author;

	std::cout << "Isbn: " << this->isbn;

	std::cout << "isAvailable: " << this->isAvailable;
}