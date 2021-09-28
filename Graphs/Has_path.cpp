#include<iostream>
using namespace std;

bool HasPath(int **edges,int n,int a,int b,bool* visited){
  if(a==b){
    return true;
  }
  visited[a]=true;
  for(int i=0;i<n;i++){
    if(i==a){
      continue;
    }
    if(edges[a][i]==1&& !visited[i]){
      bool find=HasPath(edges,n,i,b,visited);
      if(find){
        return true;
      }
    }
  }
  return false;
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
    edges[f][s]=1;
    edges[s][f]=1;
  }
  bool*visited=new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i]=false;
  }
  int a,b;
  cin>>a>>b;
  if(HasPath(edges,n,a,b,visited)){
    cout<<"true";
  }
  else{
    cout<<"false";
  }
  delete []visited;
  for(int i=0;i<n;i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
