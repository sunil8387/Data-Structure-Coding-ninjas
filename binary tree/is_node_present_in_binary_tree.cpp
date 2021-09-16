#include <iostream>
#include<queue>
using namespace std;
template <typename T>
class binarytreenode{
    public:
    T data;
    binarytreenode* left;
    binarytreenode* right;

    binarytreenode (T d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

binarytreenode<int>* take_input_level_wise(){
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    binarytreenode<int>* root= new binarytreenode<int>(rootdata);
    queue<binarytreenode<int>*> pending;
    pending.push(root);
    while (pending.size()!=0){
        binarytreenode<int>* front = pending.front();
        pending.pop();
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
           binarytreenode<int>* leftnode= new binarytreenode<int>(leftchild);
           front->left= leftnode;
           pending.push(leftnode);
        }
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
           binarytreenode<int>* rightnode= new binarytreenode<int>(rightchild);
           front->right= rightnode;
           pending.push(rightnode);
        }
    }
    return root;
}

bool is_present (binarytreenode<int>* root,int x){
  //check if x is present at root->data
  // if yes then return true
  // otherwise make a recursive call on root's left and right children
  // if x is not found after making recusive call then return false
    if(root==NULL){
        return NULL;
    }
    if(root->data==x){
        return true;
    }
    if(is_present(root->left,x)){
        return true;
    }
    if(is_present (root->right,x)){
        return true;
    }
    return false;
}

int main() {
    binarytreenode<int>* root=take_input_level_wise();
    int x;
    cin>>x;
    if(is_present(root,x)){
      cout << "true" << endl;
    }
    else{
      cout<<"false"<<endl;
    }

    return 0;
}
