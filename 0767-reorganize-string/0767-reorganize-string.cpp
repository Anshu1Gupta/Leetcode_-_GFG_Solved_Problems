class Solution {
    
public:
   
    string reorganizeString(string s) {
        vector<int>f(26,0);
       int n=s.size();
       for(int i=0;i<s.size();i++){
           f[s[i]-'a']++;
        if(f[s[i]-'a']>(n+1)/2)
        return "";
       }
       priority_queue<pair<int,char>>pq;
       for(int i=0;i<26;i++){
        if(f[i]!=0){
            pq.push({f[i],(char)i+'a'});
        }
       }
        
        string str="";
        
        while(pq.size()>=2){
            auto it1=pq.top();pq.pop();
            auto it2=pq.top();pq.pop();
            
                str+=it1.second;
                str+=it2.second;
            
            
            if(it1.first>1){
                pq.push({it1.first-1,it1.second});
            }
            if(it2.first>1){
                pq.push({it2.first-1,it2.second});
            }
        }
        if(pq.size()==1){
            str+=pq.top().second;
        }
        return str;
        
        
    }
};