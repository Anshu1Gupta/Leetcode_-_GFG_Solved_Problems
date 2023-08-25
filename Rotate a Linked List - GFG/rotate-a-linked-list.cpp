//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    int sizeOf(Node*temp){
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        return size;
    }
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(head)
        int size=sizeOf(head);
        k=k%size;
        if(k==0)return head;
        Node*start=head;
        
        Node*temp=head;
        while(k>1){
            temp=temp->next;
            k--;
        }
        Node*rem=temp->next;
        Node*ans=rem;
        temp->next=NULL;
        while(rem->next!=NULL){
            rem=rem->next;
        }
        rem->next=start;
        return ans;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends