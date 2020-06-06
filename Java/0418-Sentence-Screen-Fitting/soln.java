class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        int n = sentence.length, total = 0;
        int [] lens = new int[n];
        int i = 0;
        for(String word : sentence) {
            int len = word.length();
            if (len > cols) return 0;
            total += len;
            lens[i++] = len;
        }
        total += sentence.length;
        int row = 0, cur = 0, ans = 0, col = 0;
        while (rows > 0) {
            if (col == 0) {
                ans += cols / total;
                col = cols / total * total;
            }
            // System.out.println(col);
            if (col + lens[cur] <= cols) {
                col += lens[cur] + 1;
                ++cur;
                if (cur >= lens.length) {
                    cur %= lens.length;
                    ++ans;
                }
            } else {
                col = 0;
                --rows;
                ++row;
                if (cur == 0) {
                    ans += ans * (rows / row);
                    rows %= row;
                }
            }
        }
        return ans;
    }
}
