//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
   Node* reverse(Node*head){
        Node*p=NULL,*q=NULL,*r=head;
        while(r!=NULL){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        return q;
    }
    Node *compute(Node *head)
    {
        if(head==NULL||head->next==NULL)return head;
        // your code goes here
        // 3 2 6 5 11 10 15 12
        head=reverse(head);
        int maxi=head->data;
        Node*ans=head;
    
        Node*temp=head;
        Node*tail=new Node(-1);
        while(temp!=NULL){
            if(temp->data>=maxi){
                tail->next=temp;
                tail=tail->next;
                maxi=max(maxi,temp->data);
            }
            temp=temp->next;
        }
        
        tail->next=NULL;
       
       ans=reverse(ans);
       return ans;
    }
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends