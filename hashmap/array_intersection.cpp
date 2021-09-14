#include<iostream>
#include<unordered_map>
using namespace std;

void intersection(int*a,int n,int*b,int m){
  unordered_map<int,int> m1;
  for(int i=0;i<n;i++){
    m1[a[i]]++;     //first we store a1 array in map
  }
  for(int i=0;i<m;i++){
    if(m1.count(b[i])>0){    //then we check if b1 array is present in map or not
      cout<<b[i]<<" ";   // if yes then we will print that element and dec its count from map
      m1[b[i]]--;
      if(m1[b[i]]==0){  // if the count become 0 then we will remove the element from map
        m1.erase(b[i]);
      }
    }
  }
  return;
}

int main(){

  int a[]={1,2,3,4,43,7,3};
  int b[]={34,45,1,3,7,3};
  intersection(a,7,b,6);


  return 0;
}
