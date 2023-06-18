class UndergroundSystem {
private:
    map<pair<string,string>, pair<int,int>> travelTimes; // <<start,end>, <sum of travel times for this route, times route was traveled>>
    unordered_map<int, pair<string,int>> passengerStartedAt; // <id, <start, time>>
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        passengerStartedAt[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = passengerStartedAt[id];
        passengerStartedAt.erase(id);

        travelTimes[{startStation, stationName}].first += t - startTime;
        travelTimes[{startStation, stationName}].second++; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)travelTimes[{startStation, endStation}].first / travelTimes[{startStation, endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
 
 //https://leetcode.com/problems/design-underground-system/