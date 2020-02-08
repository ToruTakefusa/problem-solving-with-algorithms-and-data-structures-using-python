public class Sample {
    public static void main(String args[]) {
        MyBinarySearchTree tree = new MyBinarySearchTree();
        tree.put(10, "foo");
        tree.put(20, "foo2");
        tree.put(0, "foo3");
        tree.put(24, "foo4");
        tree.put(33, "foo5");
        System.out.println(tree.containsKey(10));
        System.out.println(tree.containsKey(20));
        System.out.println(tree.get(10));
        tree.delete(0);
        System.out.println(tree.containsKey(0));
    }
}
