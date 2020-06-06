class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> uniques = new HashSet<>();
        for(String email : emails) {
            int i = email.indexOf('@');
            String local = email.substring(0, i);
            String rest = email.substring(i);
            int j = local.indexOf('+');
            if (j != -1) local = local.substring(0, j);
            local = local.replaceAll("\\.", ""); // regex
            // System.out.println(local + rest);
            uniques.add(local + rest);
        }
        return uniques.size();
    }
}
