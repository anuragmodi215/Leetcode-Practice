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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        
        ListNode *oddhead=head;
        ListNode *evenhead=head->next;
        ListNode *odder=oddhead;
        ListNode *evener=evenhead;
        
        while(odder->next!=NULL and evener->next!=NULL){
            if(odder->next->next){
            odder->next=odder->next->next;
            odder=odder->next;
            }
            else odder->next=NULL;
            
            if(evener->next->next){
            evener->next=evener->next->next;
            evener=evener->next;
            }
            else{
                evener->next=NULL;
            }
            
        }
        odder->next=evenhead;
        return oddhead;
    }
};