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
  std::string temp =  name_ + "\n"+ "Author: " + Author + " ISBN: " + ISBN + "\n" + realPrice + " " +
 std::to_string(qty_) + " left \n";
 
 return temp;
 
}
void Book::dump(std::ostream& os) const
{
 os << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_
   << std::endl << ISBN << std::endl << Author << std::endl;
}
