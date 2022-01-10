 class Solution {
  public:
    unordered_map<Node*, Node*> mmp;
    unordered_map<Node*, bool> visit;
    Node* tn;
    
    void fillParentMap(Node* root,int target)
    {
        queue<Node *> qu;
        qu.push(root);
        visit[root] = false;
        
        while(qu.empty() == false)
        {
            Node* temp = qu.front();
            qu.pop();
            if(temp->data == target)
                tn = temp;
            
            if(temp->left != NULL)
            {
                mmp[temp->left] = temp;
                visit[temp->left] = false;
                qu.push(temp->left);
            }
            if(temp->right != NULL)
            {
                mmp[temp->right] = temp;
                visit[temp->right] = false;
                qu.push(temp->right);
            }
        }
    }
    
    int burnTime()
    {
        int t = -1;
        visit[tn] = true;
        queue<Node *> qu;
        qu.push(tn);
        
        while(qu.empty() == false)
        {
            t++;
            int s = qu.size();
            for(int i = 0;i<s;i++)
            {
                Node* temp = qu.front();
                qu.pop();
                
                if(temp->left != NULL && visit[temp->left] == false)
                {
                    qu.push(temp->left);
                    visit[temp->left] = true;
                }
                if(temp->right != NULL && visit[temp->right] == false)
                {
                    qu.push(temp->right);
                    visit[temp->right] = true;
                }
                if(mmp.count(temp)!=0 && visit[mmp[temp]] == false)
                {
                    qu.push(mmp[temp]);
                    visit[mmp[temp]] = true;
                }
            }
        }
        return t;
    }
    
    
    int minTime(Node* root, int target) 
    {
        fillParentMap(root,target);
        
        int t = burnTime();
        return t;
    }
};