class ParkingSystem {
public:
   int one=0,two=0,three=0;
    ParkingSystem(int big, int medium, int small) {
        if(big){
           one+=big;
        }
        if(medium){
            two+=medium;
        }
        if(small){
            three+=small;
        }
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(one){
                one--;return true;
            }
            else return false;
        }
       else if(carType==2){
            if(two){
                two--;return true;
            }
            else return false;
        }
        else if (carType==3){
            if(three){
            three--;return true;
            }
            else return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */