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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front){
                v.push_back(front->val);
            }
            else{
                ans.push_back(v);
                v.clear();
                if(!q.empty()) q.push(NULL);;
            }
            if(front and front->left){
                q.push(front->left);
            }
            if(front and front->right){
                q.push(front->right);
            }
        }
        
        
        return ans;
    }
};