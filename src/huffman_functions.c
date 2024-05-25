#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/huffman_struct.h"

HuffmanNode* createNode(char character, int frequency) {
    HuffmanNode *newNode = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

HuffmanNode* createParentNode(HuffmanNode* left, HuffmanNode* right) {
    HuffmanNode *parentNode = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    parentNode->character = '\0';  // Nodo no hoja
    parentNode->frequency = left->frequency + right->frequency;
    parentNode->left = left;
    parentNode->right = right;
    return parentNode;
}

PriorityQueue* createPriorityQueue() {
    PriorityQueue *pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

void insertNode(PriorityQueue *pq, HuffmanNode *node) {
    pq->nodes[pq->size] = node;
    pq->size++;
    // Ordenar la cola de prioridad según las frecuencias
    for (int i = pq->size - 1; i > 0 && pq->nodes[i]->frequency < pq->nodes[i-1]->frequency; i--) {
        HuffmanNode *temp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[i-1];
        pq->nodes[i-1] = temp;
    }
}

HuffmanNode* extractMin(PriorityQueue *pq) {
    if (pq->size == 0) {
        return NULL;
    }
    HuffmanNode *minNode = pq->nodes[0];
    for (int i = 1; i < pq->size; i++) {
        pq->nodes[i-1] = pq->nodes[i];
    }
    pq->size--;
    return minNode;
}

// Función para imprimir el árbol horizontalmente
void printTreeHorizontal(HuffmanNode* root, int depth, int pos, char s[MAX_HEIGHT][MAX_WIDTH]) {
    if (root == NULL) {
        return;
    }

    char buffer[20];
    if (root->character == '\0') {
        snprintf(buffer, sizeof(buffer), "*:%d", root->frequency);
    } else {
        snprintf(buffer, sizeof(buffer), "%c:%d", root->character, root->frequency);
    }

    int startPos = pos - strlen(buffer) / 2;
    for (size_t i = 0; i < strlen(buffer); i++) {
        s[depth][startPos + i] = buffer[i];
    }

    if (root->left != NULL) {
        s[depth + 1][pos - 1] = '/';
        printTreeHorizontal(root->left, depth + 2, pos - 4, s);
    }
    if (root->right != NULL) {
        s[depth + 1][pos + 1] = '\\';
        printTreeHorizontal(root->right, depth + 2, pos + 4, s);
    }
}

void printTree(HuffmanNode* root) {
    char s[MAX_HEIGHT][MAX_WIDTH];
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            s[i][j] = ' ';
        }
    }
    printTreeHorizontal(root, 0, MAX_WIDTH / 2, s);

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            putchar(s[i][j]);
        }
        putchar('\n');
    }
}