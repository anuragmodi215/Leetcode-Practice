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
    
    void traversal(TreeNode* root, int vertical, int row,  map<int,map<int,multiset<int>>>&node)
    {
        if(!root) return;
        
        traversal(root->left,vertical-1,row+1,node);
        traversal(root->right,vertical+1,row+1,node);
        
        node[vertical][row].insert(root->val);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,map<int,multiset<int>>> node;
        traversal(root,0,0,node);
        
        for(auto &i:node){
            vector<int>v;
            for(auto &j: i.second){
                for(auto k:j.second){
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};