#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "user.h"
#include "util.h"
 
 
class Clothing : public Product {
public:
  Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
   //methods
 
   std::set<std::string> keywords() const;
  
   std::string displayString() const;
 
   void dump(std::ostream& os) const;
 
 
private:
 //clothing specific variables
 std::string size;
 std::string brand;
 
};
#endif
