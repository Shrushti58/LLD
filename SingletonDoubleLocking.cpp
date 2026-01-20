//Singleton Design Pattern with Double Locking

#include <bits/stdc++.h>
#include<mutex>
using namespace std;

class singleton{
  private:
    static singleton* instance;
    static mutex mtx;
    singleton(){
      cout<<"Constructor Called"<<endl;
    }
    
  public:
    static singleton* getinstance(){
      if(instance==nullptr){
        lock_guard<mutex>lock(mtx);
        if(instance==nullptr){
          instance=new singleton();
        }
      }
      return instance;
    }
};

singleton* singleton::instance=nullptr;
mutex singleton::mtx;
int main(){
  
  singleton* s1=singleton::getinstance();
  singleton* s2=singleton::getinstance();
  cout<<(s1==s2);
  
}
