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
    TreeNode* helper(TreeNode* a, TreeNode* b){
        if(a and b){
            TreeNode* root = new TreeNode(a->val+b->val);
            root->left = helper(a->left,b->left);
            root->right = helper(a->right,b->right);
            return root;
        }
        else{
            if(!a){
                return b;
            }
            else return a;
        }
        return NULL;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return helper(root1, root2);
    }
};