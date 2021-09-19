// Given a generic tree, find and return the sum of all nodes present in the given tree.

#include<iostream>
#include<queue>
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


int sumnodes(treenode<int> *root){
	int ans=root->data;
	for(int i=0;i<root->children.size();i++){
		ans +=sumnodes(root->children[i]);  // recursively calling all child and adding them in ans
	}
	return ans;
}

int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  cout<<sumnodes(root);
  return 0;
}
