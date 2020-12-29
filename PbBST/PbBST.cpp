#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "PbBST.h"
using namespace std;

PbBST::PbBST(){
    root = NULL;
}
PbBST::PbBST(const PbBST &tree){
    root = tree.root;
}
//methods
void PbBST::insertKey(const int Key){
		// Position of insertion found; insert after leaf
		if (root == NULL) {
			root = new PbBSTNode(Key, NULL, NULL);
		}
		// Else search for the insertion position
		else if (Key < root->item){
                insertItem(root->leftChildPtr,Key);
		}

		else{
                insertItem(root->rightChildPtr,Key);
        }

}
void PbBST::insertItem(PbBSTNode *&treePtr,const int &newItem){
		// Position of insertion found; insert after leaf
		if (treePtr == NULL) {
			treePtr = new PbBSTNode(newItem, NULL, NULL);
		}
		// Else search for the insertion position
		else if (newItem < treePtr->item)
			insertItem(treePtr->leftChildPtr, newItem);
		else
			insertItem(treePtr->rightChildPtr, newItem);
}
void PbBST::deleteKey(int key){
    deleteItem(root, key);
}
void PbBST::deleteItem(PbBSTNode *&treePtr,int searchKey){
        if (treePtr == NULL)
            cout << "No node found to delete" << endl;
		// Position of deletion found
		else if (searchKey == treePtr->item)
			deleteNodeItem(treePtr);
		// Else search for the deletion position
		else if (searchKey < treePtr->item)
			deleteItem(treePtr->leftChildPtr, searchKey);
		else
			deleteItem(treePtr->rightChildPtr, searchKey);

}
void PbBST::deleteNodeItem(PbBSTNode *&nodePtr){
		PbBSTNode *delPtr;
		int replacementItem;
		// (1)  Test for a leaf
		if((nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL)){
			delete nodePtr;
			nodePtr = NULL;
		}
		// (2)  Test for no left child
		else if(nodePtr->leftChildPtr == NULL){
			delPtr = nodePtr;
			nodePtr = nodePtr->rightChildPtr;
			delPtr->rightChildPtr = NULL;
			delete delPtr;
		}
		// (3)  Test for no right child
		else if (nodePtr->rightChildPtr == NULL) {
			delPtr = nodePtr;
			nodePtr = nodePtr->leftChildPtr;
			delPtr->leftChildPtr = NULL;
			delete delPtr;
		}
		// (4)  There are two children:
		//      Retrieve and delete the inorder successor
		else{
			processLeftmost(nodePtr->rightChildPtr, replacementItem);
			nodePtr->item = replacementItem;
		}
}
void PbBST::processLeftmost(PbBSTNode *&nodePtr, int &treeItem){

		if (nodePtr->leftChildPtr == NULL) {
			treeItem = nodePtr->item;
			PbBSTNode *delPtr = nodePtr;
			nodePtr = nodePtr->rightChildPtr;
			delPtr->rightChildPtr = NULL; // defense
			delete delPtr;
		}
		else
			processLeftmost(nodePtr->leftChildPtr, treeItem);
}
//For Height
int PbBST::getHeight(){
    if(root == NULL){
        return 0;
    }
    return findHeight(root);

}
int PbBST::findHeight(PbBSTNode *node){
    if (node == NULL)
   {
      return 0;
   }
   int lheight = findHeight(node->leftChildPtr);
   int rheight = findHeight(node->rightChildPtr);
       /* use the larger one */
       if (lheight > rheight)
           return(lheight+1);
       else
           return(rheight+1);
}
//For Getting the Node Count
int PbBST::getNodeCount(){
    if(root == NULL){
        return 0;
    }
    return findTotalNode(root);
}
int PbBST::findTotalNode(PbBSTNode *node){
    if(node == NULL){
        return 0;
    }
    else{
        return findTotalNode(node->leftChildPtr) + 1 +findTotalNode(node->rightChildPtr);
    }
}
//For finding the nodes required
int PbBST::findNodesRequired(){
    int FullTreeNumber = 1;
    for(int i = 0; i < getHeight();i++){
        FullTreeNumber = FullTreeNumber *2;
    }
    FullTreeNumber--;
    cout << FullTreeNumber << endl;
    return FullTreeNumber - getNodeCount();
}
//Finding Full Binary Tree Level
int PbBST::findFullBTLevel(){
    if(root == NULL)
        return 0;
    int levelMax = 1;

}
//Time Analysis
void PbBST::AnalysisOfTime(){
    int a = 0;
    for(int i = 0; i < 15000 ; i++){
        for(int j = 1; j < 15000; j = j*2){
            a++;
        }
    }
    cout << "Part e - Time analysis of Binary Search Tree - part 1" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Tree Size Time Elapsed" << endl;
    cout << "-----------------------------------------------------" << endl;
    int arr[15000];
    for(int i = 0;i <= 15000;i++){
        arr[i] = 1 + rand() % 15000;
        clock_t begin_time = clock();
        insertKey(arr[i]);
        if((i % 1500 == 0) && (i >= 1500)){
            cout << i << "         " << begin_time << endl;
        }
    }
    cout << "-----------------------------------------------------" << endl;
    cout << "Part e - Time analysis of Binary Search Tree - part 2" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Tree Size Time Elapsed" << endl;
    cout << "-----------------------------------------------------" << endl;
   for(int i = 0;i<= 15000;i++){
        clock_t begin_time2 = clock();
        deleteKey(arr[i]);
        if((i % 1500 == 0) && (i >= 1500)){
            cout << i << "         " << begin_time2  << endl;
        }
   }

}
int main(){
    PbBST A;
    A.AnalysisOfTime();
}
