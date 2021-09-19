/*
Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn are the children of node N.
*/
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

treenode<int> * takeInputLevelWise(){ //itrative approch
	int rootdata;
	cout<<"enter root data: "; // taking root data from user
	cin>>rootdata;
	treenode<int>* root=new treenode<int>(rootdata);  //creating root of tree
	queue<treenode<int>*> pending;  // creating a queue of type treenode
	pending.push(root); // entering root data to the queue

	while (pending.size()!=0){  // while queue is not empty
		treenode<int>* front=pending.front();  // creating another tree which has data value wic are in queue
		pending.pop(); // after adding element in tree deleting it from queue
		int n;
		//cout<<"number of children of "<<front->data<<" ";
		cin >>n;
		for (int i=0;i<n;i++){
			//cout<<"enter "<<i<<"th children of "<<front->data<<" ";
			int child;
			cin>>child; // taking value of children i from user
			treenode<int>* childnode=new treenode<int>(child); // creating a tree node with value of children
			front->children.push_back(childnode); // linking children and root node
			pending.push(childnode); // adding that element toh queue to take input its further child
		}
	}
	return root;

}

void printLevelWise(treenode<int>*root){
	//cout<<root->data<<":";
	queue<treenode<int>*> pending; // creating a queue of type treenode
	pending.push(root); // inserating root element to the tree
	while(pending.size()!=0){
		treenode<int>*front=pending.front(); // creating another tree node and putting value of queue in it to print
		pending.pop(); // after putting value in tree node deleting it from queue
		cout<<front->data<<":"; //printing value which is being entered to tree
		for(int i=0;i<front->children.size();i++){  //printing its child value
			cout<<front->children[i]->data<<",";
			pending.push(front->children[i]); // entering that value to queue to print its child if any.
		}
		cout<<endl;
	}
	return;
}

int main(int argc, char const *argv[]) {
  treenode<int>*root=takeInputLevelWise();
  printLevelWise(root);
  return 0;
}
