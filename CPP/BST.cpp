/*
LECTURE : 12 & 13
DATE    : 01/02/2020
TOPIC   : 1. BST CREATE FROM INORDER
          2. BST ADD NODE
          3. BST DELETE NODE

DATE    : 02/02/2020
TOPIC   : 1. BST LCA
          2.
          3.

*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int  data = 0;
  Node *left = NULL;
  Node *right = NULL;
  Node(int data = 0, Node *left = NULL, Node *right = NULL)
  {
    this->data=data;
    this->left=left;
    this->right=right;
  }
  ~Node()
  {
    delete left;
    delete right;
  }
};

Node* create(vector <int> &arr, int &idx ){
  if(idx == arr.size() || arr[idx] == -1){
    idx++;
    return NULL;
  }

  Node* node = new Node(arr[idx], NULL, NULL);

  idx++;
  node->left = create(arr, idx);
  node->right = create(arr, idx);

  return node;
}

void display(Node* node){
  if(node == NULL)
  return;

  string str="";

  str+=(node->left == NULL)?".":to_string(node->left->data);
  str+="->" +to_string(node->data) + "<-";
  str+=(node->right == NULL)?".":to_string(node->right->data);

  cout<<str<<"\n";

  display(node->left);
  display(node->right);
}

Node* create_in(vector<int> &v,int l, int r){

  if(l>r)
  return NULL;

  int mid = (l+r) >> 1;
  Node* root = new Node(v[mid]);

  root->left = create_in(v,l, mid-1);
  root->right = create_in(v,mid+1,r);

  return root;
}

Node* add_node_BST(Node* root, int data){

  if(root==NULL){
    Node* node = new Node(data);
    return node;
  }

  if(data<root->data)
  root->left = add_node_BST(root->left, data);

  else
  root->right = add_node_BST(root->right, data);

  return root;
}

Node* del_node_BST(Node* node, int data){

  if(data < node->data)
  node->left = del_node_BST(node->left, data);

  else if(data > node->data)
  node->right = del_node_BST(node->right, data);

  else{
    if(!node->left || !node->right){

       Node* temp = node->left?node->left:node->right;
       delete(node);
       return temp;
    }

    Node* temp = node->left;

    while(temp->right!=NULL)
    temp = temp->right;

    node->data = temp->data;
    node->left = del_node_BST(node->left, temp->data);
  }


  return node;
}

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        // print the value of the node
        cout << node->data << endl;
        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);
}
/*-----------------------------------------------------------------LECTURE - 12-----------------------------------------------------------------*/
Node* find(Node* root, int a){
  if(root == NULL)
  return NULL;

  if(a < root->data)
  return find(root->left, a);

  if(a > root->data)
  return find(root->right, a);

  return root;
}

Node* LCA_BST(Node* node, int a, int b){
  if(node == NULL) // Required Only when root NULL
  return NULL;

  if(a==b)
  return find(node, a);

  if((a <= node->data && b >= node->data) || (a >= node->data && b <= node->data)){

  if(!find(node, a) || !find(node, b) )
  return NULL;

  else
  return node;
  }

  if(a<node->data)
  return LCA_BST(node->left, a, b);

  return LCA_BST(node->right, a, b);
}

int main(){
  vector<int> v;
  v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  Node* root = create_in(v, 0, v.size()-1);
  //root = add_node_BST(root, 0);

  //root = del_node_BST(root, 7);
  display(root);

   Node* ans = LCA_BST(root, 0, 8);  //find(root, 4);
   cout<<(ans==NULL?-1:ans->data)<<"\n";
  //printBT(root);
  delete root;
  return 0;
}
