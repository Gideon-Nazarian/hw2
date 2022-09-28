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
	
	std::string temp =  name_ + "\n Price: " + std::to_string(price_) + "\n Quantity: " +
	std::to_string(qty_) + " in stock \n" + "Genre: " + genre + "\n Rating: " + rating + "\n";

  return temp;

}
void Movie::dump() const
{
	std::cout << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_ 
		<< std::endl << genre << std::endl << rating << std::endl; 
}
    



