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
    int cnt=0;
    void helper(TreeNode*root,int maxi){
        if(!root) return;
        helper(root->left, max(root->val,maxi));
        helper(root->right,max(root->val,maxi));
        if(root->val>=maxi)cnt++;
    }
    int goodNodes(TreeNode* root) {
        helper(root,root->val);
        return cnt;
    }
};