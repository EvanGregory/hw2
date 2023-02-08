#include "datastore.h"

class MyDataStore : DataStore
{
public:
	void addProduct(Product* p);

	void addUser(User* u);

	/**
	 * Performs a search of products whose keywords match the given "terms"
	 *  type 0 = AND search (intersection of results for each term) while
	 *  type 1 = OR search (union of results for each term)
	 */
	std::vector<Product*> search(std::vector<std::string>& terms, int type);

	void dump(std::ostream& ofile);

private:
	std::set<Product*> m_products;
	std::set<User*> m_users;
};