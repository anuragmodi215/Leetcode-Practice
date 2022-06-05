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
    
    ListNode * merge(ListNode * a, ListNode * b){
        ListNode * first = a;
        ListNode * second = b;
        ListNode * temp = new ListNode(-1);
        ListNode * node = temp;
        while(first and second){
            if(first->val<second->val){
                temp->next = first;
                first=first->next;
            }
            else{
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }
        if(first==NULL){
            temp->next = second;
        }
        if(second==NULL){
            temp->next = first;
        }
        return node->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode * newHead = new ListNode(-1);
        int n = lists.size();
        for(int i=0; i<n; i++){
            newHead->next = merge(newHead->next,lists[i]);
        }
        return newHead->next;
    }
};