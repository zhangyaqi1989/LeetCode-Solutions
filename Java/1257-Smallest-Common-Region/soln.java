class Solution {
    public String findSmallestRegion(List<List<String>> regions, String region1, String region2) {
        HashMap<String, String> parents = new HashMap<>();
        for(List<String> region : regions) {
            int n = region.size();
            String parent = region.get(0);
            for(int i = 1; i < n; ++i) {
                parents.put(region.get(i), parent);
            }
        }
        HashSet<String> cands = new HashSet<>();
        while (region1 != null) {
            cands.add(region1);
            region1 = parents.getOrDefault(region1, null);
        }
        
        while(region2 != null) {
            if(cands.contains(region2)) return region2;
            region2 = parents.getOrDefault(region2, null);
        }
        return "";
    }
}
