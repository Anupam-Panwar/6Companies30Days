/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
   void toSumTree(Node *node)
    {
       helper(node);
    }
    int helper(Node *node)
    {
        int sum = node->data;
        
        if(node->left!=NULL)
            sum+=helper(node->left);
        if(node->right!=NULL)
            sum+=helper(node->right);
        
        int temp = sum;
        sum-=node->data;
        
        node->data = sum;
        
        return temp;
    }
};