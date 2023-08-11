class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>ans;
        int i=0;
        int j=0;
        int n=chars.size();
        
        while(j<n){
            while(j<n&&chars[i]==chars[j]){
                j++;
            }
            if(j-i==1){
                ans.push_back(chars[i]);
            }
            else{
                ans.push_back(chars[i]);
                int len=j-i;
                string temp;
                while(len!=0){
                    int x=len%10;
                    char y=x+'0';
                    temp+=y;
                    len=len/10;
                }
                for(int i=temp.size()-1;i>=0;i--)
                     ans.push_back(temp[i]);
            }
            
            cout<<chars[i]<<' '<<j-i<<endl;
            i=j;
            
        }
        
        chars=ans;
        return ans.size();
    }
};