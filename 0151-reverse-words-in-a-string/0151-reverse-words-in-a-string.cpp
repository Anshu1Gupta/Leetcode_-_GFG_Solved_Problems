class Solution {
public:
    void reverse(string &s){
        int n=s.length();
        int low=0,high=n-1;
        while(low<=high){
            swap(s[low],s[high]);
            low++,high--;
        }
    }
    string reverseWords(string p) {
        string s;
        for(int i=0;i<p.length();i++){
            if(p[i]==' '){
                if(s.empty()||s.back()!=' ')s+=p[i];
            }
            else s+=p[i];
        }
        reverse(s);
        string str;
        
        int end=0;
        int start=0;
        int n=s.length();
        
        while(end<n){
            while(start<n&&s[start]==' ')start++;
            end=start;
            while(end<n&&s[end]!=' ')end++;
            
            int low=start;
            int high=end-1;
            while(low<=high){
                swap(s[low++],s[high--]);
            }
            start=end;
        }
        
        while(!s.empty()&&s.back()==' ')s.pop_back();
        int i=0;
        for(;i<s.length();i++){
            if(s[i]!=' ')break;
        }
        while(i--){
            s.erase(s.begin());
        }
        return s;
    }
};