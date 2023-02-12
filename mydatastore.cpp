#include "mydatastore.h"
#include "util.h"

#include <iostream>
#include <sstream>

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
		std::set<std::string> s(terms.begin(), terms.end());
		for (Product* currProd : m_products)
		{
      		std::set<std::string> keywords = currProd->keywords();
			if (setUnion(keywords, s) == keywords)
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
      		std::set<std::string> keywords = currProd->keywords();
			if ( !(setIntersection(keywords, s).empty()) )
			{
				foundProds.push_back(currProd);
			}
		}
	}
  return foundProds;
}

void MyDataStore::dump(std::ostream& ofile)
{
	ofile << "<products>" << "\n";
	for (Product* currProd : m_products)
	{
		currProd->dump(ofile);
	}
	ofile << "</products>" << "\n";
	ofile << "<users>" << "\n";
	for (User* currUser : m_users)
	{
		currUser->dump(ofile);
	}
	ofile << "</users>" << "\n";
}
