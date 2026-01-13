//SRP : Solid Responsiblity Principle it states that one class or object should only posses single responsiblity if it posses one or more function then it becomes difficult to handle the code as changing one function can affect others.
//Always Remember- One class only one Function.
//In below eg if shopping cart involes all funcs like calculating total,printing invoice,saving data to DB then it voilates SRP so we create different classes for every func and pass object of shopping cart as reference.

#include <bits/stdc++.h>
using namespace std;

class product{
  public:
  string name;
  int price;
  public:
  product(string n,int p){
    name=n;
    price=p;
  }
};

class shoppingcart{
  
  public:
  int totalprice;
  vector<product*>products;
  public:
  
  void addproducts(string n,int p){
    product* newproduct=new product(n,p);
    products.push_back(newproduct);
  }
  
  void getproducts(){
    for(auto it:products){
      cout<<it->name<<":"<<it->price<<endl;
    }
  }
  
  int calctotal(){
    for(auto it:products){
      totalprice+=it->price;
    }
    cout<<"Total Price is :"<<totalprice<<endl;
    return totalprice;
  }
  
};

class cartinvoice{
  public:
  shoppingcart* cart;
  cartinvoice(shoppingcart* s){
    cart=s;
  }
  void printinvoice(){
    for(auto it:cart->products){
      cout<<it->name<<":"<<it->price<<endl;
    }
    cout << "Total Price : " << cart->calctotal() << endl;
    
  }
};

int main(){
  shoppingcart* s=new shoppingcart();
  s->addproducts("Mouse",200);
  s->addproducts("KeyBoard",400);
  s->getproducts();
  s->calctotal();
  cartinvoice printer(s);
  printer.printinvoice();
  
 
  return 0;
}

