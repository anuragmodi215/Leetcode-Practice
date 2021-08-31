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
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        ListNode* newnode = new ListNode();
        ListNode* temp;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        temp = newnode;
        while(ptr1 != NULL and ptr2 != NULL){
         
            if(ptr1->val < ptr2->val){
                temp->next=ptr1;
                ptr1 = ptr1->next;
                temp = temp->next;
            }
            else{
                temp->next = ptr2;
                ptr2 = ptr2->next;
                temp = temp->next;
            }
        }
        
        while(ptr1 !=NULL){
            temp->next = ptr1;
            temp = temp->next;
            ptr1 = ptr1->next;
        }
        while(ptr2!=NULL){
            temp->next = ptr2;
            ptr2 = ptr2->next;
            temp = temp->next;
        }
        return newnode->next;
        
    }
};