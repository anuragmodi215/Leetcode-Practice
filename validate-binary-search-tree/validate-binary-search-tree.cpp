/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(!root) return true;
        
        if(min!=NULL and root->val<=min->val) 
            return false;
        if(max!=NULL and root->val>=max->val)
            return false;
            
 return helper(root->left,min,root) and helper(root->right,root,max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
};