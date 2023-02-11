#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "product.h"

class Book : public Product
{
public:
	Book(const std::string name, double price, int qty, std::string author, std::string isbn) : 
		Product("book", name, price, qty), author_(author), isbn_(isbn)
	{}

	std::set<std::string> keywords() const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

private:
	std::string author_;
	std::string isbn_;
};
#endif