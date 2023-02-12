#include "movie.h"
#include "util.h"
#include <string>

std::set<std::string> Movie::keywords() const
{
	std::set<std::string> words = parseStringToWords(name_);
	words.insert(convToLower(genre_));
	return words;
}

std::string Movie::displayString() const
{
	char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s\nGenre: %s Rating: %s\n%.2f %d left.\n",
        name_.c_str(), genre_.c_str(), rating_.c_str(), price_, qty_);
    return std::string(buffer);
}

void Movie::dump(std::ostream& os) const
{
	Product::dump(os);
	os << genre_ << "\n" << rating_ << "\n";
}

