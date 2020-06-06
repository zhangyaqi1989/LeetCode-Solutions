class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, ArrayList<String>> m = new HashMap<>();
        for(String path : paths) {
            String [] tokens = path.split(" ");
            // System.out.println(tokens.length);
            String parent = tokens[0];
            int n = tokens.length;
            for(int i = 1; i < n; ++i) {
                // System.out.println(tokens[i]);
                String file = tokens[i];
                int idx = file.indexOf("(");
                String name = file.substring(0, idx);
                String content = file.substring(idx + 1, file.length() - 1);
                if (!m.containsKey(content)) m.put(content, new ArrayList<>());
                m.get(content).add(parent + "/" + name);
            }
        }
        List<List<String>> ans = new ArrayList<>();
        for(String content : m.keySet()) {
            // System.out.println(content);
            if (m.get(content).size() > 1) ans.add(m.get(content));
        }
        
        return ans;
    }
}
