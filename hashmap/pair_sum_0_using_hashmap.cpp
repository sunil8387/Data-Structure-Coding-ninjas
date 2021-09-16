#include <iostream>
#include<unordered_map>
using namespace std;

int pair_sum_to_0(int*a,int n){
  unordered_map<int,int> m;
  for(int i=0;i<n;i++){
    m[a[i]]++;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(m.count(-(a[i]))>0){
      ans+=(m[a[i]]*m[-a[i]]);
      m[-(a[i])]--;
      m[(a[i])]--;
    }
  }
  return ans;
}

int main(){
  int a[]={2,1,-2,2,3};
  cout<<pair_sum_to_0(a,5);
  return 0;
}
