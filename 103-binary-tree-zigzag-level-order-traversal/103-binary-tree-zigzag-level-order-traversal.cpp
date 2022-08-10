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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front){
                v.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            else{
                ans.push_back(v);
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        for(int i=1; i<ans.size(); i++){
            if(i%2==1){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};