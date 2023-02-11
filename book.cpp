#include <string>
#include "book.h"
#include "util.h"


std::set<std::string> Book::keywords()
{
	std::set<std::string> words = setUnion(parseStringToWords(name_), parseStringToWords(author_));
	words.insert(isbn_);
	return words;
}

std::string Book::displayString() const
{

}

void Book::dump(std::ostream& os) const
{
	Product::dump(os);
	os << isbn_ << "\n" << author_ << endl;
}
