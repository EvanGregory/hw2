#include "movie.h"
#include "util.h"
#include <string>

std::set<std::string> Movie::keywords()
{
	std::set<std::string> words = parseStringToWords(name_);
	words.insert(genre_);
	return words;
}

std::string Movie::displayString() const
{

}

void Movie::dump(std::ostream& os) const
{

}

