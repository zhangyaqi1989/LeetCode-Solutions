class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ids_[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = ids_.find(id);
        string start_station = it->second.first;
        int start_time = it->second.second;
        ids_.erase(it);
        pair<string, string> ticket = {start_station, stationName};
        if (times_.find(ticket) == times_.end()) {
            times_[ticket] = {t - start_time, 1};
        } else {
            times_[ticket].first += t - start_time;
            times_[ticket].second += 1;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> ticket = {startStation, endStation};
        auto & p = times_[ticket];
        return (double) p.first / p.second;
    }
    
private:
    map<int, pair<string, int>> ids_;
    map<pair<string, string>, pair<long long, int>> times_;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
