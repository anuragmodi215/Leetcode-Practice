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
    int cnt=0;
    void helper(TreeNode* root, long long int target){
        if(!root) return;
        if(root->val==target) cnt++;
        target-=root->val;
        helper(root->left,target);
        helper(root->right,target);
    }
    int pathSum(TreeNode* root, int targetSum) {
        //cnt=0;
        if(!root) return cnt;
        helper(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right, targetSum);
        return cnt;
    }
};