/*
  Lecture 8
  # Trees : Traversals
  Date: 12-01-2020
*/
import java.util.ArrayList;
import java.util.LinkedList;

public class Trav{

  public static void main(String[] args){
    int[] arr = {10,20,30,-1,-1,40,-1,-1,50,60,80,-1,-1,-1,70,90,-1,100,-1,-1,-1};


    Node root=create(arr);
  //  display(root);
    //bfs(root);
    System.out.println(kfar_2(root , 4 ,60));
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



 public static void bfs(Node root){           //Level order trav
 LinkedList<Node> que=new LinkedList<>();
 que.addLast(root);

 int level=0;

 while(que.size()>0){
   System.out.print("\nLevel:"+ level + "->");
   int size = que.size();

    while(size-->0){
      Node rnode =que.removeFirst();
      System.out.print(rnode.data + " ");

      if(rnode.left!=null)
      que.addLast(rnode.left);

      if(rnode.right!=null)
      que.addLast(rnode.right);
      }
    level++;
    }
   }

 public static void kaway(Node node, int k, Node rnode){
    if(node==null)
      return;
    if(node==rnode)
      return;

    if(k==0){
      System.out.print(node.data + " ");
      return;
    }

    kaway(node.left , k-1 , rnode);
    kaway(node.right , k-1 , rnode);
 }

 public static void kfar(Node node, int k, int data){  //O(n) Space O(n) Time Complexity
   ArrayList<Node> path = root_to_nodePath(node , data);
   Node rnode=null;

   for(int i=0; i<path.size();i++){
     kaway(path.get(i),k-i,rnode);
     rnode =  path.get(i);
   }
 }

 public static int kfar_2(Node node, int k, int data){  //O(1) Space O(n) Time Complexity
   if(node == null)
   return -1;

   if(node.data == data){   // Code not correct correct it.
     kaway(node, k , null);
     return 0;
   }

   int ld = kfar_2(node.left, k, data);
   if( ld != -1 ){
     if(ld ==  k)
       System.out.println(node.data + " ");
     else
     kaway(node, k-ld, node.left);
     return ld + 1;
   }

   int rd = kfar_2(node.right, k, data);
   if( rd != -1 ){
     if(rd == k)
       System.out.println(node.data + " ");
     else
     kaway(node, k-rd, node.right);
     return rd + 1;
   }

 return 0;
}

public static all_in_one()
{
  if(node == null)             //check on git rajneesh
   return;

  sol.size++;
  aol.height = Math.max(sol.height, level);
  sol.find = sol.find || node.data == data;

  if(node.data > data && node.data < sol.ceil)
     sol.ceil = node.data;

  if(node.data < data && node.data > sol.floor)
        sol.floor = node.data;
}

public static
}
