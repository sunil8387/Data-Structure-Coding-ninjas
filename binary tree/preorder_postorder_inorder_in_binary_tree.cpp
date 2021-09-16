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


 void preorder(binarytreenode<int>* root){
   // base case: if root =NULL return
    if(root==NULL){
        return;
    }
    //first print root's data and then first make a recursive call on root's
    // and then on root 's right
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(binarytreenode<int>* root){
  // base case: if root =NULL return
    if(root==NULL){
        return;
    }
    // first print the value at root's left and then  the value at root's right
    // and at last root data
    postorder(root->left);
    postorder (root->right);
    cout<<root->data<<" ";
}
 void inorder(binarytreenode<int>* root){
   // base case: if root =NULL return
    if(root==NULL){
        return;
    }
    // first print the value at root's left and then root data
    //and at last the value at root's right data
    inorder(root->left);
    cout<<root->data<<" ";
    inorder (root->right);
}

int main() {

    binarytreenode<int>* root=take_input_level_wise();
    cout<<"preorder: ";
    preorder(root);
    cout<<endl<<"postorder:";
    postorder(root);
    cout<<endl<<"inorder: ";
    inorder(root);
    cout<<endl;


    return 0;
}
