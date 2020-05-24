/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* create_BST(int start,int end,vector<int> preorder)
{   

    TreeNode * node = new TreeNode(preorder[start]);

    
    if(start==end)
        return node;
    
    int index =-1;
    int i=start;
    while(i<=end && preorder[i]<=preorder[start])
    {
        i++;
    }
    if(i <= end)
    {
       node->right= create_BST(i,end,preorder);
    }
    
    if(start+1<=i-1)
    node->left =create_BST(start+1,i-1,preorder);
    
    
    return node;
    
    
    
}
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode * root = new TreeNode;
        
        int n = preorder.size();
        
       root= create_BST(0,n-1,preorder);
        
        return root;
        
    }
};