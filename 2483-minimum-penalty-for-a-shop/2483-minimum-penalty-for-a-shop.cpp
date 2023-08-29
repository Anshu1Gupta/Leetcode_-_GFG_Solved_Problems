class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        
        int countN=0;
        int countY=0,req=n+1;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y')countY++;
        }
        int ind=0;
        for(int i=0;i<n;i++){
            
            if(customers[i]=='N')countN++;
            if(customers[i]=='Y')countY--;
            
            if(customers[i]=='N'){
                   int pen=countN+countY-1;
                if(req>pen){
                   req=pen;
                    ind=i;
                }
            }
            else{
                int pen=countN+countY+1;
                if(req>pen){
                    req=pen;
                    ind=i;
                }
            }
        }
        
        return countN<req?n:ind;
        
       
    }
};