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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        while(head and head->val==val){
            head = head->next;
        }
          ListNode *t=head;
      
        while(t and t->next){
            if(t->next->val == val){
                
                t->next = t->next->next;
            }
            else
            t=t->next;
        }
        return head;
    }
};