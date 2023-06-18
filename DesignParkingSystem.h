class ParkingSystem {
private: 
    vector<int> limit = vector<int>(4);
    vector<int> current = vector<int>(4, 0);
public:
    ParkingSystem(int big, int medium, int small) {
        limit[1] = big;
        limit[2] = medium;
        limit[3] = small;
    }
    
    bool addCar(int carType) {
        if(current[carType] == limit[carType])
            return false;

        current[carType]++;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
 
 //https://leetcode.com/problems/design-parking-system/
 
 // as cars are only added we could also just use one vector and check if there is space left like that