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
    ListNode* Reverse(ListNode*curr,ListNode*prev,ListNode*next){
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        return prev;
    }
    int lengthOfLinkedList(ListNode* head){
        ListNode* ptr = head;
        int n = 0;
        while(ptr){
            n++;
            ptr=ptr->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        int n = lengthOfLinkedList(head);
        k=k%n;
        if(n==k or k==0) return head;
        ListNode* dummy = Reverse(head,NULL,NULL);
        ListNode* ptr = dummy;
        
        
        for(int i=1; i<k; i++){
           ptr=ptr->next; 
        }
        
        ListNode* head1 = dummy;
        ListNode* head2 = ptr->next;
        cout<<head2->val;
        ptr->next = NULL;
        
        ListNode* first = Reverse(head1,NULL,NULL);
        ListNode* second = Reverse(head2,NULL,NULL);
        
        ptr = first;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next = second;
        return first;
    }
};