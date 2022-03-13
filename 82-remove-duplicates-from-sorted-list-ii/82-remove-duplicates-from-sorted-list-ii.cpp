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
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* ptr = dummy;
        while(ptr->next and ptr->next->next){
            if(ptr->next->val != ptr->next->next->val){
                ptr=ptr->next;
            }
            else{
                int val = ptr->next->val;
                while(ptr->next and ptr->next->val==val){
                    ptr->next = ptr->next->next;
                }
            }
        }
        return dummy->next;
    }
};