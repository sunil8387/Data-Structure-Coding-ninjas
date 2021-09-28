#include<iostream>
#include<vector>
using namespace std;

void all_connected(int**edges,int n,int s,bool* visited,vector<int>&ans){
  ans.push_back(s);
  visited[s]=true;
  for(int i=0;i<n;i++){
    if(i==s){
      continue;
    }
    if(edges[s][i]==1 && !visited[i]){
      all_connected(edges,n,i,visited,ans);
    }
  }
  return;
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
  for(int i=0;i<n;i++){
    if(!visited[i]){
      vector<int> v;
      all_connected(edges,n,i,visited,v);
      for(auto it:v){
        cout<<it<<" ";
      }
      cout<<endl;
    }
  }

  delete []visited;
  for(int i=0;i<n;i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
