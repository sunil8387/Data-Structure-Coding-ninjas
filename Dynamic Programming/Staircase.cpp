/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time.
//Implement a method to count and return all possible ways in which the child can run-up to the stairs.
*/

#include<iostream>
using namespace std;

//Brute force
int count_steps1(int n){
  if(n<=1){
    return 1;
  }
  if(n==2){
    return 2;
  }
  return count_steps1(n-1)+count_steps1(n-2)+count_steps1(n-3);
}

//Memoization
int count_steps2_helper(int n,int* ans){
  if(n<=1){
    return 1;
  }
  if(n==2){
    return 2;
  }
  if(ans[n]!=-1){
    return ans[n];
  }
  ans[n]= count_steps2_helper(n-1,ans)+count_steps2_helper(n-2,ans)+count_steps2_helper(n-3,ans);
  return ans[n];
}


int count_steps2(int n){
  int *ans=new int[n+1];
  for(int i=0;i<=n;i++){
    ans[i]=-1;
  }
  return count_steps2_helper(n,ans);
}

//Dynamic Programing
int count_steps3(int n){

  int ans[n+1];
  ans[0]=ans[1]=1;
  ans[2]=2;
  for(int i=3;i<=n;i++){
    ans[i]=ans[i-3]+ans[i-2]+ans[i-1];
  }
  return ans[n];
}


int main(){
  int n;
  cin>>n;
  cout<<count_steps1(n)<<" "<<count_steps2(n)<<" "<<count_steps3(n)<<endl;
  return 0;
}
