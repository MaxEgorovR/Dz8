#pragma once
#include "Member.h"

class Library {
	std::shared_ptr<Book[]> books{ nullptr };

	std::shared_ptr<Member[]> members{ nullptr };

	int lengthB;

	int lengthM;
public:
	Library(){}

	Library(std::shared_ptr<Book[]> books, std::shared_ptr<Member[]> members);

	void addBook(const Book& book);

	void removeBook(const std::string& isbn);

	std::shared_ptr<Book> findBook(const std::string& isbn);

	void registerMember(const Member& member);

	void unregisterMember(const std::string& memberId);

	void displayAllBooks();
};