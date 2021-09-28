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

int no_of_island(int**edges,int n,bool*visited){
  int count=0;
  for(int i=0;i<n;i++){
    if( !visited[i]){
      Traversal(edges,n,i,visited);
      count++;
    }
  }
  return count;
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

  cout<<no_of_island(edges,n,visited);
  delete []visited;
  for(int i=0;i<n;i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
