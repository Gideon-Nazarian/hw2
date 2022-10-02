#include "movie.h"
 
 
Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating):
Product(category, name, price, qty), genre(genre), rating(rating)
{
 
 
}
std::set<std::string> Movie:: keywords() const
{
 std::set<std::string> genres = parseStringToWords(genre);
 std::set<std::string> names = parseStringToWords(name_);
 std::set<std::string> ratings = parseStringToWords(rating);
 
 std::set<std::string> combo1 = setUnion(genres, names);
 std::set<std::string> combo2 = setUnion(combo1, ratings);
 
 return combo2;
 
 
}
 
std::string Movie::displayString() const
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
 
 std::string temp =  name_ + "\n" + "Genre: " + genre + " Rating: " + rating + "\n" + realPrice + " " +
 std::to_string(qty_) + " left \n";
 
 return temp;
 
}
void Movie::dump(std::ostream& os) const
{
 os << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_
   << std::endl << genre << std::endl << rating << std::endl;
}
