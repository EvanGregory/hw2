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
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s\nAuthor: %s ISBN: %s\n%.2f %d left.\n",
        name_.c_str(), author_.c_str(), isbn_.c_str(), price_, qty_);
    return std::string(buffer);
	//std::string str;
	//str = (name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + 
	//price_ + " " + qty_ + " left.\n");
	//return str;
}

void Book::dump(std::ostream& os) const
{
	Product::dump(os);
	os << isbn_ << "\n" << author_ << "\n";
}
