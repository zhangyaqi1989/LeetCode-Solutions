class Solution {
    double radius;
    double x_center;
    double y_center;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
    }
    
    public double[] randPoint() {
        double r = Math.sqrt(Math.random()) * radius;
        double theta = Math.random() * Math.PI * 2;
        return new double[] {x_center + Math.cos(theta) * r, y_center + Math.sin(theta) * r};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
