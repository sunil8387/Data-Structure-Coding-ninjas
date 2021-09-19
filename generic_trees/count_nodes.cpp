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

int node_greater_than_x(treenode<int>*root,int x){
    int count=0;
    if (root->data>x){
        count ++;
    }
    for (int i=0;i<root->children.size();i++){
        count+=node_greater_than_x(root->children [i], x);
    }
    return count;
}

int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  cout<<node_greater_than_x(root,35);
  return 0;
}
