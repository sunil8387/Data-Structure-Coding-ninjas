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
      ans++;
      m[-(a[i])]--;
      m[(a[i])]--;
      if(m[-(a[i])]==0){
        m.erase(-(a[i]));
      }
      if(m[(a[i])]==0){
        m.erase((a[i]));
      }
    }
  }
  return ans;
}

int main(){
  int a[]={1,2,-5,67,-1,3,4,-4,5};
  cout<<pair_sum_to_0(a,9);
  return 0;
}
