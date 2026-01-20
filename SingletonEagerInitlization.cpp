//Singleton Design Pattern with Eager Initilization

#include <bits/stdc++.h>
#include<mutex>
using namespace std;

class singleton{
  private:
    static singleton* instance;
    singleton(){
      cout<<"Constructor Called"<<endl;
    }
    
  public:
    static singleton* getinstance(){
      return instance;
    }
};

singleton* singleton::instance=new singleton();
int main(){
  
  singleton* s1=singleton::getinstance();
  singleton* s2=singleton::getinstance();
  cout<<(s1==s2);
  
}
