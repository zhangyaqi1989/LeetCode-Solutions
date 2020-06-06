class Solution {
    public int lengthLongestPath(String input) {
        String [] lines = input.split("\n");
        Map<Integer, Integer> depths = new HashMap<>();
        depths.put(0, 0);
        int mx = 0;
        for(String line : lines) {
            int depth = 0;
            while (depth < line.length() && line.charAt(depth) == '\t') ++depth;
            String name = line.substring(depth);
            if (name.indexOf('.') != -1) {
                mx = Math.max(mx, depths.get(depth) + name.length());
            } else {
                depths.put(depth + 1, depths.get(depth) + 1 + name.length());
            }
        }
        return mx;
    }
}
