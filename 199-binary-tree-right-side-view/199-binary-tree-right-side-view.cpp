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
    map<int,int>mp;
    vector<int>ans;
    void solve(TreeNode* root, int level){
        if(!root) return;
        //if(mp.find(level)==mp.end()) mp[level]= root->val;
        if(ans.size()<level) ans.push_back(root->val);
        solve(root->right,level+1);
        solve(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root,1);
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
};