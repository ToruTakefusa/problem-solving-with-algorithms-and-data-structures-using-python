import java.util.Objects;

public class TreeNode {
    private int key;
    private int balancedFactor;
    private String value;
    private TreeNode leftChild;
    private TreeNode rightChild;
    private TreeNode parent;

    public TreeNode(int key, String value, TreeNode leftChild, TreeNode rightChild, TreeNode parent) {
        this.key = key;
        this.value = value;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
        this.parent = parent;
    }

    public TreeNode getParent() {
        return this.parent;
    }

    public void setParent(TreeNode parent) {
        this.parent = parent;
    }

    public TreeNode getLeftChild() {
        return this.leftChild;
    }

    public void setLeftChild(TreeNode leftChild) {
        this.leftChild = leftChild;
    }

    public TreeNode getRightChild() {
        return this.rightChild;
    }

    public void setRightChild(TreeNode rightChild) {
        this.rightChild = rightChild;
    }


    public int getKey() {
        return this.key;
    }

    public void setKey(int key) {
        this.key = key;
    }

    public String getValue() { return this.value; }

    public void setValue(String value) {
        this.value = value;
    }

    public int getBalancedFactor() {
        return balancedFactor;
    }

    public void setBalancedFactor(int balancedFactor) {
        this.balancedFactor = balancedFactor;
    }

    public boolean hasLeftChild() {
        if (Objects.isNull(leftChild)) return false;
        return true;
    }

    public boolean hasRightChild() {
        if (Objects.isNull(rightChild)) return false;
        return true;
    }

    public boolean isLeftChild() {
        if ((!Objects.isNull(parent)) && (this.parent.getLeftChild() == this)) return true;
        return false;
    }

    public boolean isRightChild() {
        if ((!Objects.isNull(parent)) && (this.parent.getRightChild() == this)) return true;
        return false;
    }

    public boolean isRoot() {
        if (Objects.isNull(this.parent)) return true;
        return false;
    }

    public boolean isLeaf() {
        if (Objects.isNull(this.leftChild) && Objects.isNull(this.rightChild)) return true;
        return false;
    }

    public boolean hasAnyChildren() {
        if (!Objects.isNull(this.leftChild) || !Objects.isNull(this.rightChild)) return true;
        return false;
    }

    public boolean hasBothChildren() {
        if (!Objects.isNull(this.leftChild) && !Objects.isNull(this.rightChild)) return true;
        return false;
    }

    public void replaceNodeData(int key, String value, TreeNode leftChild, TreeNode rightChild) {
        this.key = key;
        this.value = value;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
        if (this.hasLeftChild()) {
            this.leftChild.setParent(this);
        }
        if (this.hasRightChild()) {
            this.rightChild.setParent(this);
        }
    }

    public TreeNode findSuccessor() {
        if (this.hasRightChild()) return this.rightChild.findMin();
        if (Objects.isNull(this.parent)) return null;
        if (this.isLeftChild()) return this.parent;

        this.parent.setRightChild(null);
        TreeNode successor = this.parent;
        this.parent.setRightChild(this);
        return successor;
    }

    public TreeNode findMin() {
        TreeNode current = this;
        while(current.hasLeftChild()) {
            current = current.getLeftChild();
        }
        return current;
    }

    public void spliceOut() {
        if (this.isLeaf()) {
            if (this.isLeftChild()) {
                this.parent.setLeftChild(null);
            } else {
                this.parent.setRightChild(null);
            }
        } else if(this.hasAnyChildren()) {
            if (this.hasLeftChild()) {
                if (this.isLeftChild()) {
                    this.parent.leftChild = this.leftChild;
                } else {
                    this.parent.rightChild = this.leftChild;
                }
                this.leftChild.parent = this.parent;
            } else {
                if (this.isLeftChild()) {
                    this.parent.setLeftChild(this.rightChild);
                } else {
                    this.parent.setRightChild(this.rightChild);
                }
                this.rightChild.parent = this.parent;
            }
        }
    }
}
