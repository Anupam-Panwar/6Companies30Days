class Solution
{
    public:
        void connect(Node* root)
        {
            if(root == NULL) 
                return; 

            queue<Node*> q;
            q.push(root);
            while(q.empty() == false) 
            {
                Node* prev = NULL;
                Node* curr = NULL;
                int n = q.size();
                for(int i = 0;i < n;i++) 
                {
                    curr = q.front();
                    q.pop();
                    if(prev != NULL ) 
                        prev->nextRight = curr;
                    if(curr->left) 
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                        
                    prev = curr;
                }
            }
        }    
};