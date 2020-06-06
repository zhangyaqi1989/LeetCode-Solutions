class Logger {
    
    private Map<String, Integer> seen;

    /** Initialize your data structure here. */
    public Logger() {
        seen = new HashMap<>();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (!seen.containsKey(message) || seen.get(message) <= timestamp - 10) {
            seen.put(message, timestamp);
            return true;
        }
        return false;
    }
    
    
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
