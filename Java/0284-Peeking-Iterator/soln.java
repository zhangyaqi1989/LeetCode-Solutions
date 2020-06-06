// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> iter;
    private boolean valid;
    private int val;
    
    private void update() {
        if (!valid && iter.hasNext()) {
            valid = true;
            val = iter.next();
        }
    }

	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    iter = iterator;
        update();
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        update();
        return val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    update();
        valid = false;
        return val;
	}

	@Override
	public boolean hasNext() {
	    update();
        return valid;
	}
}
