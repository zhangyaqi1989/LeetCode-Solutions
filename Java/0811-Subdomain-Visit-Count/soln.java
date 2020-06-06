class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> domains = new HashMap<>();
        for(String cpdomain : cpdomains) {
            String[] arr = cpdomain.split(" ");
            String domain = arr[1];
            int cnt = Integer.parseInt(arr[0]);
            domains.put(domain, domains.getOrDefault(domain, 0) + cnt);
            int i = 0;
            while (true) {
                int j = domain.indexOf('.', i);
                if (j == -1) break;
                String temp = domain.substring(j + 1);
                i = j + 1;
                domains.put(temp, domains.getOrDefault(temp, 0) + cnt);
            }
        }
        List<String> ans = new ArrayList<>();
        for(String key : domains.keySet()) {
            ans.add(String.format("%d %s", domains.get(key), key));
        }
        return ans;
    }
}
