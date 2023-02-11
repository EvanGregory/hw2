#include "product.h"
#include <string>

class Clothing : public Product {
public:
	Clothing(const std::string name, double price, int qty, std::string size, std::string brand) :
		Product("clothing", name, price, qty), size_(size), brand_(brand)
	{}

	std::set<std::string> keywords() const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

private:
	std::string size_;
	std::string brand_;
};

