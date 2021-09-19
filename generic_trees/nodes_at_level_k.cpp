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

void nodes_at_level_k(treenode<int>* root,int k){ // printing all nodes value at a certain level
	if (root==NULL||k<0){
		return;
	}

	if (k==0){
		cout<<root->data<<endl;
		return;
	}
	for (int i=0;i<root->children.size();i++){
		//cout<<root->children[i]->data<<endl;
		nodes_at_level_k(root->children[i],k-1); // at root we have to find values at level k but for root->cildren it is at level k-1
	}
}


int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  nodes_at_level_k(root);
  return 0;
}
