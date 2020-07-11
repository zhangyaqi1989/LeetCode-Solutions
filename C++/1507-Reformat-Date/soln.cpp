class Solution {
public:
    string reformatDate(string date) {
        vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        istringstream iss(date);
        string day_str, month_str, year_str;
        iss >> day_str >> month_str >> year_str;
        int day = stoi(day_str);
        int month = find(months.begin(), months.end(), month_str) - months.begin() + 1;
        int year = stoi(year_str);
        return IntToString(year) + "-" + IntToString(month) + "-" + IntToString(day);
    }
    
    string IntToString(int num) {
        if(num <= 9) return "0" + to_string(num);
        else return to_string(num);
    }
};
