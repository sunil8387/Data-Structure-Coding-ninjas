/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
*/

#include<iostream>
using namespace std;
#include<cmath>

int count_of_bt1(int n){
  if(n<=1){
    return 1;
  }
  int mod=(int) (pow(10,9)) +7;
  int x=count_of_bt1(n-1);
  int y=count_of_bt1(n-2);

  int x1=(int) ( ( (long)(x) *x) % mod);
  int y1=(int) ( (2* (long)(x) *y) % mod);
  int ans= ((x1+y1)%mod);

  return ans;
}

int helper(int n,int* ans){
  if(n<=1){
    return 1;
  }
  if(ans[n]!=-1){
    return ans[n];
  }

  int x=helper(n-1,ans);
  int y=helper(n-2,ans);
  ans[n]=(x*x)+(2*(x*y));
  return ans[n];
}
int count_of_bt2(int n){
  int*ans=new int[n+1];
  for(int i=0;i<n+1;i++){
    ans[i]=-1;
  }
  return helper(n,ans);
}

int count_of_bt3(int n){
  int ans[n+1];
  ans[0]=ans[1]=1;
  for(int i=2;i<=n;i++){
    int x=ans[i-1];
    int y=ans[i-2];
    ans[i]= (x*x)+(2*(x*y));
  }
  return ans[n];
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  cout<<count_of_bt1(n)<<" "<<count_of_bt2(n)<<" "<<count_of_bt3(n)<<endl;
  return 0;
}
