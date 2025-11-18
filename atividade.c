#include <stdlib.h> // Necessário para funções gerais (embora não muito usada aqui, é boa prática)
#include <stdio.h>  // Necessário para printf, scanf e manipulação de ficheiros (FILE)
#include <string.h> // Necessário para manipulação de strings (char)

// --- ALGORITMO BUBBLE SORT ---
// Ideia: "Borbulha" os maiores valores para o final do vetor comparando pares adjacentes.
void bubbleSort(int v[], int n) {
    int i, j, aux;
    // Laço externo: controla quantas passagens fazemos no vetor
    for (i = 0; i < n - 1; i++) {
        // Laço interno: compara e troca os elementos
        for (j = 0; j < n - i - 1; j++) {
            // Se o elemento atual for maior que o próximo, troca-os de lugar
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

// --- ALGORITMO INSERTION SORT ---
// Ideia: Funciona como organizar cartas na mão. Pega num valor e insere-o na posição correta entre os anteriores.
void insertionSort(int v[], int n) {
    int i, j, chave;
    
    // Começa do segundo elemento (índice 1) até ao fim
    for (i = 1; i < n; i++) {
        chave = v[i]; // Guarda o valor que queremos inserir na parte ordenada
        j = i - 1;

        // Move os elementos maiores que a 'chave' uma posição para a frente
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave; // Insere a chave na posição correta
    }
}

// --- ALGORITMO SELECTION SORT ---
// Ideia: Procura o menor valor da lista e coloca-o na primeira posição, depois o segundo menor na segunda, etc.
void selectionSort(int v[], int n) {
    int i, j, min, aux;

    for (i = 0; i < n - 1; i++) {
        min = i; // Assume que o atual é o menor
        // Procura no resto do vetor se existe alguém menor
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) min = j; // Atualiza o índice do menor encontrado
        }
        // Troca o valor atual pelo menor valor encontrado
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

// --- ALGORITMO MERGE SORT ---
// Ideia: "Dividir para conquistar". Divide o vetor ao meio recursivamente e depois junta (merge) as partes de forma ordenada.

// Função auxiliar para juntar dois sub-vetores ordenados
void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = 0;
    int aux[fim - inicio + 1]; // Cria um vetor auxiliar temporário
    
    // Compara elementos das duas metades e coloca o menor no vetor auxiliar
    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
    }
    // Se sobraram elementos na primeira metade, copia-os
    while (i <= meio) aux[k++] = v[i++];
    // Se sobraram elementos na segunda metade, copia-os
    while (j <= fim) aux[k++] = v[j++];
    
    // Copia o vetor auxiliar ordenado de volta para o vetor original
    for (i = inicio, k = 0; i <= fim; i++, k++)
        v[i] = aux[k];
}

// Função principal do Merge Sort (recursiva)
void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);     // Ordena a metade esquerda
        mergeSort(v, meio + 1, fim);    // Ordena a metade direita
        merge(v, inicio, meio, fim);    // Junta as duas metades
    }
}

