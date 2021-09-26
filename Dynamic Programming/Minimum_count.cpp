//Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

#include<iostream>
#include<climits>
using namespace std;
//Brute force
int min_count1(int n){
  if(n<=3){
    return n;
  }
  int minimum=INT_MAX;
  for(int i=1;(i*i)<=n;i++){
    if((i*i)==n){
      return 1;
    }
    int h=1+min_count1(n-(i*i));
    if(h<minimum){
      minimum=h;
    }
  }
  return minimum;
}

//Memozisation

int min_count2_helper(int n,int*ans){
  if(n<=3){
    return n;
  }
  if(ans[n]!=-1){
    return ans[n];
  }
  int minimum=INT_MAX;
  for(int i=1;(i*i)<=n;i++){
    if((i*i)==n){
      ans[n]=1;
      return ans[n];
    }
    int h=1+min_count2_helper(n-(i*i),ans);
    if(h<minimum){
      minimum=h;
    }
  }
  ans[n]= minimum;
  return ans[n];

}

//Dynamic Programming
int min_count3(int n){
  int ans[n+1];
  ans[0]=0;
  ans[1]=1;
  ans[2]=2;
  ans[3]=3;

  int minimum=INT_MAX;
  for(int j=4;j<=n;j++){
    ans[j]=j;
    for(int i=1;(i*i)<=j;i++){
      if((i*i)==j){
        ans[j]=1;
        break;
      }
      ans[j]=min(1+ans[j-(i*i)],ans[j]);
    }
  }

  return ans[n];
}


int min_count2(int n){
  int *ans=new int[n+1];
  for(int i=0;i<=n;i++){
    ans[i]=-1;
  }
  return min_count2_helper(n,ans);
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  cout<<min_count1(n)<<" "<<min_count2(n)<<" "<<min_count3(n)<<endl;
  return 0;
}
