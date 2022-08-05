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
    bool helper(TreeNode* root, int targetSum){
        //if(!root and targetSum==0) return true;
        if(!root) return false;
        if(!root->left and !root->right and targetSum-root->val==0) return true;
        //if(targetSum<0) return false;
        bool left = helper(root->left, targetSum-root->val);
        bool right = helper(root->right, targetSum-root->val);
        return left or right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return helper(root,targetSum);
    }
};