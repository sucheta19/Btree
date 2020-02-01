
public static class BSTpair(){


  bool isBst = false;
  int count = 0;
  int lsize = 0;
  Node lBstRoot = null;

  int min = (int) 1e8;
  int max = (int) -1e8;


  public static BSTpair BSTsol(Node node){
     if(node == NULL){
       return new BSTpair();
     }

     BSTpair lp = BSTsol(node.left);
     BSTpair lp = BSTsol(node.left);

     BSTpair myPair = new BSTpair();

     if(lp.isBst && rp.isBst && lp,max < node.data && node,data < rp.min){
       myPair.isBst = true;
       myPair.count = lp.count + rp.count;
     }

     else{
       myPair.isBst = false;
       myPair.count = lp.count + rp.count;

       if(lp.lBSTsize > rp.lBSTsize){
         myPair.lBSTsize = rp.lBSTsize;
         myPair.lBSTroot = rp.lBSTroot;

       }
       else{
         myPair.lBSTsize = rp.lBSTsize;
         myPair.lBSTroot = rp.lBSTroot;
       }
     }
    myPair.min =
  }
}


public static Node linTree(Node node)
{
  if(node == null)
    return null;
  if (node.left == null && node.right == null)
    return node;
  Node leftTail = linTree(node.left);
  Node rightTail = linTree(node.right);
  if(leftTail == null)
    node.left = node.right;
  else
  leftTail.left = node.right;

  node.right = null;
  return rightTail != null ? rightTail : leftTail;

}
