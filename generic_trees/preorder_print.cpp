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
//preorder print is print root's data first and then its children's data
void preorder_print(treenode<int>*root){  //print in a single line
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++){
		preorder_print(root->children[i]);   //recursively calling root node childrens to get print
	}
	return;
}

int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  preorder_print(root);
  return 0;
}
