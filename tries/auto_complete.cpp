/*
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.
*/
#include<iostream>
#include <string>
using namespace std;

class Trienode{
public:
  char data;
  Trienode** children;;
  bool isTerminal;
  int child_count;
  Trienode(char data){
    this->data=data;
    children=new Trienode*[26];
    for(int i=0;i<26;i++){
      children[i]=NULL;
    }
    isTerminal=false;
    child_count=0;
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
      root->child_count++;

    }
    //Recursive call
    insertWord(child,word.substr(1));


  }
  void insertWord(string word){
    insertWord(root,word);
    return;
  }


  bool search(Trienode*root,string word){
    //base case
    if(word.size()==0){
      return root->isTerminal;
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

  Trienode* find_word(Trienode*root,string word){
    if(word.size()==0){
      return root;
    }
    Trienode* child=root;
    int index;
    int i=0;
    while(i<word.size()){
      index=word[i]-'a';
      if(child->children[index]!=NULL){
        child=child->children[index];
        i++;
      }
      else{
        return NULL;
      }
    }
    return child;
  }

  void all_possible(Trienode*root,string word,string output){
    if(root->isTerminal==true){
      cout<<word+output<<endl;
    }
    if(root->child_count==0){
      return;
    }
    for(int i=0;i<26;i++){
      if(root->children[i]!=NULL){
        string ans =output+root->children[i]->data;
        all_possible(root->children[i],word,ans);
      }
    }
    return;
  }


  void auto_complete(string word){

    Trienode* r=find_word(root,word);
    string output="";
    all_possible(r,word,output);
  }

};


int main(){
  trie t;
  t.insertWord("are");
  t.insertWord("ben");
  t.insertWord("no");
  t.insertWord("note");
  t.insertWord("node");
  t.insertWord("notes");
  t.insertWord("need");

  if(t.search("are")){
    cout<<"true";

  }
  else{
    cout<<"false";
  }
  if(t.search("ar")){
    cout<<"true";

  }
  else{
    cout<<"false";
  }
  cout<<endl;
  t.auto_complete("no");


  return 0;
}
