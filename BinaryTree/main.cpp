#include "binTree.h"

void printNodeData(const void* node){
	BinTreeNode* elem = (BinTreeNode*) node;
	printf("%d\n",*(int*)elem->getData());
}

void BuildTreeOne(BinTree &t, int data[]){
	t.insertLeft(NULL,&data[0]);
	t.insertLeft(t.getRoot(),&data[1]);
	t.insertLeft((t.getRoot())->getLeftNode(),&data[2]);
	t.insertLeft((t.getRoot())->getLeftNode()->getLeftNode(),&data[3]);
	t.insertRight(t.getRoot(),&data[4]);
	t.insertLeft((t.getRoot())->getRightNode(),&data[5]);
	t.insertRight((t.getRoot())->getRightNode(),&data[6]);
	t.insertRight((t.getRoot())->getRightNode()->getRightNode(),&data[7]);
	t.insertRight((t.getRoot())->getRightNode()->getRightNode()->getRightNode(),&data[8]);
}

void BuildTreeTwo(BinTree &t, int data[]){
	t.insertLeft(NULL,&data[0]);
	t.insertLeft(t.getRoot(),&data[1]);
	t.insertLeft((t.getRoot())->getLeftNode(),&data[2]);
	t.insertLeft((t.getRoot())->getLeftNode()->getLeftNode(),&data[3]);
	t.insertRight((t.getRoot())->getLeftNode()->getLeftNode(),&data[4]);
	t.insertRight((t.getRoot())->getLeftNode(),&data[5]);
	t.insertRight(t.getRoot(),&data[6]);
	t.insertLeft((t.getRoot())->getRightNode(),&data[7]);
	t.insertRight((t.getRoot())->getRightNode(),&data[8]);
}


int main(){
	BinTree tree1, tree2;
	/*elements in pre-order*/
	int treeOneData[] = {1,2,4,7,3,5,6,8,9};
	int treeTwoData[] = {6,4,2,1,3,5,8,7,9};

	BuildTreeOne(tree1,treeOneData);
	BuildTreeTwo(tree2,treeTwoData);

	printf("no. of leaves in Tree 1 = %d\n",tree1.countLeaves());
	printf("no. of leaves in Tree 2 = %d\n",tree2.countLeaves());
	printf("\nno. of non-leaves in Tree 1 = %d\n",tree1.countNonLeaves());
	printf("no. of non-leaves in Tree 2 = %d\n",tree2.countNonLeaves());
	printf("\nHeight of Tree 1 = %d\n",tree1.getHeight());
	printf("Height of Tree 2 = %d\n",tree2.getHeight());

	printf("\n\nPrinting Tree1 in Pre-Order \n");
	tree1.printPreOrder(printNodeData);
	printf("Printing Tree1 in In-Order \n");
	tree1.printInOrder(printNodeData);
	printf("Printing Tree1 in Post-Order \n");
	tree1.printPostOrder(printNodeData);

	printf("\n\nPrinting Tree2 in Pre-Order \n");
	tree2.printPreOrder(printNodeData);
	printf("Printing Tree2 in In-Order \n");
	tree2.printInOrder(printNodeData);
	printf("Printing Tree2 in Post-Order \n");
	tree2.printPostOrder(printNodeData);

	printf("\nRemoving leaves from tree1\n");
	tree1.removeLeaves();
	printf("Printing Tree1 in Pre-Order after removal\n");
	tree1.printPreOrder(printNodeData);
	printf("Printing Tree1 in In-Order after removal \n");
	tree1.printInOrder(printNodeData);
	printf("Printing Tree1 in Post-Order after removal \n");
	tree1.printPostOrder(printNodeData);

	printf("\nRemoving leaves from tree2\n");
	tree2.removeLeaves();
	printf("Printing Tree2 in Pre-Order after removal \n");
	tree2.printPreOrder(printNodeData);
	printf("Printing Tree2 in In-Order after removal \n");
	tree2.printInOrder(printNodeData);
	printf("Printing Tree2 in Post-Order after removal \n");
	tree2.printPostOrder(printNodeData);

	return 0;

}