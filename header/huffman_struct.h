#define MAX_NODES 100
#define MAX_HEIGHT 50 // 100
#define MAX_WIDTH 80  // 300


typedef struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

typedef struct PriorityQueue {
    HuffmanNode* nodes[MAX_NODES];
    int size;
} PriorityQueue;