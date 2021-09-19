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

int largest(treenode<int>*root){
	int ans=INT_MIN;

	for (int i=0;i<root->children.size();i++){
		int cm=largest(root->children[i]); //storing value of each node
		if (cm>ans){   // comparing that value of ans
			ans=cm;
		}
	}
	if (ans<root->data){  // after comparing with all children comparing it with root
		ans=root->data;
	}
	return ans;
}

int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  cout<<largest(root);
  return 0;
}
