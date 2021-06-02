package comp2402a3;

import java.util.LinkedList;
import java.util.Queue;
import java.io.PrintWriter;
import java.util.Random;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;

/**
 * An implementation of binary trees
 * @author morin
 *
 * @param <Node>
 */
public class BinaryTree<Node extends BinaryTree.BTNode<Node>> {

	public static class BTNode<Node extends BTNode<Node>> {
		public Node left;
		public Node right;
		public Node parent;
	}

	/**
	 * An extension of BTNode that you can actually instantiate.
	 */
	protected static class EndNode extends BTNode<EndNode> {
			public EndNode() {
				this.parent = this.left = this.right = null;
			}
	}

	/**
	 * Used to make a mini-factory
	 */
	protected Node sampleNode;

	/**
	 * The root of this tree
	 */
	protected Node r;

	/**
	 * This tree's "null" node
	 */
	protected Node nil;

	/**
	 * Create a new instance of this class
	 * @param sampleNode - a sample of a node that can be used
	 * to create a new node in newNode()
	 * @param nil - a node that will be used in place of null
	 */
	public BinaryTree(Node sampleNode, Node nil) {
		this.sampleNode = sampleNode;
		this.nil = nil;
		r = nil;
	}

	/**
	 * Create a new instance of this class
	 * @param sampleNode - a sample of a node that can be used
	 * to create a new node in newNode()
	 */
	public BinaryTree(Node sampleNode) {
		this.sampleNode = sampleNode;
	}

	/**
	 * Allocate a new node for use in this tree
	 * @return
	 */
	@SuppressWarnings({"unchecked"})
	protected Node newNode() {
		try {
			Node u = (Node)sampleNode.getClass().getDeclaredConstructor().newInstance();
			u.parent = u.left = u.right = nil;
			return u;
		} catch (Exception e) {
			return null;
		}
	}

	/**
	 * Compute the depth (distance to the root) of u
	 * @param u
	 * @return the distanct between u and the root, r
	 */
	public int depth(Node u) {
		int d = 0;
		while (u != r) {
			u = u.parent;
			d++;
		}
		return d;
	}

	/**
	 * Compute the size (number of nodes) of this tree
	 * @warning uses recursion so could cause a stack overflow
	 * @return the number of nodes in this tree
	 */
	public int size() {
		return size(r);
	}

	/**
	 * @return the size of the subtree rooted at u
	 */
	protected int size(Node u) {
		if (u == nil) return 0;
		return 1 + size(u.left) + size(u.right);
	}

	/**
	 * Compute the number of nodes in this tree without recursion
	 * @return
	 */
	public int size2() {
		Node u = r, prev = nil, next;
		int n = 0;
		while (u != nil) {
			if (prev == u.parent) {
				n++;
				if (u.left != nil) next = u.left;
				else if (u.right != nil) next = u.right;
				else next = u.parent;
			} else if (prev == u.left) {
				if (u.right != nil) next = u.right;
				else next = u.parent;
			} else {
				next = u.parent;
			}
			prev = u;
			u = next;
		}
		return n;
	}

	/**
	 * Compute the maximum depth of any node in this tree
	 * @return the maximum depth of any node in this tree
	 */
	public int height() {
		return height(r);
	}

	/**
	 * @return the height of the subtree rooted at u
	 */
	protected int height(Node u) {
		if (u == nil) return -1;
		return 1 + Math.max(height(u.left), height(u.right));
	}


	public String toString() {
		StringBuilder sb = new StringBuilder();
		toStringHelper(sb, r);
		return sb.toString();
	}

	protected void toStringHelper(StringBuilder sb, Node u) {
			if (u == null) {
				return;
			}
			sb.append('(');
			toStringHelper(sb, u.left);
			toStringHelper(sb, u.right);
			sb.append(')');
	}


