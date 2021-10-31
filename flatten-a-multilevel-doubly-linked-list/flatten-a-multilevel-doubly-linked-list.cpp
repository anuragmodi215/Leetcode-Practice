/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        
        Node* temp=head;
        stack<Node*>s;
        Node* ptr;
        while(temp->next or temp->child){
            if(temp->child){
                if(temp->next){
                    temp->next->prev=NULL;
                }
                
                if(temp->next){
                    s.push(temp->next);
                }
                
                temp->child->prev=temp;
                temp->next=temp->child;
                temp->child=NULL;
                temp=temp->next;
            }
            else temp=temp->next;
        }
        while(!s.empty()){
            ptr=s.top();
            s.pop();
            temp->next=ptr;
            ptr->prev=temp;
            while(temp->next){
                temp=temp->next;
            }
        }
        return head;
    }
};