#include<iostream>
#include<climits>
using namespace std;

int helper(int**cake,int n,int s,int e,bool** visited){
  // if(s>=n || e>=n){
  //   return 0;
  // }
  visited[s][e]=true;
  int count=0;
  if(s+1<n && !visited[s+1][e] && cake[s+1][e]==1){
    count+=(helper(cake,n,s+1,e,visited)+1);
  }
  if(e-1>=0 &&(!visited[s][e-1]) && cake[s][e-1]==1){
    count+=(helper(cake,n,s,e-1,visited)+1);
  }
  if(s-1>=0 &&(!visited[s-1][e]) && cake[s-1][e]==1){
    count+=(helper(cake,n,s-1,e,visited)+1);
  }
  if(e+1<n && !visited[s][e+1]&& cake[s][e+1]==1){
    count+=(helper(cake,n,s,e+1,visited)+1);
  }
  return count;
}

int LargestPiece(int ** cake,int n,bool**visited){
  int max=0;
  for(int i=0;i<n;i++){
    for(int j=0;i<n;i++){
      if(cake[i][j]==1&& !visited[i][j]){
        int piece=helper(cake,n,i,j,visited)+1;
        if((piece)> max){
          max=piece;
        }
      }
    }
  }
  return max;
}

int main() {
  int n;
  cin>>n;
  int** cake=new int*[n];
  for(int i=0;i<n;i++){
    cake[i]=new int [n];
    for(int j=0;j<n;j++){
      cin>>cake[i][j];
    }
  }
  bool** visited=new bool*[n];
  for(int i=0;i<n;i++){
    visited[i]=new bool[n];
    for(int j=0;j<n;j++){
      visited[i][j]=false;
    }
  }

  cout<<LargestPiece(cake,n,visited);
  for(int i=0;i<n;i++){
    delete []visited[i];
  }
  delete []visited;
  for(int i=0;i<n;i++){
    delete [] cake[i];
  }
  delete [] cake;
  return 0;
}
