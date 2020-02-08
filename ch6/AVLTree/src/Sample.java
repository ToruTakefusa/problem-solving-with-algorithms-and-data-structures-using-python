public class Sample {
    public static void main(String args[]) {
        MyAVLTree tree = new MyAVLTree();
        tree.put(10, "foo1");
        tree.put(20, "foo2");
        tree.put(15, "foo3");
        System.out.println(tree.get(10));
    }
}
