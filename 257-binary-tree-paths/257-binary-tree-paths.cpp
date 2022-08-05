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
    void helper(TreeNode*root, string output, vector<string>&ans){
        if(!root->left and !root->right){
            ans.push_back(output);
            return;
        }
        if(root->left){
            helper(root->left, output+"->"+to_string(root->left->val),ans);
        }
        if(root->right){
            helper(root->right, output+"->"+to_string(root->right->val),ans);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s;
        s+=to_string(root->val);
        helper(root,s,ans);
        return ans;
    }
};