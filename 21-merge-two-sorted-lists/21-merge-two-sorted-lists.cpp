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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * temp = new ListNode(-1);
        ListNode * newHead = temp;
        ListNode * first = list1;
        ListNode * second = list2;
        
        while(first and second){
            if(first->val <= second->val){
                temp->next = first;
                temp=temp->next;
                first = first->next;
            }
            else{
                temp->next = second;
                temp=temp->next;
                second = second->next;
            }
        }
        while(first){
            temp->next = first;
            first=first->next;
            temp=temp->next;
        }
        while(second){
            temp->next = second;
            second = second->next;
            temp = temp->next;
        }
        return newHead->next;
    }
};