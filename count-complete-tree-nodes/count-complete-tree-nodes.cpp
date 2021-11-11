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
    int leftHeight(TreeNode* root){
        if(!root) return 0;
        TreeNode* node = root;
        int cnt=0;
        while(node){
            cnt++;
            node=node->left;
        }
        return cnt;
    }
    int rightHeight(TreeNode* root){
        if(!root) return 0;
        TreeNode* node = root;
        int cnt=0;
        while(node){
            cnt++;
            node=node->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh==rh){
             return pow(2,lh)-1;
        }
        return 1 + countNodes(root->left)+countNodes(root->right);
    }
};