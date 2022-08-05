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
    int inorder(TreeNode* root, int &val, int &minDiff){
        if(root->left){
            inorder(root->left,val,minDiff);
        }
        if(val>=0){
            minDiff = min(minDiff, root->val-val);
            //cout<<minDiff<<endl;
        }
        val = root->val;
        if(root->right){
            inorder(root->right, val, minDiff);
        }
        return minDiff;
    }
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int val=-1;
        return inorder(root,val, minDiff);
    }
};