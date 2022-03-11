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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k==0) return head;
        
        ListNode* ptr = head;
        int n=1;
        while(ptr->next){
            n++;
            ptr=ptr->next;
        }
        ptr->next=head;
        k=k%n;
        for(int i=1; i<=n-k; i++){
            ptr=ptr->next;
        }
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};