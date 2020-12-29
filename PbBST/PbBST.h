#ifndef __PBST_H
#define __PBST_H
#include <string>
#include "PbBSTNode.h"
using namespace std;
class PbBST{
public:
    PbBST();
    PbBST(const PbBST &tree);
//Ýnsert and delete key items
    void insertKey(const int Key);
    void insertItem(PbBSTNode *&node,const int &item);
    //For Deletion
    void deleteKey(int key);
    void deleteItem(PbBSTNode *&treePtr,int searchKey);
    void deleteNodeItem(PbBSTNode *&nodePtr);
    void processLeftmost(PbBSTNode *&nodePtr, int &treeItem);
    //Getting Height
    int getHeight();
    int findHeight(PbBSTNode *node);
    //Getting Node Count
    int getNodeCount();
    int findTotalNode(PbBSTNode *node);
    //Nodes Required
    int findNodesRequired();
    int findFullBTLevel();
    void mirrorTree();
    void printTree();
    //Time Analysis
    void AnalysisOfTime();
private:
    PbBSTNode *root;
};
#endif
