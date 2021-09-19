/*
Given two generic trees, return true if they are structurally identical. Otherwise return false.
Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.

*/

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

bool identical(treenode<int>*root,treenode<int>*root2){
    if(root->data!=root2->data){
        return false;
    }
    for(int i=0;i<root->children.size()&&i<root2->children.size();i++){
        bool find=identical (root->children [i],root2->children [i]);
        if(!find){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
  treenode<int>*root2=takeInputLevelWise();
	treenode<int>*root1=takeInputLevelWise();
  if(identical(root1,root2)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
  return 0;
}
