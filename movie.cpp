#include "movie.h"
#include "util.h"
#include <string>

std::set<std::string> Movie::keywords() const
{
	std::set<std::string> words = parseStringToWords(name_);
	words.insert(genre_);
	return words;
}

std::string Movie::displayString() const
{
	std::string str;
	str.append(name_, "\nGenre: ", genre_, " Rating: ", rating_, "\n", 
	price_, " ", qty_, " left.\n");
	return str;
}

void Movie::dump(std::ostream& os) const
{
	Product::dump(os);
	os << genre_ << "\n" << rating_ << "\n";
}

