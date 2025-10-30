#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    int vetorNumero[6], vetorNumeroOrdenado[6], opcao, i = 0;
    char linha[100];
    char escolhaUsuario;

    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    fclose(arquivo);

    printf("Digite 6 números (de forma desordenada)\n");
    arquivo = fopen("dados.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    for (int i = 0; i < 6; i++) {
        printf("\n\n%d° Número\n\n", i + 1);
        scanf("%d", &vetorNumero[i]);
        fprintf(arquivo, "%d\n", vetorNumero[i]);
    }
    fclose(arquivo);

    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao ler o arquivo.\n");
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

    printf("\nDigite o tipo de ordenação que desejas (1-5): ");
    scanf("%d", &opcao);

    for (int k = 0; k < 6; k++) {
        vetorNumeroOrdenado[k] = vetorNumero[k];
    }

    switch (opcao) {
        case 1:
            bubbleSort(vetorNumeroOrdenado, 6);

            printf("Vetor ordenado (Bubble Sort) ");
            for (int i = 0; i < 6; i++) {
                printf("%d ", vetorNumeroOrdenado[i]);
            }
            break;
        case 2:
            printf("Vetor ordenado (Insertion) ");
            for (int i = 0; i < 6; i++) {
                printf("%d ", vetorNumeroOrdenado[i]);
            }
            break;
        case 3:
            printf("Vetor ordenado (Selection) ");
            for (int i = 0; i < 6; i++) {
                printf("%d ", vetorNumeroOrdenado[i]);
            }
            break;
        case 4:
            printf("Vetor ordenado (Merge) ");
            for (int i = 0; i < 6; i++) {
                printf("%d ", vetorNumeroOrdenado[i]);
            }
            break;
        case 5:
            printf("Vetor ordenado (Quick Sort) ");
            for (int i = 0; i < 6; i++) {
                printf("%d ", vetorNumeroOrdenado[i]);
            }
            break;
    }
    
    FILE *arquivoOrdenado = fopen("ordenado.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }   
    fclose(arquivoOrdenado);

    arquivoOrdenado = fopen("ordenado.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    for (int i = 0; i < 6; i++) {
        fprintf(arquivoOrdenado, "%d\n", vetorNumeroOrdenado[i]);
    }
    fclose(arquivoOrdenado);
    
    arquivoOrdenado = fopen("dados.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivoOrdenado == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return 1;
    }
    
    printf("\n\nDeseja alterar o valor do arquivo? (s/n)");
    scanf("%s", &escolhaUsuario);
    
    if (escolhaUsuario == 's' || escolhaUsuario == 'S') {
        while (fgets(linha, sizeof(linha), arquivoOrdenado) != NULL) {
            if (i < 100) {
                printf("\n\n%d° Número (valor atual da linha: %d)\n", i + 1, vetorNumeroOrdenado[i]);

                printf("Novo valor: \n");
                scanf("%d", &vetorNumeroOrdenado[i]);
                fprintf(temp, "%d\n", vetorNumeroOrdenado[i]);
            }
            else {
                fprintf(temp, "%s", linha);
            }
            i++;
        }
    }
    else {
        rewind(arquivoOrdenado);
        while (fgets(linha, sizeof(linha), arquivoOrdenado) != NULL) {
            fprintf(temp, "%s", linha);
        }
    }
    fclose(arquivoOrdenado);
    fclose(temp);
    
    remove("ordenado.txt");
    rename("temp.txt", "ordenado.txt");
    return 0;
}