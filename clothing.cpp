#include <clothing.h>
#include <util.h>
#include <string>

std::set<std::string> Clothing::keywords()
{
	return setUnion(parseStringToWords(name_), parseStringToWords(brand_));
}

std::string Clothing::displayString() const
{

}

void Clothing::dump(std::ostream& os) const
{

}

