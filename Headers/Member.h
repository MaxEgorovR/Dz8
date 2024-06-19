#pragma once
#include "Book.h"

class Member {
	std::string name;

	std::string memberId;

	std::shared_ptr<Book[]> borrowedBooks{nullptr};

	int length;
public:
	Member(){}

	Member(std::string & name, std::string& memberId, std::shared_ptr<Book> & books, int& length);

	std::string getName();

	void setName(std::string & name);

	std::string getMemberId();

	void setMemeberId(std::string & id);

	int getLength();

	void setLength(int& id);

	std::shared_ptr<Book[]> getBorrowedBooks();

	void setBorrowedBooks(std::shared_ptr<Book[]>& books);

	void borrowBook(Book& book);

	void returnBook(Book& book);
};