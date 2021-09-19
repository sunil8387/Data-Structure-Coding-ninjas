//Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.


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

//approch 1 node with Max child sum
int helper(treenode<int>* root){
    int sum=root->data;
    for (int i=0;i<root->children.size();i++){
        sum+= root->children[i]->data;
    }
    return sum;
}

int max(treenode<int>* root){
    int ans = root->data;
    int sum=helper(root);
    for (int i=0;i<root->children.size();i++){
        int x=max(root->children [i]);
        int xsum=helper(root->children [i]);
        if (xsum>sum){
            sum=xsum;
            ans=x;
        }
    }
    return ans ;
}

//nodes with Max sub child sum genric tree
// Approach 2
int s(treenode<int>* root){
    int ans=root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=root->children [i]->data;
    }
    return ans;
}
pair<int,int> helper1(treenode<int>* root){
    pair<int,int> x ;
    x.first = root->data;
    x.second=s(root);
    for(int i=0;i<root->children.size();i++){
        pair<int,int> p1= helper1(root->children [i]);
        if(p1.second>=x.second){
            x.first=p1.first;
            x.second=p1.second;
        }
    }
    return x;
}

int max1(treenode<int>* root){
    pair<int,int> p=helper1(root);
    return p.first;
}

int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  cout<<max(root)<<" ";
  cout<<max1(root);
  return 0;
}
