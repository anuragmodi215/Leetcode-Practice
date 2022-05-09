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
class Solution {
public:
    ListNode * helper(ListNode * a, ListNode * b){
        ListNode * first = a;
        ListNode * second = b;
        ListNode * dummy = new ListNode(-1);
        ListNode * temp = dummy;
        while(first and second){
            if(first->val<=second->val){
                temp->next = first;
                first = first->next;
            }
            else{
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }
        if(first) temp->next = first;
        else if(second) temp->next = second;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * dummy = new ListNode(-1);
        int n = lists.size();
        for(int i=0; i<n; i++){
            dummy->next = helper(dummy->next,lists[i]);
        }
        return dummy->next;
    }
};