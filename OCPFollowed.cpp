//Instead of Modifying dbstorage class every time we needed to add new feature, we create abstract class called DBPersistance and inherited it in savetoMongo,savetoSQL,savetoFile.
//By adding one layer of abstraction we have followed OCP principle.

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

//class databasestorage{
  
//   public:
//     shoppingcart* db;
//     databasestorage(shoppingcart* s){
//       db=s;
//     }
    
//     //Save Data to SQl
//     void savetoSQL(){
//       cout<<"Data saved to SQL";
//     }
    
//     //Save data to MongoDB
//     void savetoMongo(){
//       cout<<"Data Saved to MongoDB";
//     }
    
//     //Save to File 
//     void savetoFile(){
//       cout<<"Data Saved to File";
//     }
    
//};


class DBPersistance{
  public:
    shoppingcart* s;
    virtual void save(shoppingcart* s)=0; //Pure virtual func
};

class savetoMongo:public DBPersistance{
  
  public:
    void save(shoppingcart* c){
      cout<<"Saved Data to MongoDB";
    }
};

class savetoSQL:public DBPersistance{
  
  public:
    void save(shoppingcart* s){
      cout<<"Saved to SQL";
    }
};

class savetoFile:public DBPersistance{
  public:
   void save(shoppingcart* s){
     cout<<"Data Saved to File";
   }
};

int main(){
  
  shoppingcart* s=new shoppingcart();
  s->addproducts("Mouse",200);
  s->addproducts("Keyboard",400);
  invoice* in=new invoice(s);
  
  // DBPersistance* db=new savetoMongo();
  // db->save(s);
  
  DBPersistance* db=new savetoSQL();
  db->save(s);
  
}
