class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        // Build a graph
        int nqueries = queries.size();
        double [] ans = new double [nqueries];
        Map<String, Map<String, Double>> graph = new HashMap<>();
        int idx = 0;
        for(List<String> e : equations) {
            String nume = e.get(0), deno = e.get(1);
            double value = values[idx++];
            store(graph, nume, deno, value);
            store(graph, deno, nume, 1.0/value);
            store(graph, nume, nume, 1.0);
            store(graph, deno, deno, 1.0);
        }
        idx = 0;
        for(List<String> q : queries) {
            String nume = q.get(0), deno = q.get(1);
            ans[idx++] = search(graph, nume, deno);
        }
        return ans;
        
    }
    
    public double search(Map<String, Map<String, Double>> graph, String start, String target) {
        if (!graph.containsKey(start)) return -1.0;
        Stack<Pair<String, Double>> stk = new Stack<>();
        Set<String> seen = new HashSet<>();
        stk.push(new Pair(start, 1.0));
        seen.add(start);
        while(!stk.isEmpty()) {
            Pair<String, Double> node = stk.peek();
            stk.pop();
            String u = node.getKey();
            double value = node.getValue();
            if (u.equals(target)) return value;
            Map<String, Double> neis = graph.getOrDefault(u, null);
            if (neis != null) {
                for(String v : neis.keySet()) {
                    if (!seen.contains(v)) {
                        seen.add(v);
                        stk.push(new Pair(v, neis.get(v) * value));
                    }
                }
            }
        }
        return -1.0;
    }
    
    public void store(Map<String, Map<String, Double>> graph, String nume, String deno, double value) {
        graph.putIfAbsent(nume, new HashMap<>());
        graph.get(nume).put(deno, value);
    }
    
}
