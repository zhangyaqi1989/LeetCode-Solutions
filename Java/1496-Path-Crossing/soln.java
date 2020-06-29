class Solution {
    public boolean isPathCrossing(String path) {
        HashSet<Integer> visited = new HashSet<>();
        visited.add(0);
        int r = 0, c = 0;
        for(char ch : path.toCharArray()) {
            if(ch == 'N') --r;
            else if(ch == 'S') ++r;
            else if(ch == 'E') ++c;
            else --c;
            int key = r * 10000 + c;
            if(visited.contains(key)) return true;
            visited.add(key);
        }
        return false;
    }
}
