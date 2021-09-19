//You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.

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


void replace_depth(treenode<int>*&root,int depth){
    root->data=depth;
    for (int i=0;i<root->children.size();i++){
        replace_depth(root->children [i],depth+1);
    }
    return ;
}


int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  replace_depth(root,0);
  return 0;
}
