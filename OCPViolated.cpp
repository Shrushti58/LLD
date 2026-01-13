//OCP : Open Close Principle in SOLID principles states that class should be open for extension and close for modification.
//In following eg we have class dbstorage where firstly we only have feature of SQL Storage and we now wanted to add features of Mongo DB storage as well as File Storage, Now we can't directly
//modify the class else it will violate the OCP principle.

#include <bits/stdc++.h>
using namespace std;

class product{
  
  public:
    string name="";
    int price=0;
    
    product(string n,int p){
      name=n;
      price=p;
    }
};


class shoppingcart{
  
  public:
    vector<product*>products;
    int total;
    
    shoppingcart(){
      total=0;
    }
    
    //setter
    void addproducts(string n,int p){
      product* newpro=new product(n,p);
      products.push_back(newpro);
    }
    
    //getter
    vector<product*> getproducts(){
      return products;
    }
    
    //Calculate total price
    int totalprice(){
      for(auto it:products){
        total+=it->price;
      }
      return total;
    }
};

class invoice{
  
  public:
    shoppingcart* cart;
    invoice(shoppingcart* ref){
      cart=ref;
    }
    
    void printinvoice(){
      for(auto it:cart->getproducts()){
        cout<<"Name of Product:"<<it->name<<" "<<"Price :"<<it->price<<endl;
      }
      cout<<"Total Price :"<<cart->totalprice();
    }
};

class databasestorage{
  
  public:
    shoppingcart* db;
    databasestorage(shoppingcart* s){
      db=s;
    }
    
    //Save Data to SQl
    void savetoSQL(){
      cout<<"Data saved to SQL";
    }
    
    //Save data to MongoDB
    void savetoMongo(){
      cout<<"Data Saved to MongoDB";
    }
    
    //Save to File 
    void savetoFile(){
      cout<<"Data Saved to File";
    }
    
};

int main(){
  
  shoppingcart* s=new shoppingcart();
  s->addproducts("Mouse",200);
  s->addproducts("Keyboard",400);
  invoice in(s);
  in.printinvoice();
  databasestorage d(s);
  d.savetoMongo();
}
