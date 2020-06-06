struct Transaction {
    string name;
    int time;
    int amount;
    string city;
    string str;
    Transaction(const string & s) {
        istringstream iss(s);
        vector<string> tokens;
        string token;
        while(getline(iss, token, ',')) tokens.push_back(token);
        assert(tokens.size() == 4);
        name = tokens[0];
        time = stoi(tokens[1]);
        amount = stoi(tokens[2]);
        city = tokens[3];
        str = s;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        // same name, different city, within 60 min
        vector<Transaction> trans;
        for(const auto & t : transactions) {
            trans.push_back(Transaction(t));
        }
        const int kMaxAmount = 1000;
        const int kMinTime = 60;
        vector<string> ans;
        const int kN = trans.size();
        for(int i = 0; i < kN; ++i) {
            const auto & t = trans[i];
            if (t.amount > kMaxAmount) {
                ans.push_back(t.str);
                continue;
            }
            bool valid = true;
            for(int j = 0; j < kN; ++j) {
                if (j == i) continue;
                if (trans[j].name == t.name && abs(trans[j].time - t.time) <= kMinTime && trans[j].city != t.city) {
                    valid = false;
                    break;
                }
            }
            if (!valid) ans.push_back(t.str);
        }
        return ans;
    }
};
