/*You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
*/

#include<iostream>
#include<climits>
#include<string>
using namespace std;
//Brute force
int EditDistance1(string s,string t){
  if(s.length()==0||t.length()==0){
    return max(s.length(),t.length());
  }
  if(s[0]==t[0]){
    return EditDistance1(s.substr(1),t.substr(1));
  }
  else{
    int ins=1+EditDistance1(s.substr(1),t);
    int del=1+EditDistance1(s,t.substr(1));
    int rep=1+EditDistance1(s.substr(1),t.substr(1));
    return min(ins,min(del,rep));
  }

}

//Memoization

int helper(string s,string t,int**a){
  if(s.length()==0||t.length()==0){
    return max(s.length(),t.length());
  }
  if(s[0]==t[0]){
    a[s.length()][t.length()]= helper(s.substr(1),t.substr(1),a);
    return a[s.length()][t.length()];
  }
  else{
    int ins=1+helper(s.substr(1),t,a);
    int del=1+helper(s,t.substr(1),a);
    int rep=1+helper(s.substr(1),t.substr(1),a);
    a[s.length()][t.length()]=min(ins,min(del,rep));
    return a[s.length()][t.length()];
  }
}

int EditDistance2(string s,string t){
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
int EditDistance3(string s,string t){
  int n=s.length();
  int m=t.length();
  int a[n+1][m+1];
  a[0][0]=0;
  for(int i=0;i<=n;i++){
    a[i][0]=i;
  }
  for(int i=0;i<=m;i++){
    a[0][i]=i;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s[n-i]==t[m-j]){
        a[i][j]=a[i-1][j-1];
      }
      else{
        int ins=1+a[i-1][j];
        int del=1+a[i][j-1];
        int rep=1+a[i-1][j-1];
        a[i][j]=min(ins,min(del,rep));
      }
    }
  }
  return a[n][m];
}

int main(int argc, char const *argv[]) {
  string s,t;
  cin>>s>>t;
  cout<<EditDistance1(s,t)<<" "<<EditDistance2(s,t)<<" "<<EditDistance3(s,t)<<endl;

  return 0;
}
