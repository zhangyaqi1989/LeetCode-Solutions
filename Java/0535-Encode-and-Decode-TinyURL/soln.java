public class Codec {
    int size = 0;
    Map<Integer, String> urls = new HashMap<>();
    
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        urls.put(size, longUrl);
        return "http://tinyurl/com/" + Integer.toString(size++);
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        int idx = 0, unit = 0, n = shortUrl.length();
        for(int i = n - 1; i >= 0; --i) {
            if (Character.isDigit(shortUrl.charAt(i))) {
                idx += (shortUrl.charAt(i) - '0') * unit;
                unit *= 10;
            } else {
                break;
            }
        }
        return urls.get(idx);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
