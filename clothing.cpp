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
 std::string tempPrice = std::to_string(price_);
 int i = 0;
 while(tempPrice[i] != '.')
 {
   i++;
 }
 i += 2;
 std::string realPrice = "";
 for(int j = 0; j <= i ; j++){
   realPrice += tempPrice[j];
 }
  std::string temp =  name_ +  "\n" + "Size: " + size + " Brand: " + brand +"\n" + realPrice +" " +
 std::to_string(qty_) + " left \n";
 
 return temp;
 
}
void Clothing::dump(std::ostream& os) const
{
 os << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_
   << std::endl << size << std::endl << brand << std::endl;
}

