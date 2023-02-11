#include <string>
#include "book.h"
#include "util.h"


std::set<std::string> Book::keywords() const
{
	std::set<std::string> names = parseStringToWords(name_);
	std::set<std::string> author = parseStringToWords(author_);
	std::set<std::string> words = setUnion(names, author);
	words.insert(isbn_);
	return words;
}

std::string Book::displayString() const
{
	std::string str;
	str.append(name_, "\nAuthor: ", author_, " ISBN: ", isbn_, "\n", 
	price_, " ", qty_, " left.\n");
	return str;
}

void Book::dump(std::ostream& os) const
{
	Product::dump(os);
	os << isbn_ << "\n" << author_ << "\n";
}
