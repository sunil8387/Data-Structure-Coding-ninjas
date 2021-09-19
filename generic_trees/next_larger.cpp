//Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
//Note: Return NULL if no node is present with the value greater than n.

#include<iostream>
#include<queue>
#include<climits>
using namespace std;
template <typename T>
class treenode
{
public:
	T data;
	vector<treenode*> children;

	treenode(int d){
		data=d;
	}

};

treenode<int> * takeInputLevelWise(){
	int rootdata;
	cout<<"enter root data: ";
	cin>>rootdata;
	treenode<int>* root=new treenode<int>(rootdata);
	queue<treenode<int>*> pending;
	pending.push(root);

	while (pending.size()!=0){
		treenode<int>* front=pending.front();
		pending.pop();
		int n;
		cin >>n;
		for (int i=0;i<n;i++){
			int child;
			cin>>child;
			treenode<int>* childnode=new treenode<int>(child);
			front->children.push_back(childnode);
			pending.push(childnode);
		}
	}
	return root;

}


int nextlarger(treenode<int>*root,int x){
    int ans=0;
    if(root->data >x){
        ans=root->data;
    }
    for (int i=0;i<root->children.size();i++){
        int n=nextlarger(root->children [i],x);
        if(ans==0 ){
            ans=n;
        }
        if(ans>n&&n!=0){
            ans=n;
        }
    }
    return ans;
}
int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  cout<<nextlarger(root,5);
  return 0;
}
