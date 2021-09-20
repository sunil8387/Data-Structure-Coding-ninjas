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

  void remove(Trienode* root,string word) {
    if(word.size()==0){
      root->isTerminal=false;
      return ;
    }

    int index=word[0]-'a';
    Trienode* child;
    if(root->children[index]!=NULL){
      child=root->children[index];
      remove(child,word.substr(1));
    }
    else{
      return;
    }

    if(child->isTerminal==false){
      for(int i=0;i<26;i++){
        if(child->children[i]!=NULL){
          return;
        }
      }
      delete child;
      root->children[index]=NULL;
    }

  }
  void remove (string word){
    remove (root,word);
  }

};


int main(){
  trie t;
  t.insertWord("are");
  t.insertWord("ben");
  t.insertWord("a");
  t.insertWord("bet");

  cout<<t.search("are")<<endl;
  t.remove("are");
  cout<<t.search("are")<<endl;

  return 0;
}
