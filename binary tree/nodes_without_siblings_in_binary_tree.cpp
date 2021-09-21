//For a given Binary Tree of type integer, print all the nodes without any siblings.

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

void print_sibling(binarytreenode<int>* root){
    if(root==NULL){
        return ;
    }
    if(root->left!=NULL && root->right==NULL){
        cout<<root->left->data<<" ";
    }
    if(root->left==NULL&& root->right!=NULL){
        cout<<root->right->data<<" ";
        print_sibling(root->right);
    }
    print_sibling(root->left);
    print_sibling(root->right);
    return ;

}

int main() {
    binarytreenode<int>* root=take_input_level_wise();
    print_sibling(root);


    return 0;
}
