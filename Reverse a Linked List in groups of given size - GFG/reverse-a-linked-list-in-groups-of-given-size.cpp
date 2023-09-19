//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    pair<struct node*,struct node*> rev(struct node* head,int k){
        if(head==NULL)return {NULL,NULL};
        struct node* p=NULL,*q=NULL,*r=head;
        while(r!=NULL&&k){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
            k--;
        }
        return {q,r};
    }
    public:
    struct node *reverse (struct node *head, int k)
    { 
    
    struct node*entry=NULL,*res=NULL,*end=NULL;
    pair<struct node*,struct node*>revPair=rev(head,k);
    
    entry=revPair.first;
    res=entry;
    
    end=revPair.second;
    
    
    while(end!=NULL){
        
        while(entry->next!=NULL){
            entry=entry->next;
        }
        pair<struct node*,struct node*>revPair=rev(end,k);
        
        entry->next=revPair.first;
        end=revPair.second;
        
    }
    return res;
    
    }
};



//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends