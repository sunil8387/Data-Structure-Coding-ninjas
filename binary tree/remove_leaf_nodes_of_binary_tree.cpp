//Remove all leaf nodes from a given Binary Tree. Leaf nodes are those nodes, which don't have any children.
//Note : Root will also be a leaf node if it doesn't have left and right child. You don't need to print the tree, just remove all leaf nodes and return the updated root.

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

void print_level_order(binarytreenode<int>* root){
    if(root==NULL){
        return;
    }
    binarytreenode<int>* nn= new binarytreenode<int>(0);
    queue<binarytreenode<int>*> pending;
    pending.push(root);
    pending.push(nn);
    while(pending.size()!=0){
        binarytreenode<int>* front= pending.front();
        pending.pop();
        if(front->data!=0){
            cout<<front->data<<" ";
        }

       if(front->data==0){
            if(pending.size()==0){
                break;
            }
            cout<<endl;
            pending.push(nn);
        }
        if(front->left!=NULL){
            pending.push(front->left);
        }
        if(front->right!=NULL){
            pending.push(front->right);
        }
    }
    return;
}

binarytreenode<int>* remove_leaf(binarytreenode<int>*& root){
    if(root==NULL){
        return NULL ;
    }
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL ;
    }
    root->left=remove_leaf(root->left);
    root->right=remove_leaf(root->right);
    return root;
}

int main() {
    binarytreenode<int>* root=take_input_level_wise();
    root=remove_leaf(root);
    print_level_order(root);


    return 0;
}
