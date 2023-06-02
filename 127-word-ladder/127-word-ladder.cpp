class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>set;
        for(auto it: wordList){
            set.insert(it);
        }
        queue<pair<string,int>>pq;
        pq.push({beginWord,1});
        
        
       while(!pq.empty()){
           string str=pq.front().first;
           int level=pq.front().second;
           pq.pop();
           
           string n=str;
           for(int i=0;i<str.length();i++){
               for(char c='a';c<='z';c++){
                   n[i]=c;
                   if(set.find(n)!=set.end()){
                       set.erase(n);
                       pq.push({n,level+1});
                       if(n==endWord)return level+1;
                   }
                   n=str;
               }
               
           }
       }
        
        return 0;
    }
};