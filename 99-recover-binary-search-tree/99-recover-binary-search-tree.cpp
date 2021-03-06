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
    TreeNode* last;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* prev;
    void check(TreeNode* root){
        if(!root) return;
        
        check(root->left);
        
        if(prev and prev->val>root->val){
            if(!first){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        
        prev = root;
        
        check(root->right);
    }
    void recoverTree(TreeNode* root) {
        last = first = middle = prev = NULL;
        check(root);
        
        if(first and last) swap(first->val, last->val);
        else swap(first->val, middle->val);
    }
};




