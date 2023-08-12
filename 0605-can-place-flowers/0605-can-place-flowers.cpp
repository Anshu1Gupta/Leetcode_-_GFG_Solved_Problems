class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n=flowerbed.size();
        if(n==1){
           if(k==1&&flowerbed[0]==1)return false;
            else return true;
        }
        if(n==2){
            if(k==1){
                if(flowerbed[0]==1||flowerbed[1]==1)return false;
                return true;
            }
            if(k==0)return true;
            
            else return false;
        }
        
        if(flowerbed[0]==0&&flowerbed[1]==0)flowerbed[0]=1,k--;
        if(flowerbed[n-1]==0&&flowerbed[n-2]==0)flowerbed[n-1]=1,k--;
         if(k<=0)return true;
        
        for(int i=1;i<n-2;i++){
            if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0){
                flowerbed[i]=1;
                k--;
            }
            
            if(k<=0)return true;
        }
        
        return false;
        
        
    }
};