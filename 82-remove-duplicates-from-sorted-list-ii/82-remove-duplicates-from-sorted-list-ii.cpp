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
      
        ListNode* temp=new ListNode(-1000);
        temp->next = head;
        ListNode* ptr = temp;
        while(ptr->next and ptr->next->next){
            if(ptr->next->val!=ptr->next->next->val){
                ptr=ptr->next;
            }
            else{
                int value = ptr->next->val;
                while(ptr->next and ptr->next->val==value){
                    ptr->next = ptr->next->next;
                }
            }
        }
        
        return temp->next;
    }
};