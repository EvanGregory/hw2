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

std::set<Product*>& MyDataStore::getProducts() const
{
	return m_products;
}

std::set<User*>& MyDataStore::getUsers() const
{
	return m_users;
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
		std::set<std::string> s(terms.begin(), terms.end());
		for (std::string currTerm : terms)
		{
			if (setIntersection(currProd->keywords(), s) == currProd->keyWords)
			{
				foundProds.push_back(currProd);
			}
		}
	}
	else // OR search
	{
		std::set<std::string> s(terms.begin(), terms.end());
		for (Product* currProd : m_products)
		{
			if (setUnion(currProd->keywords(), s) != currProd->keyWords)
			{
				foundProds.push_back(currProd);
			}
		}
	}
}

void MyDataStore::dump(std::ostream& ofile)
{
	ofile << "<products>" << endl;
	for (Product* currProd : m_products)
	{
		currProd->dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	for (User* currUser : m_users)
	{
		currUser->dump(ofile);
	}
	ofile << "</users>" << endl;
}
