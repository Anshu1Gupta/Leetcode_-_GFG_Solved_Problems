class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
       priority_queue<int,vector<int>,greater<int>>front,back;
        long long sum=0;
        int i=0,j=costs.size()-1;
       while(k--){
           while(front.size()<candidates&& i<=j)front.push(costs[i++]);
           while(back.size()<candidates&& j>=i)back.push(costs[j--]);
           
         
           int first=front.size()>0?front.top():INT_MAX;
           int second=back.size()>0?back.top():INT_MAX;
           if(first<=second){
               sum+=first;
               front.pop();
           }
           else{
               sum+=second;
               back.pop();
           }
       }
        return sum;
    }
};