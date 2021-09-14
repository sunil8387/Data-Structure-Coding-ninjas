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

void print_level_wise(binarytreenode<int>* root){
    //cout<<root->data<<":";
    queue<binarytreenode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0){
        binarytreenode<int>* front=pending.front();
        pending.pop();
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

pair<int,int> diameter (binarytreenode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;//denotes height
        p.second=0;//denotes diameter
        return p;
    }
    pair<int,int> lh=diameter (root->left);
    pair<int,int> rh=diameter(root->right);
    int height= 1+max(lh.first,rh.first);
    int dia= max(lh.first+rh.first,max(lh.second,rh.second));
    pair<int,int>p;
    p.first=height;
    p.second=dia;
    return p;
}

int main() {
    binarytreenode<int>* root=take_input_level_wise();
    print_level_wise(root);
   pair<int,int> p= diameter(root);
   cout<<"diameter="<<p.second<<endl;

    return 0;
}
