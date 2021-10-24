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
    void cntNodes(TreeNode* root,int &cnt){
        if(!root) return;
        cnt++;
        cntNodes(root->left,cnt);
        cntNodes(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt=0;
        cntNodes(root,cnt);
        return cnt;
    }
};