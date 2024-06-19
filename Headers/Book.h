#pragma once
#include <iostream>
#include <string>

class Book {
protected:
	std::string title;

	std::string author;

	std::string isbn;

	int isAvailable;
public:
	Book(){}

	Book(std::string title, std::string author, std::string isbn, int isAvailable);

	std::string getTitle();

	void setTitle(std::string title);

	std::string getAuthor();

	void setAuthor(std::string author);

	std::string getIsbn();

	void setIsbn(std::string isbn);

	int getIsAvailable();

	void setIsAvailable(int isAvailable);

	void displayDetails();
};