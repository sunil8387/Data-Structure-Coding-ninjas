#include <iostream>
#include<unordered_map>
using namespace std;

int main(int argc, char const *argv[]) {
  unordered_map<string,int> m;
  //inserating element
  pair<string,int> s("abc",1);
  m.insert(s);
  //or
  m["xyz"]=2;
  // access/print
  cout<<m["abc"]<<endl;  //if the element is not present it insert that element and allocates value 0 to it
  cout<<m.at("xyz")<<endl;   // if the element is not present it gives error "element not present"
  cout<<"size:"<<m.size()<<endl;  // to determine size of map
  // check presence
  if(m.count("abc")>0){  // tells the count of element
    cout<<"element is present"<<endl; // count of any element can be 0 or 1
  }
  else{
    cout<<"element is not present"<<endl;
  }
  return 0;
}
