/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(head==NULL)return head;
        
       Node* original=head;
        
       while(original!=NULL){
           Node* temp=original->next;
           original->next= new Node(original->val);
           original->next->next=temp;
           original=temp;
       }
        
        
       original=head;
       while(original!=NULL){
           if(original->next!=NULL){
               original->next->random=original->random!=NULL?original->random->next:NULL;
           }
           original=original->next->next;
       }
        
       original=head;
        Node* copy=head->next;
        Node* ans=copy;
        while(original!=NULL){
            original->next=original->next->next;
            if(copy->next){
                copy->next=copy->next->next;
            }
            else{
                copy->next=NULL;
            }
            
            original=original->next;
            copy=copy->next;
        }
        return ans;
        
    }
};