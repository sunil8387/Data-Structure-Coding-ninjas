//Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order.


#include<iostream>
using namespace std;

// using dynamic programning
int lcs(int a[],int n){
  int ans[n];
  int count=1;
  ans[0]=1;
  for(int i=1;i<n;i++){
    ans[i]=1;
    for(int j=i-1;j>=0;j--){
      if(a[j]<a[i] && ans[i]<ans[j]+1){
        ans[i]=ans[j]+1;
        if(count<ans[i]){
            count=ans[i];
        }
      }
    }
  }
  return count;
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cout<<lcs(a,n)<<" "<<endl;
}
