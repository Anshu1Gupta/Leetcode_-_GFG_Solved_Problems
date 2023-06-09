class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0;
        int j=letters.size()-1;
        char ans=letters[0];
        while(i<=j){
            int mid=(i+j)/2;
            if(letters[mid]>target){
                ans=letters[mid];
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};