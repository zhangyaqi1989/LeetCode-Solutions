class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> cities = new HashSet<>();
        for(List<String> p : paths) {
            cities.add(p.get(0));
        }
        for(List<String> p : paths) {
            if(!cities.contains(p.get(1))) return p.get(1);
        }
        return "";
    }
}
