class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>front,back;
        int i=0,j=costs.size()-1;
        long long sum=0;
    
        while(k!=0){
            
            while(front.size()<candidates&&(i<=j))front.push(costs[i++]);
            while(back.size()<candidates&&(j>=i))back.push(costs[j--]);
            
            int fro=front.size()>0?front.top():INT_MAX;
            int bac=back.size()>0?back.top():INT_MAX;
            
            if(fro<=bac){
                sum+=fro;
                front.pop();
            }
            else{
                sum+=bac;
                back.pop();
            }
                k--;
            
        }
        return sum;
    }
        
        
};