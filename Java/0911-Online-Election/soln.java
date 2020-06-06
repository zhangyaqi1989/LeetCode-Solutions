class TopVotedCandidate {
    
    private TreeMap<Integer, Integer> leads;

    public TopVotedCandidate(int[] persons, int[] times) {
        leads = new TreeMap<>();
        int n = persons.length;
        int [] counter = new int [n + 1];
        int mx = 0, lead = 0;
        for(int i = 0; i < n; ++i) {
            int p = persons[i], t = times[i];
            if (++counter[p] >= mx) {
                mx = counter[p];
                lead = p;
            }
            leads.put(t, lead);
        }
    }
    
    public int q(int t) {
        return leads.floorEntry(t).getValue();
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
