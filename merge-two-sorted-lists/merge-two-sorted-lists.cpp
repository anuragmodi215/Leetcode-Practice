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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * t = l1;
        ListNode * y = l2;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *temp = new ListNode();
        ListNode *ptr = temp;
        while(t !=NULL and y != NULL){
                       
            if(t->val < y->val){
                ptr->next = t;
                t=t->next;
                ptr = ptr->next;
            }
            else{
                ptr->next = y;
                ptr = ptr->next;
                y=y->next;
            }
            
        }
        while(t){
            ptr->next = t;
            t=t->next;
            ptr = ptr->next;
        }
        while(y){
            ptr->next = y;
            y=y->next;
            ptr = ptr->next;
        }
        return temp->next;
    }
};