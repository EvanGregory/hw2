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
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s\nSize: %s Brand: %s\n%.2f %d left.\n",
        name_.c_str(), size_.c_str(), brand_.c_str(), price_, qty_);
    return std::string(buffer);
}

void Clothing::dump(std::ostream& os) const
{
	Product::dump(os);
	os << size_ << "\n" << brand_ << "\n";
}

