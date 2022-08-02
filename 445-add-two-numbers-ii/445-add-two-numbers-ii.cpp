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

// void helper(ListNode* l1, ListNode* l2, ListNode* dummy, int carry){
//         if(l1->next and l2->next){
//             ListNode * temp = new ListNode();
//             dummy->next = temp;
//             helper(l1->next, l2->next, dummy->next, carry);
//         }
//         else if(!l2->next){
//             ListNode * temp = new ListNode();
//             dummy->next = temp;
//             helper(l1->next, l2, dummy->next, carry);
//         }
//         else if(!l1->next){
//             ListNode * temp = new ListNode();
//             dummy->next = temp;
//             helper(l1, l2->next, dummy->next, carry);
//         }
//         int val = l1->val+l2->val+ carry;
//         carry = val/10;
//         val = val%10;
//         dummy->val = val;
        
//     }
class Solution {
public:
    
    ListNode * reverseList(ListNode * l){
        ListNode* prev=NULL;
        ListNode* curr = l;
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy = new ListNode();
        //helper(l1,l2,dummy,0);
        ListNode * p=reverseList(l1);
        ListNode * t=reverseList(l2);
        //ListNode * dummy = new ListNode();
        ListNode * d = dummy;
        int carry=0;
        while(p and t){
            ListNode * node = new ListNode();
            dummy->next = node;
            int val = p->val+t->val+carry;
            carry = val/10;
            val = val%10;
            dummy->next->val = val;
            p=p->next;
            t=t->next;
            dummy = dummy->next;
        }
        while(p){
            ListNode * node = new ListNode();
            dummy->next = node;
            int val = p->val+carry;
            carry = val/10;
            val = val%10;
            dummy->next->val = val;
            p=p->next;
            dummy = dummy->next;
        }
        while(t){
            ListNode * node = new ListNode();
            dummy->next = node;
            int val = t->val+carry;
            carry = val/10;
            val = val%10;
            dummy->next->val = val;
            t=t->next;
            dummy = dummy->next;
        }
        if(carry){
            // ListNode * node = new ListNode();
            dummy->next =new ListNode(carry);
            // dummy->next->val = carry;
        }
        d->next = reverseList(d->next);
        return d->next;
    }
};












