#include "user.h"
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1), cart_()
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type), cart_()
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

std::vector<Product*>& User::getCart() const
{
    return cart_;
}

void User::addToCart(Product* p)
{
    cart_.push_back(p);
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << balance_ << " " << type_ << endl;
}

