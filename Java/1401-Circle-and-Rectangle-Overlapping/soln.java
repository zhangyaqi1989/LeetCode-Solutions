class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx = Math.max(x1, Math.min(x_center, x2)) - x_center;
        int dy = Math.max(y1, Math.min(y_center, y2)) - y_center;
        return dx * dx + dy * dy <= radius * radius;
    }
}
