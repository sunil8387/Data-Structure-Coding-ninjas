#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> remove_duplicate(int*a,int n){
  vector<int> v;
  unordered_map<int,bool> seen;
  for(int i=0;i<n;i++){
    if(seen.count(a[i])>0){
      continue;
    }
    seen[a[i]]=true;
    v.push_back(a[i]);
  }
  return v;
}

int main(){
  int a[]={2,6,1,2,5};
  vector<int> output=remove_duplicate(a,5);
  for (int i = 0; i <output.size(); i++) {
    cout<<output[i]<<" ";
  }

  return 0;
}
