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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next==NULL) return NULL;
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        //if(fast=NULL or fast->next==NULL)
        if(fast!=slow) return NULL;
        fast = head;
        while(fast!=slow){
            slow = slow->next;
            fast = fast->next;
            if(slow==fast) break;
        }
        return slow;
    }
};