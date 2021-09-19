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

// total number of nodes in tree
int num_node(treenode<int>*root){
	if (root==NULL){
		return 0;
	}
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans +=num_node(root->children[i]);  // recursively calling all child and adding them in ans
	}
	return ans;
}

int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  cout<<num_node(root);
  return 0;
}
