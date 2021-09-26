//Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns.
//Beerus plays first. In one step, the player can remove either 1,  X, or Y coins from the tower.
//The person to make the last move wins the game. Can you find out who wins the game?

#include<iostream>
#include<climits>
using namespace std;


void CoinTower(int n,int x,int y){
  int arr[n+1];
  arr[1]=1;
  arr[x]=1;
  arr[y]=1;

  for(int i=2;i<=n;i++){
    if(x==i||y==i){
      arr[i]=1;
    }
    else{
      int rem1=(arr[i-1])^1;
      int rem_x=INT_MIN,rem_y=INT_MIN;
      if(i-x>0){
        rem_x=(arr[i-x])^1;
      }
      if(i-y>0){
        rem_y=(arr[i-y])^1;
      }
      arr[i]=max(rem1,max(rem_x,rem_y));
    }

  }
  if(arr[n]==0){
    cout<<"Whis";
  }
  else{
    cout<<"Beerus";
  }
  return ;
}


int main(int argc, char const *argv[]) {
  int n,x,y;
  cin>>n>>x>>y;
  CoinTower(n,x,y);
  return 0;
}
