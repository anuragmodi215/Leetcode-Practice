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
        ListNode* ptr = l1;
        ListNode* ptr2=l2;
        
        ListNode* temp = new ListNode(-1);
        ListNode* res=temp;
        int carry =0;
        while(ptr and ptr2){
            ListNode* curr = new ListNode();
            int a=ptr->val;
            int b=ptr2->val;
            int sum = a+b+carry;
            
            curr->val = sum%10;
            carry =sum/10;
            
            res->next = curr;
            res=res->next;
            
            ptr=ptr->next;
            ptr2 = ptr2->next;
        }
        
        while(ptr){
            ListNode* curr = new ListNode();
            int a = ptr->val;
            int sum=a+carry;
            curr->val = sum%10;
            carry=sum/10;
            res->next = curr;
            res=res->next;
            ptr=ptr->next;
        }
        
         while(ptr2){
            ListNode* curr = new ListNode();
            int a = ptr2->val;
            int sum=a+carry;
            curr->val = sum%10;
            carry=sum/10;
            res->next = curr;
            res=res->next;
            ptr2=ptr2->next;
        }
        if(carry){
            ListNode* curr = new ListNode();
            curr->val = carry;
            res->next = curr;
        }
        return temp->next;
    }
};