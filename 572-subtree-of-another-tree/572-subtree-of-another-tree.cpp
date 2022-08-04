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
    bool check(TreeNode*root, TreeNode*sub){
        if(!root and !sub) return true;
        if(!root or !sub) return false;
        if(root->val != sub->val) return false;
        return check(root->left,sub->left) and check(root->right, sub->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(check(root,subRoot)) return true;
        
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
        
    }
};