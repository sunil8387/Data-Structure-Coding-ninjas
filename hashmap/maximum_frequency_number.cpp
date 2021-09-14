#include<iostream>
#include<unordered_map>
#include <climits>
using namespace std;

int max_ocurring(int*a,int n){
  unordered_map<int,int> m;
  for(int i=0;i<n;i++){
    m[a[i]]++;
  }
  int max=INT_MIN,ans;
  pair<int,int>p;
  for(int i=0;i<m.size();i++){
    p.first=i;
    p.second=m[i];
    if(p.second > max){
      max=p.second;
      ans=p.first;
    }
  }
  return ans;
}


int main(int argc, char const *argv[]) {
  int a[]={1,2,3,4,2,2,4,2,3,1,35,54,43};
  cout<<max_ocurring(a,13);
  return 0;
}
