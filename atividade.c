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

void insertionSort(int v[], int n) {
    int i, j, chave;

    for (i = 1; i < n; i++) {
        chave = v[i]; 
        j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void selectionSort(int v[], int n) {
    int i, j, min, aux;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) min = j;
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = 0;
    int aux[fim - inicio + 1];
    
    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
    }
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim) aux[k++] = v[j++];
    for (i = inicio, k = 0; i <= fim; i++, k++)
    v[i] = aux[k];
}
void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void quickSort(int v[], int inicio, int fim) {
    int i = inicio, j = fim, pivo = v[(inicio + fim) / 2], aux;

    while (i <= j) {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;
        if (i <= j) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    if (inicio < j) quickSort(v, inicio, j);
    if (i < fim) quickSort(v, i, fim);
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
            insertionSort(vetorNumeroOrdenado, 6);
        
            printf("Vetor ordenado (Insertion) ");
            for (int i = 0; i < 6; i++) {
                printf("%d ", vetorNumeroOrdenado[i]);
            }
            break;
        case 3:
            selectionSort(vetorNumeroOrdenado, 6);
            
            printf("Vetor ordenado (Selection) ");
            for (int i = 0; i < 6; i++) {
                printf("%d ", vetorNumeroOrdenado[i]);
            }
            break;
        case 4:
            mergeSort(vetorNumeroOrdenado, 0, 5);

            printf("Vetor ordenado (Merge) ");
            for (int i = 0; i < 6; i++) {
                printf("%d ", vetorNumeroOrdenado[i]);
            }
            break;
        case 5:
            quickSort(vetorNumeroOrdenado, 0, 5);

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
    
    printf("\n\nDeseja alterar o valor do arquivo? (s/n): ");
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