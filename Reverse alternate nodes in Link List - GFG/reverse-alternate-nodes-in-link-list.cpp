//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    struct Node*reverse(struct Node*head){
        struct Node*p=NULL,*q=NULL,*r=head;
        
        while(r!=NULL){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        return q;
    }
    public:
    void rearrange(struct Node *odd)
    {
        if(odd==NULL||odd->next==NULL)return ;
        //add code here
       struct Node* leftTail=new Node(-1);
       struct Node* rightTail=new Node(-1);
       
       struct Node*ans=leftTail;
       struct Node*rightHead=rightTail;
       
       struct Node*temp=odd;
       int i=0;
       while(temp!=NULL){
           if(i%2==0){
               leftTail->next=temp;
               leftTail=temp;
           }
           else{
               rightTail->next=temp;
               rightTail=temp;
           }
           temp=temp->next;
           i++;
       }
       leftTail->next=NULL;
       rightTail->next=NULL;
       
       rightHead=reverse(rightHead->next);
       leftTail->next=rightHead;
       odd=ans->next;
       
       
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends