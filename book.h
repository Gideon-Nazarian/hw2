#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "user.h"

class Book : public Product {
public:
    Book(const std::string name, double price, int quantity, std::string catigory, std::string ISBN, std::string Author);
    //methods

    std::set<std::string> keywords() const;
    
    std::string displayString() const;
   
    void dump(std::ostream& os) const; 


private:
  //book specific variables
  std::string ISBN;
  std::string Author;

};
#endif