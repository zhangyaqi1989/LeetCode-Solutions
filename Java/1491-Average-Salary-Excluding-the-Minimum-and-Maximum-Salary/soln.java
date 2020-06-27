class Solution {
    public double average(int[] salary) {
        double sum = 0.0;
        int mn = salary[0], mx = salary[1];
        for(int num : salary) {
            sum += num;
            mn = Math.min(mn, num);
            mx = Math.max(mx, num);
        }
        return (sum - mn - mx) / (salary.length - 2);
    }
}
