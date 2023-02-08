#include <clothing.h>
#include <util.h>
#include <string>

std::set<std::string> Clothing::keywords()
{
	std::set<std::string> words = parseStringToWords(name_);
	std::set<std::string> brand = parseStringToWords(brand_);
	words.insert(brand.begin(), brand.end());
	return words;
}

std::string Clothing::displayString() const
{

}

void Clothing::dump(std::ostream& os) const
{

}

