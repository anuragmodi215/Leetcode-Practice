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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * temp = head; 
        ListNode* ptr = head;
        ListNode* first=NULL;
        ListNode * second = NULL;
        int cnt=1;
        while(cnt<k){
            temp = temp->next;
            cnt++;
        }
        
        if(cnt==k){
            first = temp;
        }
        while(temp->next){
            temp = temp->next;
            ptr = ptr->next;
        }
        int number = ptr->val;
        ptr->val = first->val;
        first->val = number;
        return head;
    }
};


