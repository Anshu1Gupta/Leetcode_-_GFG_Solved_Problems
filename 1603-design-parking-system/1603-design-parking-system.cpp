class ParkingSystem {
public:
    unordered_map<int,int>mp;
    ParkingSystem(int big, int medium, int small) {
        if(big){
            mp[1]+=big;
        }
        if(medium){
            mp[2]+=medium;
        }
        if(small){
            mp[3]+=small;
        }
    }
    
    bool addCar(int carType) {
        if(mp[carType]!=0){
            mp[carType]--;return true;
        }
        else return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */