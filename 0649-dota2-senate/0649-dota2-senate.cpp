class Solution {
public:
    string predictPartyVictory(string senate) {
        stack<int>st;
        int n=senate.size();
        
           queue<int>dir,rad;
            
            for(int i=0;i<senate.size();i++){
                if(senate[i]=='D'){
                    dir.push(i);
                }
                else{
                    rad.push(i);
                }
            }
            
        int i=0;
            while(!dir.empty()&&!rad.empty()){
                if(rad.front()>dir.front()){
                    dir.push(i+n);
                }
                else{
                    rad.push(i+n);
                }
                
                dir.pop(),rad.pop();
                i++;
            }
            return rad.empty()==true?"Dire":"Radiant";
            
            
        
        
    }
};