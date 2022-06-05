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
        
        ListNode * newHead = new ListNode(-1);
        newHead->next = head;
        
        ListNode * temp = newHead;
        while(temp and temp->next){
            if(temp->next->val==val){
                temp->next = temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return newHead->next;
    }
};