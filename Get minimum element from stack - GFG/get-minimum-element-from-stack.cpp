//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    stack<int>st,minStack;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           if(!minStack.empty())
           return minStack.top();
           //Write your code here'
           else return -1;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
        //   int val=0;
           if(!minStack.empty()&&minStack.top()==st.top()){
               minStack.pop();
               
           }
           if(st.empty())return -1;
           int val=st.top();
           st.pop();
           return val;
           
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(minStack.empty()||minStack.top()>=x){
               minStack.push(x);
           }
           st.push(x);
           //Write your code here
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends