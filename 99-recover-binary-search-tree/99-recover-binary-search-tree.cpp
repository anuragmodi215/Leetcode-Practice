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
    TreeNode*first=NULL;
    TreeNode*middle=NULL;
    TreeNode*second=NULL;
    TreeNode*prev=NULL;
    void helper(TreeNode*root){
        if(!root) return;
        helper(root->left);
        if(prev and prev->val>root->val){
            if(!first){
                first = prev;
                middle = root;
            }
            else second = root;
        }
        prev = root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        if(first and second){
            swap(first->val, second->val);
        }
        else swap(first->val,middle->val);
    }
};