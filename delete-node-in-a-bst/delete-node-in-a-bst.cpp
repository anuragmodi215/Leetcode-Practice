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
    TreeNode* findMin(TreeNode* root){
        while(root->left) root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            TreeNode* temp=NULL;
            if(!root->left and !root->right){
                root=NULL;
            }
            else if(!root->left){
                temp=root;
                root=root->right;
                delete(temp);
            }
            else if(!root->right){
                temp=root;
                root=root->left;
                delete(temp);
            }
            else{
                TreeNode* t = findMin(root->right);
                root->val=t->val;
                root->right = deleteNode(root->right,t->val);
            }
        }
        return root;
    }
};