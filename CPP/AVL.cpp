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

  int hieght = -1;
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

void update_ht_bal(Node* node){
  int lh = -1, rh = -1;

  if(node->left) lh = node->left->hieght;
  if(node->right) rh = node->right->hieght;

 node->height = max(lh, rh) + 1;
 node->bal = lh-rh;
}


Node* ll(Node x){
  Node* y = x->left;
  Node* ykaright = y->right;

  y->right = x;
  x->left = ykaright;

  return y;
}

Node* rr(Node x){
  Node* y = x->right;
  Node* ykaleft = y->left;

  y->left = x;
  x->right = ykaleft;

  return y;
}

Node* getRotate(){
  if(node->balance == 2){                      //ll, lr
    if(node->left->balance == 1)  //ll
    return ll(node);
    else{   //lr
      node->left = rr(node->left);
      return ll(node);
    }
  }

  else if(node->balance == -2){ //rr, rl
    if(node->right->balance == -1)  //rr
    return rr(node);
    else{   //rl
      node->right = ll(node->right);
      return rr(node);
    }
  }
}

int main(){


  delete root;
  return 0;
}
