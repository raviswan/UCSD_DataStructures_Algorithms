#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_
#include <iostream>
#include <cstdlib>

#define SUCCESS 1
#define FAILURE -1

class BinTreeNode{
public:
	BinTreeNode(void* data);	
	BinTreeNode* getLeftNode() const;
	BinTreeNode* getRightNode() const;
	/*Create a left node with value pointed to by "data" pointer*/
	int setLeftNode(void* data); 
	/*Create a right node with value pointed to by "data" pointer*/
	int setRightNode(void* data);
	/*Set left pointer of current node to NULL*/
	int setLeftToNull();
	/*Set right pointer of current node to NULL*/
	int setRightToNull();
	bool isLeafNode() const;
	bool isEndOfBranch() const;
	void* getData() const;
	~BinTreeNode();

private:
	void *data;
	BinTreeNode* left;
	BinTreeNode* right;
};

class BinTree{
public:
	BinTree();
	~BinTree();
	int getTreeSize() const;
	BinTreeNode* getRoot() const;
	/*insert a node to left of parent node*/
	int insertLeft(BinTreeNode* parent,void *data);
	/*insert a node to right of parent node*/
	int insertRight(BinTreeNode* parent,void* data);
	/*recursively remove left sub-tree of parent node*/
	int removeLeft(BinTreeNode* parent);
	/*recursively remove right sub-tree of parent node*/
	int removeRight(BinTreeNode* parent);
	/*use this to destroy data only if data is allocated on the heap*/
	int destroyData(BinTreeNode* data);
	/*Count the number of the leaves in a tree*/
	int countLeaves(void);
	/*Count the number of non-leaves in a tree*/
	int countNonLeaves(void);
	/*Get the height of a tree*/
	int getHeight(void);
	/*print tree elements in pre-order by using user-defined print function*/
	void printPreOrder(void (*print)(const void *data));
	/*print tree elements in-order by usin user-defined print function */
	void printInOrder(void (*print)(const void *data));
	/*print tree elements post-order by using user-defined print function*/
	void printPostOrder(void (*print)(const void *data));
	/*Remove all leaves of a tree*/
	void removeLeaves(void);

private:
	/*internal functions*/
	void doCountLeaves(BinTreeNode* node);
	int doGetHeight(BinTreeNode* node);
	void doPrintPreOrder(BinTreeNode* node,void (*print)(const void *data));
	void doPrintInOrder(BinTreeNode* node,void (*print)(const void *data));
	void doPrintPostOrder(BinTreeNode* node,void (*print)(const void *data));
	void doRemoveLeaves(BinTreeNode* node);
	/*root pointer of a tree*/
	BinTreeNode* root;
	/*total elements in a tree*/
	int size;
	/*no. of leaves in a tree*/
	int leafCount;
	/*height of a tree*/
	int height;
};

#endif
