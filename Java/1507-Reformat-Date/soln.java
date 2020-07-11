class Solution {
    public String reformatDate(String date) {
        String [] tokens = date.split(" ");
        String [] months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int day = Integer.parseInt(tokens[0].substring(0, tokens[0].length() - 2));
        int month = -1;
        for(int i = 0; i < 12; ++i) {
            if(months[i].equals(tokens[1])) {
                month = i + 1;
                break;
            }
        }
        int year = Integer.parseInt(tokens[2]);
        return toString(year) + "-" + toString(month) + "-" + toString(day);
    }
    
    public String toString(int num) {
        if(num <= 9) return "0" + num;
        else return Integer.toString(num);
    }
}
