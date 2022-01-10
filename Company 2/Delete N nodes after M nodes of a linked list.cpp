class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            int md = m;
            while(md>1 && temp!=NULL)
            {
                temp = temp->next;
                md--;
            }
            Node* ph = temp;
            
            md = n;
            while(md>0 && temp!=NULL)
            {
                temp = temp->next;
                md--;
            }
            
            if(ph!=NULL)
            {
                temp = temp ? temp->next : NULL;
                ph->next = temp;
            }
        }
    }
};