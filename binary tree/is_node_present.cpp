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

bool is_present (binarytreenode<int>* root,int x){
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
    print_level_wise(root);
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
