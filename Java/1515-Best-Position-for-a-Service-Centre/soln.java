class Solution {
    public double getMinDistSum(int[][] points) {
        double x = 0, y = 0;
        int n = points.length;
        for(int [] p : points) {
            x += p[0];
            y += p[1];
        }
        x /= n;
        y /= n;
        int [] dirs = {0, 1, 0, -1, 0};
        double best = SumDistance(points, x, y);
        boolean done = false;
        double step = 100.0;
        double eps = 0.000001;
        while(step > eps) {
            done = false;
            for(int k = 0; k < 4; ++k) {
                int dx = dirs[k];
                int dy = dirs[k + 1];
                double nx = x + step * dx;
                double ny = y + step * dy;
                double cur = SumDistance(points, nx, ny);
                if (cur < best) {
                    best = cur;
                    x = nx;
                    y = ny;
                    done = true;
                    break;
                }

            }
            if (!done) step /= 2;
        }
        return best;
    }
    
    public double SumDistance(int [][] points, double x, double y) {
        double sum = 0;
        for(int [] p : points) {
            double dx = x - p[0];
            double dy = y - p[1];
            sum += Math.sqrt(dx * dx + dy * dy);
        }
        return sum;
    }
    
}
