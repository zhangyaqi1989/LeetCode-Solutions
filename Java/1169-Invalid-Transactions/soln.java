class Transaction {
    public String name;
    public int time;
    public int amount;
    public String city;
    public String str;
    
    public Transaction(String s) {
        str = s;
        String[] tokens = s.split(",");
        assert(tokens.length == 4);
        name = tokens[0];
        time = Integer.parseInt(tokens[1]);
        amount = Integer.parseInt(tokens[2]);
        city = tokens[3];
    }
    
}

class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        int n = transactions.length;
        Transaction [] trans = new Transaction[n];
        for(int i = 0; i < n; ++i) {
            trans[i] = new Transaction(transactions[i]);
        }
        List<String> ans = new ArrayList<>();
        final int kMaxAmount = 1000;
        final int kMinTime = 60; // minutes
        for(int i = 0; i < n; ++i) {
            Transaction t = trans[i];
            if (t.amount > kMaxAmount) {
                ans.add(t.str);
                continue;
            }
            boolean valid = true;
            for(int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (trans[j].name.equals(t.name) && Math.abs(trans[j].time - t.time) <= kMinTime && !trans[j].city.equals(t.city)) {
                    valid = false;
                    break;
                }
            }
            if (!valid) ans.add(t.str);
        }
        return ans;
    }
}
