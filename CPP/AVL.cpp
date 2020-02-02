/*
LECTURE : 12
DATE    : 01/02/2020
TOPIC   : AVL
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int  data = 0;
  Node *left = NULL;
  Node *right = NULL;

  int height = -1;
  int bal = 0;
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

void update_ht_bal(Node* node){
  int lh = -1, rh = -1;

  if(node->left) lh = node->left->height;
  if(node->right) rh = node->right->height;

 node->height = max(lh, rh) + 1;
 node->bal = lh-rh;
}


Node* ll(Node* x){
  Node* y = x->left;
  Node* ykaright = y->right;

  y->right = x;
  x->left = ykaright;

  update_ht_bal(x);
  update_ht_bal(y);
  return y;
}

Node* rr(Node* x){
  Node* y = x->right;
  Node* ykaleft = y->left;

  y->left = x;
  x->right = ykaleft;

  update_ht_bal(x);
  update_ht_bal(y);

  return y;
}

Node* getRotate(Node* node){
  if(node->bal == 2){                      //ll, lr
    if(node->left->bal== 1)  //ll
    return ll(node);
    else{   //lr
      node->left = rr(node->left);
      return ll(node);
    }
  }

  else if(node->bal == -2){ //rr, rl
    if(node->right->bal == -1)  //rr
    return rr(node);
    else{   //rl
      node->right = ll(node->right);
      return rr(node);
    }
  }
return NULL;
}

Node* add_node_AVL(Node* root, int data){

  if(root==NULL){
    Node* node = new Node(data);
    return node;
  }

  if(data<root->data)
  root->left = add_node_AVL(root->left, data);

  else
  root->right = add_node_AVL(root->right, data);
  root = getRotate(root);
  return root;
}

int main(){
  Node *root = NULL;
  add_node_AVL(root, 1);
  add_node_AVL(root, 2);
  add_node_AVL(root, 3);
  add_node_AVL(root, 4);
  add_node_AVL(root, 5);
  add_node_AVL(root, 6);
  add_node_AVL(root, 7);

  display(root);

  delete root;
  return 0;
}
