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
    if(head==NULL){
    Node*dummy=head;
head=NULL;
return dummy;
    }
    if(head->next==NULL){
        Node*dummy=new Node(head->val);
        if(head->random==head)dummy->random=dummy;
        
        return dummy;
    }
    Node*rem;
    Node*temp=head;
    while(temp!=NULL){
          Node*dummy=new  Node(temp->val);
          rem=temp->next;
          temp->next=dummy;
          dummy->next=rem;
          temp=dummy->next;;
    }
     temp=head;
    Node*ans=temp->next;;

    
    while(temp!=NULL){
        rem=temp->next->next;
        if(temp->random==NULL)
            temp->next->random=NULL;
        else
            temp->next->random=temp->random->next;
    temp=rem;
    }
    temp=head;

    while(temp!=NULL){
        rem=temp->next;
        temp->next=rem->next;
        if(temp->next==NULL)break;
        rem->next=temp->next->next;
        temp=temp->next;
    }

    
return ans;

}  
    
};