class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        const int n=garbage.size();
        const char* GPM="GPM";
        int time=0;
        bool t[3]={0}; 
        #pragma unroll
        for(int i=n-1; i>0; i--){
            string&& x=move(garbage[i]);// Use right value not a copy
            time+=x.size();
            #pragma unroll
            for(int j=0; j<3; j++){
                if (!t[j]){
                    if(x.find(GPM[j])!=-1){
                        t[j]=1;
                        //compute the travel time for truck for GPM[j]
                        time+=accumulate(travel.begin(), travel.begin()+i,0);
                    } 
                } 
            }
        }
        return time+garbage[0].size();
    }
};