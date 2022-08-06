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
    void helper(TreeNode* root,vector<int>&v, int lv){
        if(!root) return;
        if(v.size()<lv){
            v.push_back(root->val);
        }
        helper(root->right,v,lv+1);
        helper(root->left,v,lv+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        helper(root,v,1);
        return v;
    }
};