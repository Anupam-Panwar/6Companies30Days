class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void inorder(Node* node, vector<int> &ans)
    {
        if(node == NULL)
        return;
        
        inorder(node->left,ans);
        ans.push_back(node->data);
        inorder(node->right,ans);
    }
    
    vector<int> serialize(Node *root) // For serialization calculating inorder of the tree
    {
       vector<int> ans;
       inorder(root,ans);
       return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A) // For deserialization making a tree from the inorder
    {                                  // we cannot construct an unique Binary Tree from a single traversal
        Node* head  = new Node(A[0]);  // Inorder of the tree generated is same as inorder given by serialization 
        Node* temp = head;
        int n = A.size();
        for(int i=1;i<n;i++)
        {
           temp->right = new Node(A[i]);
           temp = temp->right;
        }
        return head;
    }

};