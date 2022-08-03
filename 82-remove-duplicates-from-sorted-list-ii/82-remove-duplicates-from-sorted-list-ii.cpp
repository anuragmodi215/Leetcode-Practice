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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * temp = dummy;
        while(temp->next and temp->next->next){
            if(temp->next->val != temp->next->next->val)
                temp = temp->next;
            else{
                int val = temp->next->val;
                while(temp->next and temp->next->val == val){
                    temp->next = temp->next->next;
                }
            }
        }
        return dummy->next;
    }
};