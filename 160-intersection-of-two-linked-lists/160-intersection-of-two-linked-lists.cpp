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
    ListNode * traverse(ListNode* temp, int times){
        for(int i=0; i<times; i++){
            temp=temp->next;
        }
        return temp;
    }
    
    ListNode * checkForIntersection(ListNode * headA, ListNode * headB){
        while(headA and headB){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*first = headA;
        ListNode*second = headB;
        
        int firstLength=0;
        int secondLength=0;
        
        while(first or second){
            if(first){
                firstLength++;
                first=first->next;
            }
            if(second){
                secondLength++;
                second = second->next;
            }
        }
        
        int difference=0;
        ListNode* temp = NULL;
        if(firstLength>secondLength){
            difference = firstLength-secondLength;
            temp = headA;
            temp = traverse(temp,difference);
            return checkForIntersection(temp,headB);
        }
        else{
            difference = secondLength-firstLength;
            temp = headB;
            temp = traverse(temp,difference);
            return checkForIntersection(temp,headA);
        }
        return NULL;
        
    }
};







