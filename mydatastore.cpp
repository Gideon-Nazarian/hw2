#include "mydatastore.h"
 
 
MyDataStore::MyDataStore()
{
 
}
 
MyDataStore::~MyDataStore() {
  
   std::vector<Product*>::iterator Prod_it; // product iterator
  
   //deletes all of the products created(all Books, Movies and Clothing)
   for(Prod_it = products.begin(); Prod_it != products.end(); ++Prod_it) {
     delete *Prod_it;
   }
   
   // delete users
   std::vector<User*>::iterator User_it; // user itterator

		for (User_it = users.begin(); User_it != users.end(); ++User_it) {
			delete *User_it; 
		}

}
 
bool MyDataStore::eUser(std::string username) {
    
     std::vector<User*>::iterator it;
 
     for(it = users.begin(); it!=users.end(); ++it) {
       if((*it)->getName() == username)
       {
          return true;
       }
     }
     return false;
}
 
 
void MyDataStore:: addProduct(Product* p)
{
 
   std::set<std::string> keys; // set containing the keys for the product
  
   products.push_back(p); // add product to product list
 
   keys = p->keywords(); // uses method we made to get all of the keywords and store in keys
 
   std::set<std::string>::iterator it;
 
   for(it = keys.begin(); it!=keys.end(); ++it) {
     if(pKeys.find(*it) == pKeys.end())  // if keyword not found, make new product set
     {
       std::set<Product*> temp;
       temp.insert(p);
 
       pKeys.insert(make_pair(*it, temp));
 
     }
     else
     {
       pKeys.find(*it)->second.insert(p); // inserts product into corresponding key
     }
 
   }
 
}
void MyDataStore :: addUser(User* u)
{
 bool sameName = false; // bool value to be modified if same name
 
 if(users.size() == 0) // if empty add a user
 {
   users.push_back(u);
 }
 else
 {
   for(int i = 0; i < (int)users.size(); ++i) // go through users
   {
     if( convToLower(u -> getName()) == convToLower(users[i] -> getName())) //prevent adding a user with same name
     {
       sameName = true;
     }
 
   }
     if(sameName)
     {
      // std::cout << "Error user with name already made"<<endl;
      
     }else
     {
       users.push_back(u); // add to users if not a copy
     }
   }
}
 
std::vector<Product*> MyDataStore :: search(std::vector<std::string>& terms, int type)
{
  std::vector<Product*> found; // temp vector to hold all products found by search
 
   if(terms.size() == 0) // if empty(searched nothing) return the empty vector
   {
     return found;
   }

    int tempSol = 0;
    for (int i = 0; i < (int)terms.size();i++){
      if(pKeys.find(terms[i])!=pKeys.end()){
        tempSol = i;
        i += terms.size();
      }
    }
   if(pKeys.find(terms[tempSol])!=pKeys.end()) // if first(found) term is found in vector of pKeys
   {
     std::set<Product*> productOfKey = pKeys.find(terms[tempSol])->second; //products that correspond to key
 
     std::set<Product*> productOfKey2; // temp

     if(type == 0) // and search
     {
       std::vector<std::string>::iterator andIt;
       for(andIt = terms.begin(); andIt!=terms.end(); ++andIt)
       {
         std::map<std::string, std::set<Product*> >::iterator key2 = pKeys.find((*andIt));
         if (key2 == pKeys.end()){
           continue;
         }
         productOfKey2 = key2->second;
 
        
         productOfKey = setIntersection(productOfKey, productOfKey2);
       }
     }

     if(type == 1) // or search
     {
       std::vector<std::string>::iterator orIt;
       for(orIt = terms.begin(); orIt != terms.end(); ++orIt)
       {
         std::map<std::string, std::set<Product*> >::iterator key1 = pKeys.find((*orIt));
         if (key1 == pKeys.end()){
           continue;
         }
         productOfKey2 = key1->second;
         productOfKey = setUnion(productOfKey, productOfKey2);
       }
 
     }
     
     for(std::set<Product*>::iterator it = productOfKey.begin(); it!=productOfKey.end(); ++it) {
       found.push_back(*it);
     }
 
   }
 
   return found;
 
}
void MyDataStore :: dump(std::ostream& ofile)
{
 //outputs similarly to the given info on part 1 slide (data)
 ofile <<"<products>"<< std::endl;
   for(int i = 0; i < (int)products.size(); ++i)
   {
     products[i]->dump(ofile);
   }
   ofile << "</products>" << std::endl << "<users>" << std::endl;
 
   for(int i = 0; i < (int)users.size(); ++i) {
     users[i]->dump(ofile);
   }
   ofile << "</users>" << std::endl;
}
 
void MyDataStore::addCart(std::string uName, Product* p) {
 
   if(!eUser(uName))
   {
     std::cout << "invalid request" << std::endl;
     return;
    }
    bool found = false;
    for(unsigned int i = 0; i < products.size(); i++){
      if(products[i] == p){
        found = true;
      }
    }
    if(found == false){
      std::cout << "invalid request" << std::endl;
     return;
    }

   if(Ucarts.find(uName) == Ucarts.end()) { // if new cart
     std::vector<Product*> temp;
     temp.push_back(p);
     Ucarts.insert(make_pair(uName, temp));
   }
   else {
     Ucarts.find(uName)->second.push_back(p);
   }
 }
 /////////////////////////////////////////////////
 
 void MyDataStore::viewCart(std::string uName){
 
     if(!eUser(uName))
     {
       std::cout<< "Invalid username" << std::endl;
       return;
     }
 
     if(Ucarts.find(uName) != Ucarts.end()) {
 
       std::vector<Product*> userCart = Ucarts.find(uName)->second;
 
       for(int i = 0; i < (int)userCart.size(); ++i) {
         std::cout << ""<<std::endl;
         std::cout << "Item " << i+1 << std::endl;
         std::cout << userCart[i] -> displayString() << std::endl;
       }
     }
     else {
     std::cout << "Empty cart" << std::endl;
     return;
   }
 
 }
 void MyDataStore::buyCart(std::string uName) {
 
     if(!eUser(uName))
     {
       std::cout<< "Invalid username" << std::endl;
       return;
     }
 
     std::vector<User*>::iterator Uit;
 
     for(Uit = users.begin(); Uit!=users.end(); ++Uit)  // loops to get to specific user
     {
       if((*Uit) -> getName() == uName)
       {
         break;
       }
     }
 
 
    
       if(Ucarts.find(uName) != Ucarts.end())
       {
 
         std::vector <Product*> *userCart = &Ucarts.find(uName)->second; // temp holder for user cart to manipulate
 
         for(int i = 0; i < (int)(userCart -> size()); ++i)
          {
          
           if(userCart -> at(i) -> getQty() > 0 && ((*Uit)->getBalance() - userCart->at(i)->getPrice()) >= 0) { //checks if can afford and stock
             (*Uit)->deductAmount(userCart->at(i)->getPrice());
             userCart->at(i)->subtractQty(1);      // -1 stock
             userCart->erase(userCart->begin()+i); // moves out of cart b/c bought
           i--;
           }
           else
           {
             // do nothing if no stock or cant afford
           }
         }
       }
       else // cart empty or never had one do nothing
       {
         // return;
       }
    
   }
 
