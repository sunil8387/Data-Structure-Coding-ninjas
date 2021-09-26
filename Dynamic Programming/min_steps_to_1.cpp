/*
Given a positive integer 'n',  find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
*/

#include<iostream>
#include<climits>
using namespace std;

//Brute froce approach
int min1(int n){
  if(n==1){
    return 0;
  }
  int a=min1(n-1);
  int b=INT_MAX,c=INT_MAX;
  if(n%2==0){
    b=min1(n/2);
  }
  if(n%3==0){
    c=min1(n/3);
  }
  return 1+min(a,min(b,c));
}

//Memoization
int min2helper(int n,int* ans){
  if(n==1){
    return 0;
  }

  if(ans[n]!=-1){
    return ans[n];
  }
  int a=min2helper(n-1,ans);
  int b=INT_MAX,c=INT_MAX;
  if(n%2==0){
    b=min2helper(n/2,ans);
  }
  if(n%3==0){
    c=min2helper(n/3,ans);
  }

  ans[n]=1+min(a,min(b,c));
  return ans[n];

}

int min2(int n){
  int*ans=new int[n+1];
  for(int i=0;i<n+1;i++){
    ans[i]=-1;
  }
  return min2helper(n,ans);
}

//dynamic programming
int min3(int n){
  int ans[n+1];
  ans[1]=0;
  for(int i=2;i<=n;i++){
    int a=ans[i-1];
    int b=INT_MAX,c=INT_MAX;
    if(i%2==0){
      b=ans[i/2];
    }
    if(i%3==0){
      c=ans[i/3];
    }
    ans[i]=1+min(a,min(b,c));
  }
  return ans[n];
}



int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  cout<<min1(n)<<" "<<min2(n)<<" "<<min3(n);
  return 0;
}
