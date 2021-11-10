/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parentTrack){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();
            if(node->left){
                parentTrack[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parentTrack[node->right]=node;
                q.push(node->right);
            }
        }
    }
                 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentTrack;
        parents(root,parentTrack);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        int curr_lv=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_lv==k) break;
            else curr_lv++;
            for(int i=0; i<size; i++){
                TreeNode* node=q.front(); q.pop();
                if(node->left and !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right and !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parentTrack[node] and !visited[parentTrack[node]]){
                    q.push(parentTrack[node]);
                    visited[parentTrack[node]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            ans.push_back(t->val);
        }
        return ans;
    }
};
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 

                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 