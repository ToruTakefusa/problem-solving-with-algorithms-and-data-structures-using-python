import java.util.Objects;

public class MyAVLTree {
    TreeNode root;
    int size;
    int balanceFactor;

    public MyAVLTree() {
        this.root = null;
        this.size = 0;
        this.balanceFactor = 0;
    }

    public int length() {
        return this.size;
    }

    public void put(int key, String value) {
        if (Objects.isNull(root)) {
            this.root = new TreeNode(key, value, null, null, null);
        } else {
            put(key, value, this.root);
        }
        this.size++;
    }

    private void put(int key, String value, TreeNode currentNode) {
        if (key < currentNode.getKey()) {
            if (currentNode.hasLeftChild()) {
                put(key, value, currentNode.getLeftChild());
            } else {
                currentNode.setLeftChild(new TreeNode(key, value, null, null, currentNode));
                updateBalance(currentNode.getLeftChild());
            }
        } else {
            if (currentNode.hasRightChild()) {
                put(key, value, currentNode.getRightChild());
            } else {
                currentNode.setRightChild(new TreeNode(key, value, null, null, currentNode));
                updateBalance(currentNode.getRightChild());
            }
        }
    }

    private void updateBalance(TreeNode treeNode) {
        if (treeNode.getBalancedFactor() > 1 || treeNode.getBalancedFactor() < -1) {
            rebalance(treeNode);
            return;
        }

        if (!Objects.isNull(treeNode.getParent())) {
            int balancedFactor = treeNode.getParent().getBalancedFactor();
            if (treeNode.isLeftChild()) {
                balancedFactor++;
                treeNode.getParent().setBalancedFactor(balancedFactor);
            } else if (treeNode.isRightChild()) {
                balancedFactor--;
                treeNode.getParent().setBalancedFactor(balancedFactor);
            }

            if (treeNode.getBalancedFactor() != 0) {
                updateBalance(treeNode.getParent());
            }
        }
    }

    private void rotateLeft(TreeNode treeNode) {
        TreeNode newRoot = treeNode.getRightChild();
        treeNode.setRightChild(treeNode.getLeftChild());

        if (!Objects.isNull(newRoot.getLeftChild())) {
            newRoot.getLeftChild().setParent(treeNode);
        }
        newRoot.setParent(treeNode.getParent());

        if (treeNode.isRoot()) {
            this.root = newRoot;
        } else {
            if (treeNode.isLeftChild()) {
                treeNode.getParent().setLeftChild(newRoot);
            } else {
                treeNode.getParent().setRightChild(newRoot);
            }
        }
        newRoot.setLeftChild(treeNode);
        treeNode.setParent(newRoot);
        int balancedFactor = treeNode.getBalancedFactor() + 1 - Math.min(newRoot.getBalancedFactor(), 0);
        treeNode.setBalancedFactor(balancedFactor);
        balancedFactor = newRoot.getBalancedFactor() + 1 + Math.max(treeNode.getBalancedFactor(), 0);
        newRoot.setBalancedFactor(balancedFactor);
    }

    private void rotateRight(TreeNode treeNode) {
        TreeNode newRoot = treeNode.getLeftChild();
        treeNode.setLeftChild(newRoot.getRightChild());

        if (!Objects.isNull(newRoot.getRightChild())) {
            newRoot.getRightChild().setParent(treeNode);
        }
        newRoot.setParent(treeNode.getParent());

        if (treeNode.isRoot()) {
            this.root = newRoot;
        } else {
            if (treeNode.isRightChild()) {
                treeNode.getParent().setRightChild(newRoot);
            } else {
                treeNode.getParent().setRightChild(newRoot);
            }
        }
        newRoot.setRightChild(treeNode);
        treeNode.setParent(newRoot);
        int balancedFactor = treeNode.getBalancedFactor() + 1 - Math.min(newRoot.getBalancedFactor(), 0);
        treeNode.setBalancedFactor(balancedFactor);
        balancedFactor = newRoot.getBalancedFactor() + 1 + Math.max(treeNode.getBalancedFactor(), 0);
        newRoot.setBalancedFactor(balancedFactor);
    }

    private void rebalance(TreeNode treeNode) {
        if (treeNode.getBalancedFactor() < 0) {
            if (treeNode.getRightChild().getBalancedFactor() > 0) {
                rotateRight(treeNode.getRightChild());
                rotateLeft(treeNode);
            } else {
                rotateLeft(treeNode);
            }
        } else if(treeNode.getBalancedFactor() > 0) {
            if (treeNode.getLeftChild().getBalancedFactor() < 0) {
                rotateLeft(treeNode.getLeftChild());
                rotateRight(treeNode);
            } else {
                rotateRight(treeNode);
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

}
