#include <bits/stdc++.h>
using namespace std;

class documentElement{
  public:
    virtual string render()=0;
};

class txtElement:public documentElement{
  
  private:
    string txt;
  
  public:
  
    txtElement(string t){
      txt=t;
    }
    
    string render(){
      return txt;
    }
    
};

class imageElement:public documentElement{
  
  private:
    string path;
    
  public:
    imageElement(string p){
      path=p;
    }
    
    string render(){
      return path;
    }
};

class newLineElement:public documentElement{
  
  public:
    string render(){
      return "\n";
    }
};

class document{
  private:
    vector<documentElement*>documents;
    
  public:
    void addElement(documentElement* d){
      documents.push_back(d);
    }
    
    string renderResult(){
      string result;
      
      for(auto it:documents){
        result+=it->render();
      }
      
      return result;
    }
};

class documentEditor{
  private:
    document* doc;
    string renderdoc;
  
  public:
    documentEditor(document* dobj){
      doc=dobj;
    }
    
    void addTextElement(string text){
      doc->addElement(new txtElement(text));
    }
    
    void addImgElement(string path){
      doc->addElement(new imageElement(path));
    }
    
    void addNewLine(){
      doc->addElement(new newLineElement());
    }
    
    string render(){
      renderdoc=doc->renderResult();
      return renderdoc;
    }
    
};

int main(){
  document* doc=new document();
  documentEditor* doceditor=new documentEditor(doc);
  
  doceditor->addTextElement("Hello Shrushti");
  doceditor->addNewLine();
  doceditor->addImgElement("bjhgy.jpg");
  cout<<doceditor->render();
  
}
