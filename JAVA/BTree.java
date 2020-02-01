/*
  Lecture 7
  # Trees : Zero  Class
  Date: 11-01-2020
*/
import java.util.ArrayList;
public class BTree{

  public static void main(String[] args){
    int[] arr = {10,20,30,-1,-1,40,-1,-1,50,60,80,-1,-1,-1,70,90,-1,100,-1,-1,-1};

    ArrayList <Node> res ;

    Node root=create(arr);

    // display(root);
    // System.out.println(size(root));
    // System.out.println(height(root));

    res = root_to_nodePath(root , 60);

   /*// for(Node it: res)            //|Same as below
    // System.out.println(it.data);  //  |
    for(int i=0 ; i < res.size() ; i++ )
    System.out.println(res.get(i).data );*/

    //System.out.println(find(root, 10)? "YES" : "NO");

    //System.out.println(LCA(root, 60, 90));
    //System.out.println(Diameter(root));

     System.out.println(Math.max(Diameter_opt(root)[0],Diameter_opt(root)[1]));
  }

  public static void display(Node node){

    if(node == null)
     return;

    String str="";

    str+=node.left==null?".":node.left.data;
    str+="->"+node.data+"<-";
    str+=node.right==null?".":node.right.data;

    System.out.println(str);

    display(node.left);
    display(node.right);
    }

  public static class Node{
    int data = 0;
    Node left = null;
    Node right = null;

  Node(int data, Node left, Node right){
    this.data=data;
    this.left=left;
    this.right=right;
  }
}

static int idx = 0;

public static Node create(int[] arr){
  if(arr[idx] == -1 || idx == arr.length){
    idx++;
    return null;
  }

  Node nnode= new Node(arr[idx], null, null);
  idx++;

  nnode.left = create(arr);
  nnode.right = create(arr);

return nnode;
}

public static int height(Node node){
  if(node == null)
    return 0;   // height including root if return -1 root not counted in height

  return Math.max(height(node.left),height(node.right)) + 1;

}

public static int size(Node node){ // Size = Total n of nodes
  if(node == null)
    return 0;   // size including root if return -1 root not counted in size

  return size(node.left) + size(node.right) + 1;

}

public static boolean find(Node node, int data){
  if(node == null) return false;
  if(node.data == data) return true;

  boolean res = false;                 // res used to save calls otherwise could have written return  find(node.left, data)|| find(node.right, data);
  res = res || find(node.left, data) ;
  res = res || find(node.right, data);

  return res;
}

public static ArrayList<Node> root_to_nodePath(Node node, int data){

  ArrayList<Node> ans=new ArrayList<>();

  if(node == null)
   return ans;
  if(node.data == data)
  {
    ans.add(node);
    return ans;
  }

  ArrayList<Node> left = root_to_nodePath(node.left, data) ;
  if(left.size()!=0)
  {
    left.add(node);
    return left;
  }

  ArrayList<Node> right = root_to_nodePath(node.right, data) ;
  if(right.size()!=0)
  {
    right.add(node);
    return right;
  }

  return ans;
}

public static int LCA(Node root, int d1, int d2){
  ArrayList<Node> a,b;

  a = root_to_nodePath(root , d1);
  b = root_to_nodePath(root , d2);

  int prev = -1;

  for(int i = a.size()-1, j = b.size()-1; (i >= 0 && j >= 0); i--,j--)
  {
    if(a.get(i).data!=b.get(j).data)
      break;

      prev=a.get(i).data;
  }
  return prev;
}

public static int Diameter(Node node){     //O(n*n) solution

  if(node==null) return 0;

  int dl = Diameter(node.left);
  int dr = Diameter(node.right);

  int hl = height(node.left);
  int hr = height(node.right);

  return Math.max(Math.max(dl,dr), hl + hr + 1);
}

public static int[] Diameter_opt(Node node){  //O(n) solution

  if(node==null){
    return new int[2];
  }

  int[] left = Diameter_opt(node.left);
  int[] right = Diameter_opt(node.right);

  int[] myAns = new int[2];
  myAns[0] = Math.max(Math.max(left[0],right[0]), left[1]+right[1]  + 1);
  myAns[1] = Math.max(left[1], right[1]) + 1;



  return myAns;
}


}
