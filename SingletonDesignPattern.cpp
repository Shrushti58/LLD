//Singleton ensures that a class has only one object and provides a global access point to it.

#include <bits/stdc++.h>
using namespace std;

class singleton{
  private:
    static singleton* instance;
    singleton(){
      cout<<"Constructor Called"<<endl;
    }
    
  public:
    static singleton* getinstance(){
      if(instance==nullptr){
        instance=new singleton();
      }
      return instance;
    }
};

singleton* singleton::instance=nullptr;
int main(){
  
  singleton* s1=singleton::getinstance();
  singleton* s2=singleton::getinstance();
  cout<<(s1==s2);
  
}