// --- ALGORITMO QUICK SORT ---
// Ideia: Escolhe um "pivô" e coloca os menores à esquerda e os maiores à direita.
void quickSort(int v[], int inicio, int fim) {
    int i = inicio, j = fim, pivo = v[(inicio + fim) / 2], aux;

    // Particionamento do vetor
    while (i <= j) {
        while (v[i] < pivo) i++; // Avança i enquanto for menor que o pivô
        while (v[j] > pivo) j--; // Recua j enquanto for maior que o pivô
        if (i <= j) {
            // Troca os elementos de lugar
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    // Chamadas recursivas para ordenar as sub-partes
    if (inicio < j) quickSort(v, inicio, j);
    if (i < fim) quickSort(v, i, fim);
}

int main () {
    // Declaração de variáveis
    int vetorNumero[6], vetorNumeroOrdenado[6], opcao, i = 0;
    char linha[100];      // Buffer para ler linhas do ficheiro
    char escolhaUsuario;  // Para armazenar 's' ou 'n'

    // --- PASSO 1: INICIALIZAÇÃO DO FICHEIRO ---
    // Abre com "w" (write) apenas para limpar/criar o arquivo "dados.txt" do zero
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    fclose(arquivo); // Fecha imediatamente após limpar

    // --- PASSO 2: LEITURA DOS DADOS ---
    printf("Digite 6 números (de forma desordenada)\n");
    
    // Abre agora com "a" (append) para adicionar dados
    arquivo = fopen("dados.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    // Loop para pedir 6 números e guardar no vetor E no ficheiro
    for (int i = 0; i < 6; i++) {
        printf("\n\n%d° Número\n\n", i + 1);
        scanf("%d", &vetorNumero[i]);
        fprintf(arquivo, "%d\n", vetorNumero[i]); // Escreve no .txt
    }
    fclose(arquivo); // É importante fechar o arquivo após o uso

    // --- PASSO 3: MENU E ORDENAÇÃO (LOOP INFINITO) ---
    while (1) {
        // Abre para leitura ("r") apenas para mostrar o conteúdo atual
        arquivo = fopen("dados.txt", "r");
        if (arquivo == NULL) {
            printf("Erro ao ler o arquivo.\n");
            return 1;
        }

        printf("\nConteúdo do arquivo: \n");
        // Lê linha por linha e imprime na tela
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            printf("%s", linha);
        }
        fclose(arquivo);

        // Exibe o menu
        printf("\n-----------TIPO DE ORDENAÇÃO-----------\n");
        printf("\n1 - Bubble Sort");
        printf("\n2 - Insertion");
        printf("\n3 - Selection");
        printf("\n4 - Merge");
        printf("\n5 - Quick Sort");

        printf("\nDigite o tipo de ordenação que desejas (1-5): ");
        scanf("%d", &opcao);

        // --- CÓPIA DO VETOR ---
        // Importante: Copiamos o vetor original para um novo vetor.
        // Assim, não perdemos a ordem original dos dados em 'vetorNumero'.
        for (int k = 0; k < 6; k++) {
            vetorNumeroOrdenado[k] = vetorNumero[k];
        }

        // Executa a ordenação escolhida no 'vetorNumeroOrdenado'
        switch (opcao) {
            case 1:
                bubbleSort(vetorNumeroOrdenado, 6);
                printf("Vetor ordenado (Bubble Sort) ");
                break;
            case 2:
                insertionSort(vetorNumeroOrdenado, 6);
                printf("Vetor ordenado (Insertion) ");
                break;
            case 3:
                selectionSort(vetorNumeroOrdenado, 6);
                printf("Vetor ordenado (Selection) ");
                break;
            case 4:
                mergeSort(vetorNumeroOrdenado, 0, 5); // Índices 0 a 5
                printf("Vetor ordenado (Merge) ");
                break;
            case 5:
                quickSort(vetorNumeroOrdenado, 0, 5); // Índices 0 a 5
                printf("Vetor ordenado (Quick Sort) ");
                break;
        }

        // Imprime o resultado ordenado na tela
        for (int i = 0; i < 6; i++) {
            printf("%d ", vetorNumeroOrdenado[i]);
        }

        // --- PASSO 4: GUARDAR ORDENADO EM NOVO FICHEIRO ---
        // Limpa/Cria o arquivo "ordenado.txt"
        FILE *arquivoOrdenado = fopen("ordenado.txt", "w");
        // Nota: O código original verifica 'arquivo' aqui, mas devia verificar 'arquivoOrdenado'
        if (arquivoOrdenado == NULL) { 
            printf("Erro ao criar o arquivo.\n");
            return 1;
        }   
        fclose(arquivoOrdenado);

        // Grava os números ordenados
        arquivoOrdenado = fopen("ordenado.txt", "a");
        if (arquivoOrdenado == NULL) { // Correção na verificação
            printf("Erro ao criar o arquivo.\n");
            return 1;
        }
        for (int i = 0; i < 6; i++) {
            fprintf(arquivoOrdenado, "%d\n", vetorNumeroOrdenado[i]);
        }
        fclose(arquivoOrdenado);
        
        // --- PASSO 5: ALTERAR DADOS ---
        // Prepara para ler os dados originais e escrever num temporário
        arquivo = fopen("dados.txt", "r"); // Variável reutilizada (leitura)
        FILE *temp = fopen("temp.txt", "w"); // Arquivo temporário (escrita)
        
        if (arquivo == NULL || temp == NULL) {
            printf("Erro ao abrir os arquivos!\n");
            return 1;
        }
        
        printf("\n\nDeseja alterar o valor do arquivo? (s/n): ");
        scanf("%s", &escolhaUsuario); // Nota: scanf com %s lê string, melhor usar " %c" para char único

        i = 0;
        if (escolhaUsuario == 's' || escolhaUsuario == 'S') {
            // Lê o arquivo original linha a linha
            while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                if (i < 6) { // Garante que só pedimos para os 6 números
                    // Mostra o valor (Atenção: o código original mostra o valor ORDENADO aqui, não o original)
                    printf("\n\n%d° Número (valor atual: %d)\n", i + 1, vetorNumero[i]); 

                    printf("Novo valor: \n");
                    scanf("%d", &vetorNumero[i]); // Lê novo valor
                    fprintf(temp, "%d\n", vetorNumero[i]); // Escreve no temp
                }
                else {
                    fprintf(temp, "%s", linha); // Copia resto do arquivo se houver
                }
                i++;
            }
            // Fecha os ficheiros antes de renomear
            fclose(arquivo);
            fclose(temp);
            
            // Substitui o arquivo antigo pelo novo
            remove("dados.txt");
            rename("temp.txt", "dados.txt");
        }
        else {
            // Se o usuário disser 'n', fecha tudo e sai do programa
            fclose(arquivo);
            fclose(temp);
            remove("temp.txt"); // Remove o temporário que não foi usado
            break; // Sai do loop while(1)
        }
    } // Fim do while(1)
    
    return 0;
}