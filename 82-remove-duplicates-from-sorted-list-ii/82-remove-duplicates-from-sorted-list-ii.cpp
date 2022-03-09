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
        map<int,int>mp;
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode*ptr = head;
        
        while(ptr){
            mp[ptr->val]++;
            ptr = ptr->next;
        }
        for(auto i:mp){
            if(i.second>1){
                i.second = 0;
            }
        }
        
        for(auto i:mp){
            if(i.second==1){
                temp->next->val = i.first;
                temp=temp->next;                
            }

        }
        if(temp->next == head) return NULL;
        temp->next = NULL;
        return head;
    }
};