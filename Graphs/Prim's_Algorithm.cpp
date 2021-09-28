#include<iostream>
#include<climits>
using namespace std;

int FindMin(int* weight,bool* visited,int n){
  int minIndex=-1;
  for(int i=0;i<n;i++){
    if(!visited[i] && (minIndex==-1 || weight[i]<weight[minIndex])){
      minIndex=i;
    }
  }
  return minIndex;
}

void PrimAlgo(int n,int e,int**edges){
  bool* visited=new bool[n];
  for(int i=0;i<n;i++){
    visited[i]=false;
  }

  int *weight=new int[n];
  int *parent=new int[n];
  for(int i=0;i<n;i++){
    weight[i]=INT_MAX;
  }
  for(int i=0;i<n;i++){
    parent[i]=-1;
  }
  int minIndex;
  parent[0]=-1;
  weight[0]=0;
  for(int i=0;i<n-1;i++){
    minIndex=FindMin(weight,visited,n);
    visited[minIndex]=true;
    for(int j=0;j<n;j++){
      if(edges[minIndex][j]!=0 &&!visited[j]){
        if(edges[minIndex][j]<weight[j]){
          parent[j]=minIndex;
          weight[j]=edges[minIndex][j];
        }
      }
    }
  }
  for(int i=1;i<n;i++){
    cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
  }

  delete[]visited;
  delete[]weight;
  delete[]parent;
  return;
}

int main(int argc, char const *argv[]) {
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
  PrimAlgo(n,e,edges);

  for(int i=0;i<n;i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
