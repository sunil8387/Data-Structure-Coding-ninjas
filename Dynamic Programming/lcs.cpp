#include<iostream>
#include<climits>
#include<string>
using namespace std;

//Brute force
int lcs(string s,string t){
  if(s.length()==0||t.length()==0){
    return 0;
  }
  if(s[0]==t[0]){
    return 1+lcs(s.substr(1),t.substr(1));
  }
  else{
    int x=lcs(s.substr(1),t);
    int y=lcs(s,t.substr(1));
    int z=lcs(s.substr(1),t.substr(1));
    return max(x,max(y,z));
  }
}

//Memoization

int helper(string s,string t,int**ans){
  if(s.length()==0||t.length()==0){
    return 0;
  }
  int n=s.length();
  int m=t.length();
  if(ans[n][m]!=-1){
    return ans[n][m];
  }
  if(s[0]==t[0]){
    ans[n][m]=1+helper(s.substr(1),t.substr(1),ans);
    return ans[n][m];
  }
  else{
    int x=helper(s.substr(1),t,ans);
    int y=helper(s,t.substr(1),ans);
    int z=helper(s.substr(1),t.substr(1),ans);
    ans[n][m]=max(x,max(y,z));
    return ans[n][m];
  }
}
int lcs1(string s,string t){
  int **a=new int*[s.length()+1];
  for(int i=0;i<=s.length();i++){
    a[i]=new int[t.length()+1];
    for(int j=0;j<=t.length();j++){
      a[i][j]=-1;
    }
  }
  return helper(s,t,a);
}
//Dynamic programming
int lcs2(string s,string t){
  int a[s.length()+1][t.length()+1];
  for(int i=0;i<=s.length();i++){
    a[i][0]=0;
  }
  for(int i=0;i<=t.length();i++){
    a[0][i]=0;
  }
  //fill remaining cells
  for(int i=1;i<=s.length();i++){
    for(int j=1;j<=t.length();j++){
      if(s[s.length()-i]==t[t.length()-j]){
        a[i][j]=1+a[i-1][j-1];
      }
      else{
        int x=a[i-1][j];
        int y=a[i][j-1];
        int z=a[i-1][j-1];
        a[i][j]=max(x,max(y,z));
      }
    }
  }
  return a[s.length()][t.length()];
}

int main(int argc, char const *argv[]) {
  string s,t;
  cin>>s>>t;
  cout<<lcs(s,t)<<" "<<lcs1(s,t);
  return 0;
}
