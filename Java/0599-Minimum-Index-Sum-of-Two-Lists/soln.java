class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> m2 = new HashMap<>();
        int n2 = list2.length;
        for(int i = 0; i < n2; ++i) {
            m2.put(list2[i], i);
        }
        int n1 = list1.length;
        int mn = n1 + n2;
        for(int i = 0; i < n1; ++i) {
            if (m2.containsKey(list1[i])) {
                int j = m2.get(list1[i]);
                if (i + j < mn) {
                    mn = i + j;
                }
            }
        }
        List<String> ans = new ArrayList<>();
        for(int i = 0; i < n1; ++i) {
            if (m2.containsKey(list1[i])) {
                int j = m2.get(list1[i]);
                if (i + j == mn) ans.add(list1[i]);
            }
        }
        return ans.toArray(new String[ans.size()]);
    }
}
