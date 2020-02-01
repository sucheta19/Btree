/*                                                                                 \
 BST count in a tree, maximum bst ka node, check if balanced;                      \
                                                                           /\      \
 convert a tree to a tree in preorder in the right and no left child e.g. /\/\ to  \
                                                                                   \
                                                                                   \
*/
# include<iostream>
# include<vector>
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

int height( Node* node){
  if(node == NULL)
  return 0;

  return max( height(node->left) , height(node->right)) + 1 ;
}

int size( Node* node){
   if (node == NULL)
    return 0;

   return size( node->left ) + size( node->right ) + 1;
}

bool find(Node* node, int val, vector<Node*> &v){
  if(node == NULL)
   return false;

  if( node->data == val){
   v.push_back(node);
   return true;
   }
  bool res = false;

  res = res || find(node->left , val, v);
  res = res || find(node->right , val, v);

  if(res)
   v.push_back(node);

 return res;
}

Node* LCA(Node* node, int x, int y){

   vector<Node*> a;
   vector<Node*> b;
   Node* prev = NULL;

  if(!find(node, x, a) || !find(node, y, b))
   cout<<"NOT FOUND\n";

  else{
    for(int i=a.size()-1,j=b.size()-1; i>=0 && j>=0; i--, j--)
    {
      if(a[i]!=b[j])
        break;
        prev = a[i];
    }
 }

  return prev;
}

void height(Node* node, int &ht){
  if(node == NULL)
    return;
  int hl = 0, hr = 0;

  height(node->left, hl);
  height(node->right, hr);

  ht = max(hl , hr) + 1;
  return;
}

int dt(Node* node, int &ht){
   if(node == NULL)
    return 0;

   int hl = 0, hr = 0;
   int d_prev = max( dt(node->left, hl), dt(node->right, hr));

   ht = max(hl , hr) + 1;

   return max( d_prev, hl + hr + 1);

}

Node* create_pre(vector<int> &pre, vector<int> &in, int &idx, int l, int r){
  int n = in.size();

  if(idx >= n || l>r )
  return NULL;

  Node* node = new Node(pre[idx]); // Default initialisation has already been done above.


   int pos;

  for(int i=l; i<=r ; i++){
    if(in[i] == pre[idx]){
      pos=i;
      break;
    }
  }
  idx++;

  node->left = create_pre(pre, in, idx, l, pos-1);
  node->right = create_pre(pre, in, idx, pos+1, r);

  return node;
}

Node* create_pst(vector<int> &pst, vector<int> &in, int &idx, int l, int r){

  int n = in.size(), pos;

  if(idx < 0 || l>r)
   return NULL;

  Node* node = new Node(pst[idx]);

  for(int i = r; i >= l; i--)
   if(in[i] == pst[idx]){
     pos = i;
     break;
   }

   idx--;

   node->right = create_pst(pst, in, idx, pos+1, r);
   node->left = create_pst(pst, in, idx, l, pos-1);

  return node;
}

void in_order(Node* root){
  if(node == NULL)
  return;

  in_order(root->left);
  cout<< node->data <<"\n";
  in_order(root->right);

}

int l_max = (int)-1e8, r_min = (int)1e8, max_size = 0;
bool is_bst = false;

void bst_sol(Node* node){

}


int main()
{



  delete root;
  return 0;
}
