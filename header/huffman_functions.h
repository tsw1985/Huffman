#include "huffman_struct.h"
HuffmanNode* createNode(char character, int frequency);
HuffmanNode* createParentNode(HuffmanNode* left, HuffmanNode* right);
PriorityQueue* createPriorityQueue();
void insertNode(PriorityQueue *pq, HuffmanNode *node);
HuffmanNode* extractMin(PriorityQueue *pq);
void printTree(HuffmanNode* root);
void printTreeHorizontal(HuffmanNode* root, int depth, int pos, char s[MAX_HEIGHT][MAX_WIDTH]);