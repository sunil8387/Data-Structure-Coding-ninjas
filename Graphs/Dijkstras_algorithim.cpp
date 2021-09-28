#include<iostream>
#include<climits>
using namespace std;

int FindMin(int *dist,bool*visited,int n){
  int MinVertex=-1;
  for(int i=0;i<n;i++){
    if(!visited[i] && (MinVertex==-1 ||dist[i]<dist[MinVertex])){
      MinVertex=i;
    }
  }
  return MinVertex;
}


void DijkstrasAlgo(int** edges,int n) {
  bool*visited=new bool[n];
  int* dist=new int[n];
  for(int i=0;i<n;i++){
    visited[i]=false;
    dist[i]=INT_MAX;
  }
  dist[0]=0;
  for(int i=0;i<n;i++){
    int MinVertex=FindMin(dist,visited,n);
    visited[MinVertex]=true;

    for(int j=0;j<n;j++){
      if(!visited[j]&& edges[MinVertex][j]!=0){
        int C_dist=dist[MinVertex]+edges[MinVertex][j];
        if(C_dist< dist[j]){
          dist[j]=C_dist;
        }
      }

    }
  }

  for(int i=0;i<n;i++){
    cout<<i<<" "<<dist[i]<<endl;
  }
  delete[] visited;
  delete[]dist;
}

int main(){

  int n,e;
  cin>>n>>e;
  int** edges=new int*[n];
  for(int i=0;i<n;i++){
    edges[i]=new int[n];
    for(int j=0;j<n;j++){
      edges[i][j]=0;
    }
  }

  for(int i=0;i<e;i++){
    int f,s,w;
    cin>>f>>s>>w;
    edges[f][s]=w;
    edges[s][f]=w;
  }
  DijkstrasAlgo(edges,n);

  for(int i=0;i<n;i++){
    delete[]edges[i];
  }
  delete [] edges;

  return 0;
}
