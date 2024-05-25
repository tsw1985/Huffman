#include <stdio.h>
#include <stdlib.h>
//#include "../header/huffman_struct.h"
#include "../header/huffman_functions.h"


int main(int argc, char *argv[])
{

   // Crear una cola de prioridad
    PriorityQueue *pq = createPriorityQueue();

    // Insertar nodos iniciales
    insertNode(pq, createNode('A', 5));
    insertNode(pq, createNode('B', 2));
    insertNode(pq, createNode('C', 1));
    insertNode(pq, createNode('D', 1));
    insertNode(pq, createNode('R', 2));

    // Construir el árbol de Huffman
    while (pq->size > 1) {
        HuffmanNode *left = extractMin(pq);
        HuffmanNode *right = extractMin(pq);
        HuffmanNode *parent = createParentNode(left, right);
        insertNode(pq, parent);
    }

    // El nodo raíz del árbol de Huffman
    HuffmanNode *root = extractMin(pq);

    // Imprimir el árbol de Huffman
    printf("Árbol de Huffman:\n");
    printTree(root);

    // Liberar memoria
    free(root);
    free(pq);

    return 0;
}