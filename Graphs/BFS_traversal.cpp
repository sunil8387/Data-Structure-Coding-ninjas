#include<iostream>
#include<queue>
using namespace std;

void BFS_print(int **edges,int n,int sv,bool* visited){
  queue<int> pending;
  pending.push(sv);
  visited[sv]=true;
  while (pending.size()!=0) {
    int front=pending.front();
    pending.pop();
    cout<<front<<" ";
    for(int i=0;i<n;i++){
      if(i==front){
        continue;
      }
      if(edges[front][i]==1&& !visited[i]){
        pending.push(i);
        visited[i]=true;
      }
    }
  }
  return;
}

void BFS(int **edges,int n){
  bool*visited=new bool[n];
  for(int i=0;i<n;i++){
    visited[i]=false;
  }

  for(int i=0;i<n;i++){
    if(!visited[i]){
      BFS_print(edges,n,i,visited);
    }
  }
  delete []visited;
}

int main(int argc, char const *argv[]) {
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
  BFS(edges,n);
  for(int i=0;i<n;i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
