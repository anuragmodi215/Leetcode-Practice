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
    unordered_map<int,int>mp;
    int index=0;
    TreeNode* myTree(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left>right) return NULL;
        TreeNode*root = new TreeNode(preorder[index++]);
        if(left==right) return root;
        int mid = mp[root->val];
        root->left = myTree(preorder,inorder,left,mid-1);
        root->right = myTree(preorder,inorder,mid+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]]=i;
        }
        return myTree(preorder,inorder,0,n-1);
    }
};