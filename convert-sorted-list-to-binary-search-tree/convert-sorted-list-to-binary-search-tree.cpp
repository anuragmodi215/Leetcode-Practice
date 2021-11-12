/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<int>v,int strt,int end){
        if(strt>end) return NULL;
        int mid = strt+(end-strt)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = solve(v, strt,mid-1);
        root->right = solve(v,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int>v;
        ListNode* tmp = head;
        
        while(tmp){
            v.push_back(tmp->val);
            tmp=tmp->next;
        }
        cout<<head->val;
        return solve(v,0,v.size()-1);
    }
};













