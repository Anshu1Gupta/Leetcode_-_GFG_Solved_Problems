class Solution {
public:
    int finMaxiF(string &str, int k){
        int ans=0,n=str.length();
        int i=0,j=0;
        while(j<n){
            if(str[j]=='T')k--;
            
            if(k<0){
                while(str[i]=='F'){
                    i++;
                }
                i++;k++;
            }
            
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
    int finMaxiT(string &str, int k){
        int ans=0,n=str.length();
        int i=0,j=0;
        while(j<n){
            if(str[j]=='F')k--;
            
            if(k<0){
                while(str[i]=='T'){
                    i++;
                }
                i++;k++;
            }
            
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int t= finMaxiT(answerKey,k);
        int f= finMaxiF(answerKey,k);
        return max(t,f);
    }
};