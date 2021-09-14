#include <iostream>
#include<queue>
#include<climits>
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

pair<int,int> maxmin(binarytreenode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=INT_MIN; //denotes max
        p.second=INT_MAX; //denotes min
        return p;
    }
    int rootdata=root->data;
    pair<int,int> p;
    pair<int,int> left1= maxmin(root->left);
    pair<int,int> right1= maxmin(root->right);
    int fmaximun=max(rootdata,max((left1.first),(right1.first)));
    int fminimum= min(rootdata,min(left1.second,right1.second));
    p.first=fmaximun;
    p.second=fminimum;
    return p;

}

int main() {
    binarytreenode<int>* root=take_input_level_wise();
    print_level_wise(root);
   pair<int,int> p= maxmin(root);
   cout<<"maximum= "<<p.first<<endl;
   cout<<"minimun= "<<p.second<<endl;

    return 0;
}
