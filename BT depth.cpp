/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int d=1;
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return calDepth(root->left,root->right);
    }
    
    int calDepth(TreeNode* l,TreeNode* r)
    {
        if(l==NULL&&r==NULL)
            return d;
        else if(l==NULL&&r!=NULL)
            return d+calDepth(r->left,r->right);
        
        else if(r==NULL&&l!=NULL)
            return d+calDepth(l->left,l->right);

        else 
            return d+max(calDepth(l->left,l->right),calDepth(r->left,r->right));
 
    }
};
