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
    ListNode* partition(ListNode* head, int x) {
        ListNode * l = new ListNode();
        ListNode * g = new ListNode();
        ListNode * less = l;
        ListNode * greater=g;
        ListNode * temp = head;
        while(temp){
            if(temp->val<x){
                less->next = temp;
                less = less->next;
            }
            else{
                greater->next = temp;
                greater = greater->next;
            }
            temp = temp->next;
        }
        greater->next = NULL;
        less->next = g->next;
        return l->next;
    }
};