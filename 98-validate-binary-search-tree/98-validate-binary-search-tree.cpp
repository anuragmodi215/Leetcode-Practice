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
public:
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(!root) return true;
        if(min or max){
            if(min and root->val<=min->val) return false;
            if(max and root->val>=max->val) return false;
        }
        bool left = helper(root->left, min, root);
        bool right = helper(root->right, root, max);
        
        return left and right;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
};