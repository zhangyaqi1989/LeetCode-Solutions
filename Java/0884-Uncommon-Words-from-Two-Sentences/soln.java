class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> counter = new HashMap<>();
        for(String token : (A + " " + B).split(" "))
            counter.put(token, counter.getOrDefault(token, 0) + 1);
        ArrayList<String> ans = new ArrayList<>();
        for(String word : counter.keySet()) 
            if (counter.get(word) == 1)
                ans.add(word);
        return ans.toArray(new String[0]);
    }
}
