#include<iostream>
#include<algorithm>
using namespace std;

class edge{
public:
  int first;
  int second;
  int weight;
};

bool compare(edge e1,edge e2){
  return e1.weight < e2.weight;
}

int findParent(int v,int*parent){
  if(parent[v]==v){
    return v;
  }
  return findParent(parent[v],parent);
}

bool cycleDectation(int v1,int v2,int *parent){
  int Pv1=findParent(v1,parent);
  int Pv2=findParent(v2,parent);

  if(Pv1==Pv2){
    return true;
  }
  else{
    parent[Pv1]=parent[Pv2];
    return false;
  }
}

void KruskalsAlgo(int n,int e,edge input[]){
  sort(input,input+e,compare);
  int* parent=new int[n];
  for(int i=0;i<n;i++){
    parent[i]=i;
  }
  edge output[n-1];
  int count=0,i=0;
  while(count!=n-1){
    bool check=cycleDectation(input[i].first,input[i].second,parent);
    if(!check){
      output[count].first=input[i].first;
      output[count].second=input[i].second;
      output[count].weight=input[i].weight;
      count++;
    }
    i++;
  }
  for(int i=0;i<n-1;i++){
    cout<<output[i].first<<" "<<output[i].second<<" "<<output[i].weight<<endl;
  }
  delete []parent;
  return ;
}


int main(int argc, char const *argv[]) {
  int n,e;
  cin>>n>>e;
  edge input[e];
  for(int i=0;i<e;i++){
    int f,s,w;
    cin>>f>>s>>w;
    input[i].first=f;
    input[i].second=s;
    input[i].weight=w;
  }

  KruskalsAlgo(n,e,input);

  return 0;
}
