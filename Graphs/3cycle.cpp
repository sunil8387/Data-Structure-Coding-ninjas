#include<iostream>
using namespace std;

int GetCount(int** edges,int n){
  int i=0,count =0;
  while(i<n){
    int j=0;
    while (j<n) {
      if(edges[i][j]==1){
        int k=0;
        while(k<n){
          if(edges[j][k]==1){
            if(edges[i][k]==1){
              count++;
            }
          }
          k++;
        }
      }
      j++;
    }
    i++;
  }
  return count/6;
}

int main() {
  int n,e;
  cin>>n>>e;
  int** edges=new int*[n];
  for(int i=0;i<n;i++){
    edges[i]=new int [n];
    for(int j=0;j<n;j++){
      edges[i][j]=0;
    }
  }
  for(int i=0;i<e;i++){
    int f,s;
    cin>>f>>s;
    edges[s][f]=1;
    edges[f][s]=1;
  }
  cout<<GetCount(edges,n);
  for(int i=0;i<n;i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
