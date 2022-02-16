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
    ListNode* swapPairs(ListNode* head) {
        if(head and head->next){
           ListNode* curr=head;
           ListNode* nxt=curr->next;
           
           curr->next=nxt->next;
           nxt->next=curr;
           curr->next=swapPairs(curr->next);
           return nxt;
        }
        else return head;
    }
};