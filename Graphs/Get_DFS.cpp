#include<iostream>
#include<vector>
using namespace std;

bool GetPathDFS(int** edges,int n,int a,int b,bool* visited,vector<int> &v){
  if(a==b){
    v.push_back(a);
    visited[a]=true;
    return true;
  }
  visited[a]=true;
  for(int i=0;i<n;i++){
    if(i==a){
      continue;
    }
    if(edges[a][i]==1&&!visited[i]){
      bool find=GetPathDFS(edges,n,i,b,visited,v);
      if(find){
        v.push_back(a);
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
    edges[s][f]=1;
    edges[f][s]=1;
  }
  bool* visited=new bool[n];
  for(int i=0;i<n;i++){
    visited[i]=false;
  }
  int a,b;
  cin>>a>>b;
  vector<int> v;
  if(GetPathDFS(edges,n,a,b,visited,v)){
    for(auto it: v){
      cout<<it<<" ";
    }
  }
  delete []visited;
  for(int i=0;i<n;i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
