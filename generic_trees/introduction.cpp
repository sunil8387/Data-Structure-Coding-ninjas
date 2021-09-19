#include<iostream>
#include<vector>
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

treenode<int>* takeinput(){  // recursive approach

	int data;
	cout<<"enter data ";
	cin>>data;
	treenode<int> *root=new treenode<int>(data);
	int n;
	cout<<"how many children are there of "<<data<<" ";
	cin>>n;

	for(int i=0;i<n;i++){
		treenode<int>*child= takeinput();
		root->children.push_back(child);
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

void print(treenode<int> *root){  //printing children of root node in front of root node
	cout<<root->data<<":";
	for (int i=0;i<root->children.size();i++){
		cout<<root->children[i]->data<<",";  //printing children of root node in front of root node
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		print(root->children[i]);   //recursively calling root node childrens to get print
	}
	return;
}



int main(int argc, char const *argv[])
{
	treenode<int> * root=new treenode<int>(1); // creating root node
	treenode<int> * node1=new treenode<int>(2);
	treenode<int> * node2=new treenode<int>(3);   //creating children node of root node but not connecting them with root node
	treenode<int> * node3=new treenode<int>(4);
	treenode<int> * node4=new treenode<int>(5);

	root->children.push_back(node1);   //connecting children nodes with root node
	root->children.push_back(node2);
	root->children.push_back(node3);
	root->children[2]->children.push_back(node4);   //connecting children of root node to its children
	print(root);



	treenode<int> *root2=takeInputLevelWise();  //taking tree input from user
	preorder_print(root2);

  return 0;
}
