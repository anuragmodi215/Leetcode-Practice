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
    int helper(TreeNode* root, int &sum){
        if(!root) return 1;
        int left = helper(root->left,sum);
        int right = helper(root->right,sum);
        if(left==0 or right==0){
            sum++;
            return 2;
        }
        else if(left==2 or right==2){
            return 1;
        }
        else return 0;
    }
    int minCameraCover(TreeNode* root) {
        int sum=0;
        int cameras = helper(root,sum);
        if(cameras ==0) return ++sum;
        return sum;
        
    }
};