#include <product.h>
#include <string>
class Book : Product{
public:
	Book(const std::string name, double price, int qty, std::string author, std::string isbn) : 
		Product("Book", name, price, qty), author_(author), isbn_(isbn)
	{}

	std::set<std::string> keywords();
	std::string displayString() const;
	void dump(std::ostream& os) const;

private:
	std::string author_;
	std::string isbn_;
};
