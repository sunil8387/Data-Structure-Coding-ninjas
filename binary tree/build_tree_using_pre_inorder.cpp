/*
7 4 2 5 1 6 3 7 1 2 4 5 3 6 7
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

binarytreenode<int>* builttreepre(int *in,int *pre,int ins,int ine,int pres,int pree){
    if(ins>ine){
        return NULL;
    }
    int rootdata=pre[pres];
    int rootindex= -1;
    for(int i=ins;i<=ine;i++){
        if(in[i]==rootdata){
            rootindex=i;
            break;
        }
    }

    int ris=rootindex+1;
    int rie=ine;
    int rpe=pree;
    int lis=ins;
    int lps=pres+1;
    int lie=rootindex-1;
    int lpe=lie-lis+lps;
    int rps=lpe+1;
    binarytreenode<int>* root=new binarytreenode<int>(rootdata);
    root->left=builttreepre(in,pre,lis,lie,lps,lpe);
    root->right=builttreepre(in,pre,ris,rie,rps,rpe);

    return root;
}


int main() {
    int in[100],pre[100],n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    binarytreenode<int>* root= builttreepre(in, pre,0,n-1,0,n-1);
    print_level_wise(root);
    return 0;
}
