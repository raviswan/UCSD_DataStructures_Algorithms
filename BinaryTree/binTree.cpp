#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "binTree.h"

using namespace std;


/*--------------Binary Tree Node definition-------------------*/

/*Tree Node Constructor*/
BinTreeNode::BinTreeNode(void *data):left(NULL),right(NULL),data(data){
}

BinTreeNode::~BinTreeNode(){
}

BinTreeNode* BinTreeNode::getLeftNode() const{
	return this->left;
}

BinTreeNode* BinTreeNode::getRightNode() const{
	return this->right;
}

void* BinTreeNode::getData() const{
	return data;
}


int BinTreeNode::setLeftNode(void* data) {
	this->left =  new BinTreeNode(data);
	return SUCCESS;
}


int BinTreeNode::setRightNode(void* data) {
	this->right =  new BinTreeNode(data);
	return SUCCESS;
}


int BinTreeNode::setLeftToNull() {
	this->left =  NULL;
	return SUCCESS;
}


int BinTreeNode::setRightToNull() {
	this->right =  NULL;
	return SUCCESS;
}

bool BinTreeNode::isLeafNode() const{
	if(this->left == NULL && this->right==NULL)
		return true;
	return false;
}


/*--------------Binary Tree definition-------------------*/

/*Binary Tree Constructor*/
BinTree::BinTree():size(0),root(NULL),leafCount(0),height(-1){
}

BinTree::~BinTree(){
}

int BinTree::getTreeSize() const{
	return this->size;
}

BinTreeNode* BinTree::getRoot() const{
	return this->root;
}


int BinTree::insertLeft(BinTreeNode* parent,void *data){
	/*If we are inserting a new root*/
	if(parent==NULL){
		if(this->size==0){
			root = new BinTreeNode(data);
			this->size++;
			return SUCCESS;
		}
		return FAILURE;
	}
	/*If left of parent is empty*/
	if(parent->getLeftNode()==NULL){
		/*Inserting node to left of parent*/
		if(parent->setLeftNode(data) == SUCCESS){
			this->size++;
			return SUCCESS;
		}
	}
	return FAILURE;
	
}

/*Insert a node to right of parent node*/
int BinTree::insertRight(BinTreeNode* parent,void* data){
	/*If we are inserting a new root*/
	if(parent==NULL){
		if(this->size==0){
			root = new BinTreeNode(data);
			this->size++;
			return SUCCESS;
		}
		return FAILURE;
	}
	/*If right of parent is empty*/
	if(parent->getRightNode()==NULL){
		/*Inserting node to right of parent*/
		if(parent->setRightNode(data) == SUCCESS){
			this->size++;
			return SUCCESS;
		}
	}
	return FAILURE;
}


void BinTree::removeLeft(BinTreeNode* parent){
	BinTreeNode *toRemove;
	/*No removal from emtpy tree*/
	if(this->size == 0)
		return;
	/*If deleting from root*/
	if(parent == NULL)
		toRemove = this->root;
	else
		toRemove = parent->getLeftNode();
	/*recursively remove all nodes to left of parent*/
	if(toRemove != NULL){
		this->removeLeft(toRemove);
		this->removeRight(toRemove);
		//this->destroyData(toRemove);
	}
	delete(toRemove);
	this->size--;
}


void  BinTree::removeRight(BinTreeNode* parent){
	BinTreeNode *toRemove;
	/*No removal from emtpy tree*/
	if(this->size == 0)
		return;
	/*if deleting from root*/
	if(parent == NULL)
		toRemove = this->root;
	else
		toRemove = parent->getRightNode();
	/*recursively remove all nodes to right of parent*/
	if(toRemove != NULL){
		this->removeLeft(toRemove);
		this->removeRight(toRemove);
		//this->destroyData(toRemove);
	}
	delete(toRemove);
	this->size--;
}


int BinTree::destroyData(BinTreeNode* data){
	if(data){
		delete data;
		return SUCCESS;
	}
	else{
		printf("Nothing to delete\n");
		return SUCCESS;
	}
}


int BinTree::countLeaves() {
	leafCount = 0;
	doCountLeaves(root);
	return leafCount;
}

/*Recursively count the number of leaves*/
void BinTree::doCountLeaves(BinTreeNode* node){
	if(node == NULL)
		return;
	if(node->isLeafNode()){
		leafCount++;
	}
	doCountLeaves(node->getLeftNode());
	doCountLeaves(node->getRightNode());
}

/*Count number of non-leaves in the tree*/
int BinTree::countNonLeaves(){
	return(size - countLeaves());
}

/*Get the height of a tree*/
int BinTree::getHeight(){
	return (doGetHeight(root));
}

/*Recursively find height of tree. Tree with root alone has zero height*/
int BinTree::doGetHeight(BinTreeNode* node) {
	if(node==NULL)
		return -1;
	int l = doGetHeight(node->getLeftNode());
	int r = doGetHeight(node->getRightNode());
	/*Compute which side has a higher value*/
	height = 1 + std::max(l,r);
	return height;
}

/*-------------PRE-ORDER TRAVERSAL----------*/
void BinTree::printPreOrder(void (*print)(const void *data)){
	if(root==NULL)
		return;
	else
		doPrintPreOrder(this->root,print);
}

void BinTree::doPrintPreOrder(BinTreeNode* node,void (*print)(const void *data)){
	if(node==NULL)
		return;
	print(node);
	doPrintPreOrder(node->getLeftNode(),print);
	doPrintPreOrder(node->getRightNode(),print);

}

/*-------------IN-ORDER TRAVERSAL----------*/
void BinTree::printInOrder(void (*print)(const void *data)){
	if(root==NULL)
		return;
	else
		doPrintInOrder(this->root,print);
}

void BinTree::doPrintInOrder(BinTreeNode* node,void (*print)(const void *data)){
	if(node==NULL)
		return;
	doPrintInOrder(node->getLeftNode(),print);
	print(node);
	doPrintInOrder(node->getRightNode(),print);

}


/*-------------POST-ORDER TRAVERSAL----------*/
void BinTree::printPostOrder(void (*print)(const void *data)){
	if(root==NULL)
		return;
	else
		doPrintPostOrder(this->root,print);
}

void BinTree::doPrintPostOrder(BinTreeNode* node,void (*print)(const void *data)){
	if(node==NULL)
		return;
	doPrintPostOrder(node->getLeftNode(),print);
	doPrintPostOrder(node->getRightNode(),print);
	print(node);

}

/*Remove all leaves of a tree*/
void BinTree::removeLeaves(){
	if(root==NULL)
		return;
	else{
		doRemoveLeaves(root);
	}
}

/*recursively remove left and right leaves*/
void BinTree::doRemoveLeaves(BinTreeNode* node){
	if(node==NULL)
		return;
	/*If left(current node) is leaf, set left = NULL, delete left(current node)*/
	if ( (node->getLeftNode() != NULL)  ){
		if ( node->getLeftNode()->isLeafNode() == true ){
			printf("Removed %d\n",*((int*)node->getLeftNode()->getData()));
			node->setLeftToNull();
			delete node->getLeftNode();
			this->size--;
		}
	}
	/*If right(current node) is leaf, set right = NULL, delete right(current node)*/
	if ( (node->getRightNode() != NULL)  ){
		if ( node->getRightNode()->isLeafNode() == true ){
			printf("Removed %d\n",*((int*)node->getRightNode()->getData()));
			node->setRightToNull();
			delete node->getRightNode();
			this->size--;
		}
	}
	doRemoveLeaves(node->getLeftNode());
	doRemoveLeaves(node->getRightNode());
}
