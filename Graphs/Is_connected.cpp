#include<iostream>
using namespace std;

void Traversal(int **edges,int n,int sv,bool*visited){
  visited[sv]=true;
  for(int i=0;i<n;i++){
    if(i==sv){
      continue;
    }
    if(edges[sv][i]==1&& !visited[i]){
      Traversal(edges,n,i,visited);
    }
  }
  return;
}

bool check(int**edges,int n,bool*visited){
  for(int i=0;i<n;i++){
    if( !visited[i]){
      return false;
    }
  }
  return true;
}

bool IsConnected(int**edges,int n,bool*visited){
  Traversal(edges,n,0,visited);
  return check(edges,n,visited);
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
  bool* visited=new bool[n];
  for(int i=0;i<n;i++){
    visited[i]=false;
  }

  cout<<IsConnected(edges,n,visited);
  delete []visited;
  for(int i=0;i<n;i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
