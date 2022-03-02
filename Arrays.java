public class Arrays {

    public static class iArray {
        int[] items;
        int count = 0;

        public iArray(int _size) {
            items = new int[_size];
        }

        public void print() {
            for (int __i=0; __i<count; __i++) {
                System.out.println(items[__i]);
            }
        }

        public void push(int _item) { // Runtime complexity = O(n) , Space = O(x) (ig)
            if (count == items.length) {
                int[] __items = new int[count * 2];
                System.arraycopy(items, 0, __items, 0, count);
                items = __items;
            }
            items[count++] = _item;
        }
    }
}
