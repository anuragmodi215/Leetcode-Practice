/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* first = headA;
        ListNode* second = headB;
        while(first and second){
            if(first==second) return first;
            first = first->next;
            second = second->next;
            if(first==second) return first;
            if(first==NULL) first = headB;
            if(second==NULL) second = headA;
        }
        return NULL;
    }
};