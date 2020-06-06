class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int n = req_skills.length;
        Map<String, Integer> needed = new HashMap<>();
        for(int i = 0; i < n; ++i) needed.put(req_skills[i], i);
        int total = 1 << n;
        ArrayList<ArrayList<Integer>> dp = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        int m = people.size();
        for(int i = 0; i < m; ++i) temp.add(i);
        for(int i = 0; i < (1 << n); ++i) dp.add(new ArrayList<>(temp));
        dp.get(0).clear();
        for(int i = 0; i < m; ++i) {
            int cur_skill = 0;
            for(String skill : people.get(i)) {
                if (needed.containsKey(skill)) cur_skill |= (1 << needed.get(skill));
            }
            for(int j = 0; j < total; ++j) {
                int new_skill = (cur_skill | j);
                if (new_skill == j) continue;
                if (dp.get(new_skill).size() > dp.get(j).size() + 1) {
                    dp.get(new_skill).clear();
                    for(int idx : dp.get(j)) dp.get(new_skill).add(idx);
                    dp.get(new_skill).add(i);
                }
            }
        }
        int [] ans = new int[dp.get(total - 1).size()];
        for(int i = 0; i < ans.length; ++i) {
            ans[i] = dp.get(total - 1).get(i);
        }
        return ans;
        
    }
}
