class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0;
        int bob=0;
        
        int a=0,b=0;
        for(int i=0;i<colors.size();i++){
            if(colors[i]=='A'){
                bob+=max(0,b-2);
                b=0;
                a++;
            }
            else{
                alice+=max(0,a-2);
                a=0;
                b++;
            }
        }
        bob+=max(0,b-2);
        alice+=max(0,a-2);
        
        if(alice>bob)return true;
        return false;
    }
};