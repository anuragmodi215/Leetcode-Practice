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
    int lengthOfList(ListNode * head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* reverseK(ListNode * head, int k, int length){
        if(length<k) return head;
        int cnt=0;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next;
        
        while(curr and cnt<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if(next!=NULL){
            head->next = reverseK(next,k,length-k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int length = lengthOfList(head);
        return reverseK(head, k, length);
    }
};























