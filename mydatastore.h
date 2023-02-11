#include "datastore.h"

class MyDataStore : public DataStore
{
public:
	~MyDataStore ()
	{
		for (auto it = m_products.rbegin(); it != m_products.rend(); it++)
		{
			delete* it;
		}
    for (auto it = m_users.rbegin(); it != m_users.rend(); it++)
    {
      delete* it;
    }
	}

	void addProduct(Product* p);

	void addUser(User* u);


	/**
	 * Performs a search of products whose keywords match the given "terms"
	 *  type 0 = AND search (intersection of results for each term) while
	 *  type 1 = OR search (union of results for each term)
	 */
	std::vector<Product*> search(std::vector<std::string>& terms, int type);

	void dump(std::ostream& ofile);

  std::set<Product*> m_products;
	std::set<User*> m_users;
private:
};