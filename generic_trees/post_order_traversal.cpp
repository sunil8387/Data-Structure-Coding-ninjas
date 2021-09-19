//Given a generic tree, print the post-order traversal of given tree.

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

//The post-order traversal is: visit child nodes first and then root node
void postorder_print(treenode<int>*root){  // printing tree in one line from last // does not print root node
	if (root==NULL){
		return;
	}

	for(int i=0;i<root->children.size();i++){
		postorder_print(root->children[i]);   //recursively going to last node of  tree

	}
	cout<<root->data<<" ";  //printing the node

}


int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  postorder_print(root);
  return 0;
}
