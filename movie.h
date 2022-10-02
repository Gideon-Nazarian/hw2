#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "user.h"
#include "util.h"
 
 
class Movie : public Product {
public:
    Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
   //methods
 
   std::set<std::string> keywords() const;
  
   std::string displayString() const;
 
   void dump(std::ostream& os) const;
 
 
private:
 //movie specific variables
 std::string genre;
 std::string rating;
 
};
#endif
