class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       vector<int>arr(32,0);
        int i=0;
        while(n!=0){
            int x=n%2;
            arr[i]=x;
            i++;
            n=n/2;
        }
        long long ans=0;
        for(int i=0;i<=31;i++){
            ans=ans+pow(2,31-i)*arr[i];
        }
        return ans;
    }
};
       //     n=n/10;
        // }
//         int i=0;
//         while(n!=0){
//             int rem=0;
//             rem=n%2;
//              arr[i]=rem;
//               n=n/2;
//               i++;
//     }

//         long long ans=0;
//         for(int i=0;i<32;i++){
//             ans+=arr[i]*pow(2,32-1-i);
//         }
//         return ans;
