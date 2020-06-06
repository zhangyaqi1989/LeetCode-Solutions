class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> opens(rooms.size(), false);
        opens[0] = true;
        stack<int> s;
        s.push(0);
        while (s.size()) {
            int room = s.top();
            s.pop();
            for (auto key : rooms[room]) {
                if(!opens[key]) {
                    opens[key] = true;
                    s.push(key);
                }
            }
        }
        return all_of(opens.cbegin(), opens.cend(), [](bool i) {return i;});
    }
};