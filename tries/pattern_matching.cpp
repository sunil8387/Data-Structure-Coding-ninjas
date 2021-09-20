//Given a  list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not.
//Return true if the pattern is present and false otherwise.
#include<iostream>
#include <string>
using namespace std;

class Trienode{
public:
  char data;
  Trienode** children;;
  Trienode(char data){
    this->data=data;
    children=new Trienode*[26];
    for(int i=0;i<26;i++){
      children[i]=NULL;
    }
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
      return ;
    }
    string ans="";
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
    ans=ans+root->children[index]->data;

  }
  void insertWord(string word){
    insertWord(root,word);
    for (int i = 0; i < word.size(); i++) {
      insertWord(root,word.substr(i));
    }
    return;
  }


  bool search(Trienode*root,string word){
    //base case
    if(word.size()==0){
      return true;
    }

    int index=word[0]-'a';
    Trienode*child;
    if(root->children[index]!=NULL){
      child=root->children[index];
      return search(child,word.substr(1));
    }
    else{
      return false;
    }

  }
  bool search(string word){
    return search(root,word);
  }


};


int main(){
  trie t;
  t.insertWord("are");
  t.insertWord("ben");
  t.insertWord("a");
  t.insertWord("bet");

  cout<<t.search("are")<<endl;
  cout<<t.search("ar")<<endl;
  cout<<t.search("re")<<endl;
  cout<<t.search("e")<<endl;
  cout<<t.search("et")<<endl;
  cout<<t.search("b")<<endl;



  return 0;
}
