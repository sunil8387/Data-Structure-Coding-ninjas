//A thief wants to loot houses. He knows the amount of money in each house.
//He cannot loot two consecutive houses. Find the maximum amount of money he can loot.


#include<iostream>
using namespace std;

//Brute force
int max_sum(int a[],int n,int s){
  if(n<=s){
    return 0;
  }
  return max(max_sum(a,n,s+2)+a[s],max_sum(a,n,s+1));
}

//Dynamic Programming
int max_sum1(int a[],int n){
  int ans[n+1];
  ans[0]=a[0];
  ans[1]=max(a[0],a[1]);
  for(int i=2;i<=n;i++){
    ans[i]=max(a[i]+ans[i-2],ans[i-1]);
  }
  return ans[n];
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int a[10000];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cout<<max_sum(a,n,0)<<" "<<max_sum1(a,n);
  return 0;
}
