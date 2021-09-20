//Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
//The function should return either true or false. You don't have to print anything.

#include<iostream>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

class Trienode{
public:
  char data;
  Trienode** children;;
  bool isTerminal;
  Trienode(char data){
    this->data=data;
    children=new Trienode*[26];
    for(int i=0;i<26;i++){
      children[i]=NULL;
    }
    isTerminal=false;
  }
};

class trie{
  Trienode* root;
public:
  trie(){
    root=new Trienode('\0');
  }
  void insertWord(Trienode*root,string word){
    //base case
    if(word.size()==0){
      root->isTerminal=true;
      return ;
    }

    // calculation on root
    //finding index of first letter of given word
    int index=word[0]-'a';
    Trienode* child;
    // if letter is present then store its address in child
    //else create new Trienode with that letter
    if(root->children[index]!=NULL){
      child=root->children[index];
    }
    else{
      child=new Trienode(word[0]);
      root->children[index]=child;

    }
    //Recursive call
    insertWord(child,word.substr(1));

  }
  void insertWord(string word){
    insertWord(root,word);
    return;
  }

  bool palindrome(){
    int n;
    bool find=false;
    unordered_map<string,int>m;
    string s;
    cin>>n;
    // take string input from user and insert it in trie and hashmap and mantian a boolen variable
    // after that reverse that string and check if reverse string is present in haspmap or not
    // if it is present then make boolen variable as true and at the end return that variable
    for(int i=1;i<=n;i++){
      cin>>s;
      insertWord(s);
      m[s]++;
      reverse(s.begin(),s.end());
      if(m.count(s)>0){
        find=true;
      }
    }
    return find;
  }


};


int main(){
  trie t;
  cout<<t.palindrome();
  return 0;
}
