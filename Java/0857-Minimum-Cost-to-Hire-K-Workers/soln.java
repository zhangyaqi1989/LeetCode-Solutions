class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        int n = wage.length;
        double[][] workers = new double[n][2];
        for(int i = 0; i < n; ++i) {
            workers[i] = new double[] {(double) wage[i] / quality[i], quality[i]};
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        PriorityQueue<Double> pq = new PriorityQueue<>();
        double ans = Double.MAX_VALUE, qsum = 0.0;
        for(int i = 0; i < n; ++i) {
            double ratio = workers[i][0];
            qsum += workers[i][1];
            pq.offer(-workers[i][1]);
            if (pq.size() > K) qsum += pq.poll();
            if (pq.size() == K) ans = Math.min(ans, qsum * ratio);
        }
        return ans;
    }
}
