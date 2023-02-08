#include "mydatastore.h"
#include "util.h"

void MyDataStore::addProduct(Product* p)
{
	m_products.insert(p);
}

void MyDataStore::addUser(User* u)
{
	m_users.insert(u);
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
	std::vector<Product*> foundProds;

	if (type == 0) //AND search
	{
		for (std::string currTerm : terms)
		{
			std::set<std::string> s(v.begin(), v.end());
			if (setIntersection(currProd->keywords(), s) == currProd->keyWords)
			{
				foundProds.push_back(currProd);
			}
		}
	}
	else // OR search
	{
		for (Product* currProd : m_products)
		{
			std::set<std::string> s(v.begin(), v.end());
			if (setUnion(currProd->keywords(), s) != currProd->keyWords)
			{
				foundProds.push_back(currProd);
			}
		}
	}
}

void MyDataStore::dump(std::ostream& ofile)
{
	for (Product* currProd : m_products)
	{
		currProd->dump();
	}
}
