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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * newHead = new ListNode(-1);
        ListNode * temp = newHead;
        ListNode * first = l1;
        ListNode * second = l2;
        int carry=0;
        while(first and second){
            ListNode * list = new ListNode(0);
            temp->next = list;
            int a = first->val;
            int b = second->val;
            int sum = a+b+carry;
            carry = sum/10;
            list->val = sum%10;
            temp = temp->next;
            first = first->next;
            second = second->next;
        }
        while(first){
            ListNode * list = new ListNode(0);
            temp->next = list;
            int a = first->val;
            int sum = a+carry;
            carry = sum/10;
            list->val = sum%10;
            temp = temp->next;
            first = first->next;
        }
        while(second){
            ListNode * list = new ListNode(0);
            temp->next = list;
            int b = second->val;
            int sum = b+carry;
            list->val = sum%10;
            carry = sum/10;
            temp=temp->next;
            second = second->next;
        }
        if(carry){
            ListNode * list = new ListNode(0);
            temp->next = list;
            list->val = carry;
        }
        return newHead->next;
    }
};















