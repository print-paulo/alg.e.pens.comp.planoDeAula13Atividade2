#include <stdlib.h>
#include <stdio.h>

void bubbleSort(int v[], int n) {
    int i, j, aux;
    // Percorre o vetor várias vezes
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Se o elemento atual for maior que o próximo, troca
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int main () {
    int numDesordenado, opcao;
    char linha[100];

    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.");
        return 1;
    }
    fclose(arquivo);

    printf("Digite 6 números (de forma desordenada)\n");
    arquivo = fopen("dados.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    for (int i = 0; i < 6; i++) {
        printf("\n\n%d° Número\n\n", i + 1);
        scanf("%d", &numDesordenado);
        fprintf(arquivo, "%d\n", numDesordenado);
    }
    fclose(arquivo);

    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao ler o arquivo.");
        return 1;
    }


    printf("\nConteúdo do arquivo: \n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    
    fclose(arquivo);

    printf("\n-----------TIPO DE ORDENAÇÃO-----------\n");
    printf("\n1 - Bubble Sort");
    printf("\n2 - Insertion");
    printf("\n3 - Selection");
    printf("\n4 - Merge");
    printf("\n5 - Quick Sort");

    switch (opcao) {
        case 1:

    }

    return 0;
}