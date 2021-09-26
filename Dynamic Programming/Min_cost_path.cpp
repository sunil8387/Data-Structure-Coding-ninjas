/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i,  j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"

The cost of a path is defined as the sum of each cell's values through which the route passes.
*/
#include<iostream>
#include<climits>
using namespace std;

//Brute Approach
int minCostPath1(int ** a,int row,int col,int s,int e){
    if(s==row&&e==col){
        return a[s][e];
    }
    if(s>row||e>col){
        return INT_MAX;
    }

       int  down=minCostPath1(a,row,col,s+1,e);
       int  diag=minCostPath1(a,row,col,s+1,e+1);
       int  hori=minCostPath1(a,row,col,s,e+1);

    int ans=a[s][e]+min(down,min(diag,hori));
    return ans;
}
//Memoization
int helper(int **a,int row ,int col,int s,int e, int**ans){
    if(s==row&&e==col){
        return a[s][e];
    }
    if(s>row||e>col){
        return INT_MAX;
    }
    if(ans[s][e]!=-1){
        return ans[s][e];
    }
    int down=helper(a,row,col,s+1,e,ans);
    int diag=helper(a,row, col,s+1,e+1,ans);
    int hori=helper(a,row,col,s,e+1,ans);
    ans[s][e]=min(down,min(diag,hori))+a[s][e];
    return ans[s][e];
}

int minCostPath2(int **input, int n, int m) {
    int** ans=new int*[n];
    for(int i=0;i<n;i++){
        ans[i]=new int [m];
        for(int j=0;j<m;j++){
            ans[i][j]=-1;
        }
    }
    return helper(input,n-1,m-1,0,0,ans);
}


//Dynamic Programming
int minCostPath3(int **a, int n, int m) {
    int ans[n][m];
    //Fill last cell
    ans[n-1][m-1]=a[n-1][m-1];
    //Fill last row
    for(int i=m-2;i>=0;i--){
        ans[n-1][i]= ans[n-1][i+1]+a[n-1][i];
    }
    //Fill last col
    for(int i=n-2;i>=0;i--){
        ans[i][m-1]=ans[i+1][m-1]+a[i][m-1];
    }
    // Fill remaining cell
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            ans[i][j]=a[i][j]+min(ans[i+1][j+1],min(ans[i+1][j],ans[i][j+1]));
        }
    }
    return ans[0][0];

}

int main(int argc, char const *argv[]) {
  int n,m;
  cin>>n>>m;

  int** a=new int*[n];
  for(int i=0;i<n;i++){
    a[i]=new int[m];
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }

  cout<<minCostPath1(a,n-1,m-1,0,0)<<" "<<minCostPath2(a,n,m)<<" "<<minCostPath3(a,n,m)<<endl;
  return 0;
}
