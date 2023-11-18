class Solution {
public:
    vector<int> freq;
    void freqSort(vector<int>& nums,int n){
        int M=*max_element(nums.begin(), nums.end());
        freq.assign(M+1, 0);
        #pragma unroll
        for(int x: nums)
            freq[x]++;
        int i=0;
        #pragma unroll
        for(int x=0; x<=M; x++){
            int f=freq[x];
            if (f==0) continue;
            fill(nums.begin()+i, nums.begin()+(i+f), x);
            i+=f;
        }
    }

    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        freqSort(nums, n);

        int freq=0, l=0;
        long long sum=0;
        #pragma unroll
        for(int r=0; r<n; r++){
            long long x=nums[r];
            sum+=x;
            #pragma unroll
            while((r-l+1)*x-sum>k){
               sum-=nums[l++]; 
            }
            freq=max(freq, r-l+1);
        }       
        return freq;
    }
};