#include "clothing.h"


Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand):
Product(category, name, price, qty), size(size), brand(brand) 
{


}
std::set<std::string> Clothing:: keywords() const 
{
  std::set<std::string> sizes = parseStringToWords(size);
  std::set<std::string> names = parseStringToWords(name_);
  std::set<std::string> brands = parseStringToWords(brand);

  std::set<std::string> combo1 = setUnion(sizes, names);
  std::set<std::string> combo2 = setUnion(combo1, brands);

  return combo2;


}

std::string Clothing::displayString() const
{
	
	std::string temp =  name_ + "\n Price: " + std::to_string(price_) + "\n Quantity: " +
	std::to_string(qty_) + " in stock \n" + "size: " + size + "\n Brand: " + brand + "\n";

  return temp;

}
void Clothing::dump() const
{
	std::cout << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_ 
		<< std::endl << size << std::endl << brand << std::endl; 
}
    