	/**
	 * @ return an n-node BinaryTree that has the shape of a random
	 * binary search tree.
	 */
	public static BinaryTree<EndNode> randomBST(int n) {
		Random rand = new Random();
		EndNode sample = new EndNode();
		BinaryTree<EndNode> t = new BinaryTree<EndNode>(sample);
		t.r = randomBSTHelper(n, rand);
		return t;
	}

	protected static EndNode randomBSTHelper(int n, Random rand) {
		if (n == 0) {
			return null;
		}
		EndNode r = new EndNode();
		int ml = rand.nextInt(n);
		int mr = n - ml - 1;
		if (ml > 0) {
			r.left = randomBSTHelper(ml, rand);
			r.left.parent = r;
		}
		if (mr > 0) {
			r.right = randomBSTHelper(mr, rand);
			r.right.parent = r;
		}
		return r;
	}

	/**
	 * @return
	 */
	public boolean isEmpty() {
		return r == nil;
	}

	/**
	 * Make this tree into the empty tree
	 */
	public void clear() {
		r = nil;
	}

	/**
	 * Demonstration of a recursive traversal
	 * @param u
	 */
	public void traverse(Node u) {
		if (u == nil) return;
		traverse(u.left);
		traverse(u.right);
	}

	/**
	 * Demonstration of a non-recursive traversal
	 */
	public void traverse2() {
		Node u = r, prev = nil, next;
		while (u != nil) {
			if (prev == u.parent) {
				if (u.left != nil) {
					next = u.left;
				} else if (u.right != nil) {
					next = u.right;
				}	else {
					next = u.parent;
				}
			} else if (prev == u.left) {
				if (u.right != nil) {
					next = u.right;
				} else {
					next = u.parent;
				}
			} else {
				next = u.parent;
			}
			prev = u;
			u = next;
		}
	}

	/**
	 * Demonstration of a breadth-first traversal
	 */
	public void bfTraverse() {
		Queue<Node> q = new LinkedList<Node>();
		if (r != nil) q.add(r);
		while (!q.isEmpty()) {
			Node u = q.remove();
			if (u.left != nil) q.add(u.left);
			if (u.right != nil) q.add(u.right);
		}
	}

	/**
	 * Find the first node in an in-order traversal
	 * @return the first node reported in an in-order traversal
	 */
	public Node firstNode() {
		Node w = r;
		if (w == nil) return nil;
		while (w.left != nil)
			w = w.left;
		return w;
	}

	/**
	 * Find the node that follows w in an in-order traversal
	 * @param w
	 * @return the node that follows w in an in-order traversal
	 */
	public Node nextNode(Node w) {
		if (w.right != nil) {
			w = w.right;
			while (w.left != nil)
				w = w.left;
		} else {
			while (w.parent != nil && w.parent.left != w)
				w = w.parent;
			w = w.parent;
		}
		return w;
	}

	public int totalDepth() {
		// TODO: Your code goes here
		if(r == nil){
			return -1;
		}

		int cd = 0, td = 0;
		Node u = r, prev = nil, next;

		while(u != nil){
			if(prev == u.parent){
				if(u.left != nil){
					next = u.left;
					cd++;
				} else if(u.right != nil){
					next = u.right;
					cd++;
				} else{
					next = u.parent;
					cd--;
				}
			} else if(prev == u.left){
				if(u.right != nil){
					next = u.right;
					cd++;
				} else{
					next = u.parent;
					cd--;
				}
			} else{
				next = u.parent;
				cd--;
			}
			td += next == u.parent ? 0 : cd;
			prev = u;
			u = next;
		}
		
		return td;
	}

	public int totalLeafDepth() {
		// TODO: Your code goes here
		if(r == nil){
			return -1;
		}

		int cd = 0, tld = 0;
		Node u = r, prev = nil, next;

		while(u != nil){
			if(prev == u.parent){
				if(u.left != nil){
					next = u.left;
					cd++;
				} else if(u.right != nil){
					next = u.right;
					cd++;
				} else{
					next = u.parent;
					tld += cd;
					cd--;
				}
			} else if(prev == u.left){
				if(u.right != nil){
					next = u.right;
					cd++;
				} else{
					next = u.parent;
					cd--;
				}
			} else{
				next = u.parent;
				cd--;
			}
			prev = u;
			u = next;
		}
		
		return tld;
	}

