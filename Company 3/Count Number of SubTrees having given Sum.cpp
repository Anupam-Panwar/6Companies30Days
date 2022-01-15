int cnt;
int computeSum(Node* node, int target)
{
    int sum = node->data;
    if(node->left!=NULL)
        sum += computeSum(node->left,target);
    if(node->right!=NULL)
        sum += computeSum(node->right,target);
    if(sum == target)
        cnt++;
        
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
    cnt = 0;
    int treeSum = computeSum(root,X);
    return cnt;
}