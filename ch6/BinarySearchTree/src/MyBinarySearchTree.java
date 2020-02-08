import java.util.Objects;

public class MyBinarySearchTree {
    TreeNode root;
    int size;

    public MyBinarySearchTree() {
        this.root = null;
        this.size = 0;
    }

    public int length() {
        return this.size;
    }

    public void put(int key, String value) {
        if (!Objects.isNull(this.root)) {
            this.put(key, value, this.root);
        } else {
            this.root = new TreeNode(key, value, null, null, null);
        }
        this.size++;
    }

    private void put(int key, String value, TreeNode currentNode) {
        if (key < currentNode.getKey()) {
            if (currentNode.hasLeftChild()) {
                put(key, value, currentNode.getLeftChild());
            } else {
                currentNode.setLeftChild(new TreeNode(key, value, null, null, currentNode));
            }
        } else {
            if (currentNode.hasRightChild()) {
                put(key, value, currentNode.getRightChild());
            } else {
                currentNode.setRightChild(new TreeNode(key, value, null, null, currentNode));
            }
        }
    }

    public String get(int key) {
        if (!Objects.isNull(this.root)) {
            TreeNode treeNode = this.get(key, this.root);
            if (Objects.isNull(treeNode)) return null;
            return treeNode.getValue();
        } else {
            return null;
        }
    }

    public TreeNode get(int key, TreeNode curretNode) {
        if (Objects.isNull(curretNode)) {
            return null;
        } else if(curretNode.getKey() == key) {
            return curretNode;
        } else if (key < curretNode.getKey()) {
            return get(key, curretNode.getLeftChild());
        } else {
            return get(key, curretNode.getRightChild());
        }
    }

    public boolean containsKey(int key) {
        if (Objects.isNull(get(key))) return false;
        return true;
    }

    public void delete(int key) {
        if (this.size < 1) throw new IllegalArgumentException("Does not contain a specified key.");
        if (this.size > 1) {
            TreeNode nodeToRemove = get(key, this.root);
            if (Objects.isNull(nodeToRemove)) throw new IllegalArgumentException("Does not contain a specified key");
            remove(nodeToRemove);
            this.size--;
        } else if ((this.size == 1) && (this.root.getKey() == key)) {
            this.root = null;
            this.size--;
        } else {
            throw new IllegalArgumentException("Does not contain a specified key");
        }
    }

    public void remove(TreeNode currentNode) {
        if (currentNode.isLeaf()) {
            // leaf
            if (currentNode.equals(currentNode.getParent().getLeftChild())) {
                currentNode.getParent().setLeftChild(null);
            } else {
                currentNode.getParent().setRightChild(null);
            }
        } else if (currentNode.hasBothChildren()) {
            TreeNode successor = currentNode.findSuccessor();
            successor.spliceOut();;
            currentNode.setKey(successor.getKey());
            currentNode.setValue(successor.getValue());
        } else {
            // this node has one child
            if (currentNode.hasLeftChild()) {
                if (currentNode.isLeftChild()) {
                    currentNode.getLeftChild().setParent(currentNode.getParent());
                    currentNode.getParent().setLeftChild(currentNode.getLeftChild());
                } else if (currentNode.isRightChild()) {
                    currentNode.getLeftChild().setParent(currentNode.getParent());
                    currentNode.getParent().setRightChild(currentNode.getLeftChild());
                } else {
                    currentNode.replaceNodeData(currentNode.getLeftChild().getKey(),
                            currentNode.getLeftChild().getValue(),
                            currentNode.getLeftChild().getLeftChild(),
                            currentNode.getLeftChild().getRightChild());
                }
            } else {
                if (currentNode.isLeftChild()) {
                    currentNode.getRightChild().setParent(currentNode.getParent());
                    currentNode.getParent().setLeftChild(currentNode.getRightChild());
                } else if (currentNode.isRightChild()) {
                    currentNode.getRightChild().setParent(currentNode.getParent());
                    currentNode.getParent().setRightChild(currentNode.getRightChild());
                } else {
                    currentNode.replaceNodeData(currentNode.getRightChild().getKey(),
                            currentNode.getRightChild().getValue(),
                            currentNode.getRightChild().getLeftChild(),
                            currentNode.getRightChild().getRightChild());
                }
            }
        }
    }

}
