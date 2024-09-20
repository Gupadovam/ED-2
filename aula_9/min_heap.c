#include <stdio.h>
#include <stdlib.h>

int pai(int i) {
    return (i - 1) / 2;
}

int esquerda(int i) {
    return (i * 2) + 1;
}

int direita(int i) {
    return (i * 2) + 2;
}

void trocar(int *V, int a, int b) {
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

void imprimir(int *V, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void min_heapify(int *V, int size, int i) {
    int e = esquerda(i);
    int d = direita(i);
    int menor = i;

    if (e < size && V[e] < V[menor]) {
        menor = e;
    }
    if (d < size && V[d] < V[menor]) {
        menor = d;
    }
    if (menor != i) {
        trocar(V, i, menor);
        min_heapify(V, size, menor);
    }
}

void build_min_heap(int *V, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        min_heapify(V, size, i);
    }
}

int heap_extract_min(int *V, int *size) {
    if (*size < 1) {
        printf("Heap underflow\n");
        return -1;
    }
    int min = V[0];
    V[0] = V[*size - 1];
    (*size)--;
    min_heapify(V, *size, 0);
    return min;
}

void heap_decrease_key(int *V, int i, int chave, int size) {
    if (chave > V[i]) {
        printf("Nova chave é maior que a chave atual\n");
        return;
    }
    V[i] = chave;
    build_min_heap(V, size);
}

void min_heap_insert(int *V, int chave, int *size) {
    (*size)++;
    V[*size - 1] = chave;
    heap_decrease_key(V, *size - 1, chave, *size);
}

int main() {
    int size = 10;
    int v[20] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};  // Vetor inicial

    printf("Vetor inicial:\n");
    imprimir(v, size);

    build_min_heap(v, size);
    printf("Depois de build_min_heap:\n");
    imprimir(v, size);

    heap_extract_min(v, &size);
    printf("Depois de heap_extract_min:\n");
    imprimir(v, size);

    // Modificando a última chave {16} para o valor {1}!
    heap_decrease_key(v, size - 1, 1, size);
    printf("Depois de heap_decrease_key na última posição:\n");
    imprimir(v, size);

    // Inserindo uma nova chave com valor {0}!
    min_heap_insert(v, 0, &size);
    printf("Depois de min_heap_insert com valor 0:\n");
    imprimir(v, size);

    return 0;
}
