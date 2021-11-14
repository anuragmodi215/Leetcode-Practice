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
    TreeNode *first,*middle,*second,*prev;
    void recover(TreeNode* root){
        if(!root) return;
        recover(root->left);
        if(prev and prev->val>root->val){
            if(!first){
                first = prev;
                middle = root;
            }
            else second = root;
        }
        prev = root;
        recover(root->right);
    }
    void recoverTree(TreeNode* root) {
        recover(root);
        if(first and second){
            swap(first->val,second->val);
        }
        else if(first and middle){
            swap(first->val,middle->val);
        }
    }
};