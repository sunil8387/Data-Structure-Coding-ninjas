//Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1.
//Return true if given binary tree is balanced, false otherwise.

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

int level(binarytreenode<int>*root){
    if(root==NULL){
        return 0;
    }
    int l=level(root->left);
    int r=level(root->right);
    return 1+max(l,r);
}

bool balanced(binarytreenode<int>* root){
    if(root==NULL){
        return true;
    }
    int ld=level(root->left);
    int rd=level(root->right);
    int diff=abs(ld-rd);
    if (diff>1){
        return false;
    }
    else{
        bool l= balanced(root->left);
        bool r= balanced(root->right);
        return l&r;
    }
}

int main() {
    binarytreenode<int>* root=take_input_level_wise();

    if(balanced(root)){
      cout<<"true";
    }
    else{
      cout<<"false";
    }
    return 0;
}
