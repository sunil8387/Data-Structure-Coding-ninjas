//Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.

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

bool find(treenode<int>* root, int x){
    if (root->data==x){  // if root data is equal to node then we return true
        return true;
    }
    for (int i=0;i<root->children.size();i++){    // recursively calling root children
        bool check= find(root->children [i], x);  // if root children return true then we will return true from function else will call next child
        if (check){
            return true;
        }
    }
    return false ;
}

int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  if(find(root,5)){
    cout<<"true";
  }
  else{
    cout<<"false";
  }
  return 0;
}
