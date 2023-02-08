#include <book.h>
#include <util.h>
#include <string>

std::set<std::string> Book::keywords()
{
	std::set<std::string> words = parseStringToWords(name_);
	std::set<std::string> author = parseStringToWords(author_);
	words.insert(author.begin(), author.end());
	words.insert(isbn_);
	return words;
}

std::string Book::displayString() const
{

}

void Book::dump(std::ostream& os) const
{

}
