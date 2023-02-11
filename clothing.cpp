#include "clothing.h"
#include "util.h"
#include <string>

std::set<std::string> Clothing::keywords() const
{
	std::set<std::string> names = parseStringToWords(name_);
	std::set<std::string> brand = parseStringToWords(brand_);
	return setUnion(names, brand);
}

std::string Clothing::displayString() const
{
	std::string str; 
	str.append(name_, "\nSize: ", size_, " Brand: ", brand_, "\n", 
	price_, " ", qty_, " left.\n");
	return str;
}

void Clothing::dump(std::ostream& os) const
{
	Product::dump(os);
	os << size_ << "\n" << brand_ << "\n";
}

