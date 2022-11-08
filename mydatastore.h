 
#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <map>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"
 
 
 
class MyDataStore : public DataStore {
public:
 
   MyDataStore();
 
   ~MyDataStore();
 
   void addProduct(Product* p);
 
   void addUser(User* u);
 
   std::vector<Product*> search(std::vector<std::string>& terms, int type);
 
   void addCart(std::string uName, Product* p);
 
   bool eUser(std::string uName);
 
   void dump(std::ostream& ofile);
 
   void viewCart(std::string uName);
 
   void buyCart(std::string uName);
 
 
 
 
private:
   std::vector<User*> users;
   std::vector<Product*> products;
   std::map<std::string, std::vector<Product*>> Ucarts;
   std::map<std::string, std::set<Product*>> pKeys;
     
 
};
 
#endif
