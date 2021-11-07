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
    vector<vector<int>>ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     if(!root) return ans;
        
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int flag=1;
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp){               
                v.push_back(temp->val);
            }
            if(!temp){
                if(flag){
                    ans.push_back(v);
                    flag=0;
                    if(q.size()>0){
                        q.push(NULL);
                    }
                }
                else{
                    reverse(v.begin(),v.end());
                    flag=1;
                    ans.push_back(v);
                    if(q.size()>0){
                        q.push(NULL);
                    }
                }
                v.clear();
            }
            
            else if(temp){
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }            
        }
        return ans;
    }
};