	public String bracketSequence() {
		StringBuilder sb = new StringBuilder();
		// TODO: Your code goes here, use sb.append()
		if(r == nil){
			sb.append(".");
		}

		Node u = r, prev = nil, next;
		while (u != nil) {
			if (prev == u.parent) {
				sb.append("(");
				if (u.left != nil) {
					// sb.append("(");

					next = u.left;
				} else if (u.right != nil) {
					next = u.right;
					sb.append(".");
				}	else {
					next = u.parent;
					sb.append("..)");
				}
			} else if (prev == u.left) {
				if (u.right != nil) {
					next = u.right;
					// sb.append("(");
				} else {
					next = u.parent;
					sb.append(".)");
				}
			} else {
				next = u.parent;
				sb.append(")");
			}
			prev = u;
			u = next;
		}
		return sb.toString();
	}

	public void prettyPrint(PrintWriter w) {
		Node u = r, n,/* nR = r, nL = r, */ prev = nil, next;
		ArrayList<StringBuilder> bt = new ArrayList<>();
		ArrayList<StringBuilder> bars = new ArrayList<>();
		ArrayList<Boolean> lasts = new ArrayList<>();
		int length = 0, width = 0, size = 0, j;

		bt.add(new StringBuilder());
		bars.add(new StringBuilder());
		lasts.add(false);
		while (u != nil) {
			if (u.right != nil)
				lasts.set(length, false);
			else
				lasts.set(length, true);
			if (prev == u.parent) {
				size = bt.size();
				bt.get(length).append("*");
				if (u.left != nil) {
					bars.get(length).append("|");
					length++;
					if(length == size){
						bt.add(new StringBuilder());
						bars.add(new StringBuilder());
						for(int i = 0; i < width; i++){
							bt.get(size).append("  ");
							bars.get(size).append("  ");
						}
						lasts.add(false);
					}
					next = u.left;
				} else if (u.right != nil) {
					width++;
					bt.get(length).append("-");
					bars.get(length).append("  ");
					for(int i = 0; i < length; i++){
						if(!lasts.get(i)){
							bt.get(i).append("--");
						} else{
							bt.get(i).append("  ");
						}
						bars.get(i).append("  ");
					}
					for(int i = length+1; i < size; i++){
						bt.get(i).append("  ");
						bars.get(i).append("  ");
					}
					next = u.right;
				}	else {
					bars.get(length).append(" ");
					for(int i = length+1; i < size; i++){
						bt.get(i).append(" ");
						bars.get(i).append(" ");
					}
					next = u.parent;
				}
			} else if (prev == u.left) {
				size = bt.size();
				length--;
				if (u.right != nil) {
					width++;
					bt.get(length).append("-");
					bars.get(length).append(" ");
					for(int i = 0; i < length; i++){
						if(!lasts.get(i)){
							bt.get(i).append("--");
						} else{
							bt.get(i).append("  ");		
						}		
						bars.get(i).append("  ");
					}
					for(int i = length+1; i < size; i++){
						bt.get(i).append(" ");
						bars.get(i).append(" ");
					}
					next = u.right;
				} else {
					next = u.parent;
				}
			} else {
				// width--;
				next = u.parent;
			}
			prev = u;
			u = next;
		}

		size = bt.size();
		for(int i = 0; i < size; i++){
			w.println(bt.get(i));
			if(i < size-1)
				w.println(bars.get(i));
		}
	}

	public static void main(String[] args) {
		BinaryTree t = randomBST(75);
		// HashMap<String,Integer> g = new HashMap<>();
		// g.put("hey",0);
		// g.get("hey")+=1;
		PrintWriter w = new PrintWriter(System.out);
		
		
		System.out.println(t.bracketSequence());
		System.out.println();
		t.prettyPrint(w);
		w.flush();

	}

}
