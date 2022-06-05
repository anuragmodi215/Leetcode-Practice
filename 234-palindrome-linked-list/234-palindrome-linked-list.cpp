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
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * curr = slow;
        ListNode * next;
        ListNode * prev = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode * secondHead = prev;
        while(head and secondHead){
            if(head->val!=secondHead->val){
                return false;
            }
            head = head->next;
            secondHead=secondHead->next;
        }
        return true;
    }
};