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
    void getAvg(vector<int>&level, vector<double>&ans){
        double sum = 0;
        for(auto i:level){
            sum+=i;
        }
        ans.push_back(sum/level.size());
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>level;
        
        while(!q.empty()){
            TreeNode* front = q.front();
            if(front)level.push_back(front->val);
            q.pop();
            if(!front){
                getAvg(level,ans);
                if(!q.empty()){
                    q.push(NULL);
                }
                level.clear();
            }
            else{
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
        }
        return ans;
    }
};