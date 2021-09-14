/*
7 4 2 5 1 6 3 7 4 5 2 6 7 3 1
*/
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

binarytreenode<int>* builttreepost(int *in,int *post,int ins,int ine,int posts,int poste){
    if(ins>ine){
        return NULL;
    }
    int rootdata=post[poste];
    int rootindex= -1;
    for(int i=ins;i<=ine;i++){
        if(in[i]==rootdata){
            rootindex=i;
            break;
        }
    }

    int rie=ine;
    int ris=rootindex+1;
    int rpe=poste-1;
    int rps=rpe-rie+ris;
    int lis=ins;
    int lps=posts;
    int lie=rootindex-1;
    int lpe=rps-1;
    binarytreenode<int>* root=new binarytreenode<int>(rootdata);
    root->left=builttreepost(in,post,lis,lie,lps,lpe);
    root->right=builttreepost(in,post,ris,rie,rps,rpe);

    return root;
}


int main() {
    int in[100],post[100],n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    binarytreenode<int>* root= builttreepost(in, post,0,n-1,0,n-1);
    print_level_wise(root);
    return 0;
}
