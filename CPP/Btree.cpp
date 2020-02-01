# include<iostream>
# include<vector>
# include<queue>

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

int dt_sum(Node* node, int &h){
   if(node == NULL)
    return 0;


   int hl = 0, hr = 0;

   int d_prev = max( dt_sum(node->left, hl), dt_sum(node->right, hr));

   h = max(hl, hr) + node->data;

   return max( d_prev, hl + hr + node->data);

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

void bfs(Node* root){
  queue<Node*> q;

  q.push(root);
  q.push(NULL);

  while(!q.empty()){

   Node* temp = q.front();
   q.pop();


   if((temp == NULL) && !q.empty()){
    cout<<"\n";
    q.push(NULL);
  }

   else if(!q.empty()){
   cout<<temp->data<<" ";

   if(temp->left != NULL)
   q.push(temp->left);

   if (temp->right != NULL)
   q.push(temp->right);
  }
}
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

int main()
{
  vector<int> arr;
  vector<Node*> v;
  int n;
  cin >> n;
  vector <int> pre(n);
  vector <int> pst(n);
  vector <int> in(n);

  for (auto && i: pre)
    cin >> i;


  // for (auto && i: pst)
  //     cin >> i;

  for (auto && i: in)
      cin >> i;

  int idx = 0;
  Node* root = create_pre(pre, in, idx, 0, n-1);

  // idx = n-1;
  // Node* root = create_pst(pst, in, idx, 0, n-1);

  //bfs(root);



  //display(root);

  //
  // arr = {10,20,30,-1,-1,40,-1,-1,50,60,80,-1,-1,-1,70,90,-1,100,-1,-1,-1};
  //
  // int idx = 0;
  // Node* root = create(arr, idx);

  // Node* p=LCA(root , 100, 30);
  //  cout<<p->data<<"\n";

   int ht = 0 ;

   cout<<dt_sum(root, ht)<<"\n";

  delete root;
  return 0;
}
