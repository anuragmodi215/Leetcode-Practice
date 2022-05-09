/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>mp;
        ListNode* ptr = headA;
        while(ptr){
            mp.insert(ptr);
            ptr = ptr->next;
        }
        ptr = headB;
        while(ptr){
            if(mp.find(ptr)!=mp.end()){
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }
};