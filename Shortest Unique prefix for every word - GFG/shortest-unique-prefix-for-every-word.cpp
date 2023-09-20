//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
struct Node{
    Node*links[26];
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void addKey(char ch,Node*node){
        links[ch-'a']=node;
    }
    
    Node* getKey(char ch){
        return links[ch-'a'];
    }
    
    int prefix=0;
    void increasePrefix(){
        prefix++;
    }
    void decreasePrefix(){
        prefix--;
    }
    int getPrefixCount(){
        return prefix;
    }
    
};
class Trie{
    private:
    Node*root;
    public:
    
    Trie(){
        root=new Node();
    }
    
    
    void insertWord(string &word){
        Node*node=root;
        
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->addKey(word[i],new Node());
            }
            
            node=node->getKey(word[i]);
            node->increasePrefix();
        }
    }
    
    string givePrefix(string &word){
        string str="";
        
        Node*node=root;
        
        for(int i=0;i<word.size();i++){
            node=node->getKey(word[i]);
            str+=word[i];
            if(node->getPrefixCount()==1){
                return str;
            }
        }
        return word;
    }
};
class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        Trie trie;
        
        for(int i=0;i<n;i++){
            trie.insertWord(arr[i]);
        }
        
        vector<string>ans;
        for(int i=0;i<n;i++){
           string g= trie.givePrefix(arr[i]);
            ans.push_back(g);
        }
        //code here
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends