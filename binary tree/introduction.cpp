/*
1 2 3 4 5 6 -1 -1 -1 -1 -1 7 -1 -1 -1
*/
/* topic covered-
take input from user in preorder format
take input from user level wise
print tree in preorder format
print tree level wise
*/
#include <iostream>
#include<queue>
using namespace std;
template <typename T>
class binarytreenode{  // creating a class for implementing binary tree
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
    // create a queue to store value to take input their children
    queue<binarytreenode<int>*> pending;
    pending.push(root);  //push root to queue to take its children input
    while (pending.size()!=0){
      // create new binarytreenode and store value of first element of queue
      // pop that element out
        binarytreenode<int>* front = pending.front();
        pending.pop();
        int leftchild;
        cin>>leftchild;  // take left child value input from user
        if(leftchild!=-1){ // -1 indicates that it has no child
          //create a node with value provided by user and connect
          //that node to root's left side
           binarytreenode<int>* leftnode= new binarytreenode<int>(leftchild);
           front->left= leftnode;
           // push that element to queue to further take its child input
           pending.push(leftnode);
        }
        // repeat the same process with right child
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

binarytreenode<int>* take_input(){
  // take as input the value of root data and make recursive call on its child
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    binarytreenode<int>* root= new binarytreenode<int>(rootdata);
    root->left=take_input();
    root->right=take_input();
    return root;
}

void print(binarytreenode<int>*root){
  // print root data and make recursive call on its child if they exist
    if(root==NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left){
        cout<<"L"<<root->left->data;
    }
    if(root->right){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
void print_level_wise(binarytreenode<int>* root){
    //create queue and push root into it
    queue<binarytreenode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0){
      // create a new node and save the first element of queue in it
      // and then pop it from queue
        binarytreenode<int>* front=pending.front();
        pending.pop();
        // first print front->data and then its child data if they exist
        // add its child to queue
        cout<<front->data<<":";
        if(front->left){
            cout<<"L"<<front->left->data;
            pending.push(front->left);
        }
        if(front->right){
            cout<<"R"<<front->right->data;
            pending.push(front->right);
        }
        cout<<endl;
    }
}

int main() {
   binarytreenode<int>* root=take_input();
   print (root);
    binarytreenode<int>* root2=take_input_level_wise();
    print_level_wise(root2);


    return 0;
}
