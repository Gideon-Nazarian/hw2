#include "book.h"



Book::Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string Author):
Product(category, name, price, qty), ISBN(ISBN), Author(Author) 
{


}
std::set<std::string> Book:: keywords() const 
{
  std::set<std::string> isbn = parseStringToWords(ISBN);
  std::set<std::string> names = parseStringToWords(name_);
  std::set<std::string> authors = parseStringToWords(Author);

  std::set<std::string> combo1 = setUnion(isbn, names);
  std::set<std::string> combo2 = setUnion(combo1, authors);

  return combo2;


}

std::string Book::displayString() const
{
	
	//std::string tempPrice = price_;
  //std::string tempQty = qty_;
	

	std::string temp =  name_ + "\n Price: " + std::to_string(price_) + "\n Quantity: " +
	std::to_string(qty_) + " in stock \n" + "ISBN: " + ISBN + "\n Authour: " + Author + "\n";

  return temp;

}
void Book::dump() const
{
	std::cout << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_ 
		<< std::endl << ISBN << std::endl << Author << std::endl; 
}
    



