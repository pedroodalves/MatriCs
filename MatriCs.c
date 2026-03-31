#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int ordem = 3;

// Função para calcular índice
int indice(int i, int j, int ordem){
    return i * ordem + j;
}

//Função para encontrar elemento:
int buscarElemento(int vet[], int i, int j){

    return vet[indice(i, j, ordem)];
}

//Função para adicionar elemento:
void adicionarElemento(int vet[], int val, int i, int j){

    vet[indice(i, j, ordem)] = val;
}

//Função que lê os valores a serem inseridos:
void inserir(int vet[]){

    int linhaTemp, colunaTemp, valor;

    printf("Informe a linha do elemento a ser informado:");
    scanf("%d", &linhaTemp);
    if(linhaTemp < 1 || linhaTemp > ordem) {
        printf("Linha inválida!\n");
        return;
    }
    printf("Informe a coluna do elemento a ser informado:");
    scanf("%d", &colunaTemp);
    if(colunaTemp < 1 || colunaTemp > ordem) {
        printf("Coluna inválida!\n");
        return;
    }
    printf("Informe o valor a ser armazenado na linha %d, coluna %d:", linhaTemp, colunaTemp);
    scanf("%d", &valor);
    adicionarElemento(vet, valor, linhaTemp - 1, colunaTemp - 1);
    printf("O elemento %d foi armazenado na linha %d, coluna %d.\n", valor, linhaTemp, colunaTemp);
}

//Função que lê os valores a serem exibidos:
void exibir(int vet[]){

    int linhaTemp, colunaTemp;
    printf("Informe a linha do elemento a ser exibido:");
    scanf("%d", &linhaTemp);
    if(linhaTemp < 1 || linhaTemp > ordem) {
        printf("Linha inválida!\n");
        return;
    }
    printf("Informe a coluna do elemento a ser exibido:");
    scanf("%d", &colunaTemp);
    if(colunaTemp < 1 || colunaTemp > ordem) {
        printf("Coluna inválida!\n");
        return;
    }
    printf("O elemento atualmente armazenado na linha %d, coluna %d é %d.\n", linhaTemp, colunaTemp, buscarElemento(vet, linhaTemp - 1, colunaTemp - 1));
}

// Função para imprimir matriz
void imprimirMatriz(int vetor[]){
    for(int i = 0; i < ordem; i++) {
        for(int j = 0; j < ordem; j++) {
            printf("%d ", buscarElemento(vetor, i, j));
        }
        printf("\n");
    }
    printf("\n");
}

//Função para zerar matriz
void zerarMatriz(int vetor[]){
    
    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++)
        {
            adicionarElemento(vetor, 0, i, j);
        }
    }
}

// Função para preencher matriz manualmente
void preencherMatriz(int vetor[]){

    int valor;
    
    for(int i = 0; i < ordem; i++) {
        for(int j = 0; j < ordem; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &valor);
            adicionarElemento(vetor, valor, i, j);
        }
    }
}

//Função para gerar uma matriz aleatória:
void matrizRand(int vetor[]){

    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++){
            int valor = rand() % 100;
            adicionarElemento(vetor, valor, i, j);
        }
    }
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

// MAIN com uma mini-interface para escolher as funções e chamá-las:
int main() {

    int controle;
    int matriz[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    srand(time(NULL));
    
    printf("==================== SEJA BEM-VINDO AO PROGRAMA MATRICS.C! ====================\n");
    printf("============================ by pedroodalves, 2026 ============================\n");

    do{
        printf("Selecione qual função você deseja realizar utilizando as opções abaixo:\n");
        printf("1 - Exibir valores atuais da matriz.\n");
        printf("2 - Inserir valor em posição específica.\n");
        printf("3 - Exibir valor de posição específica.\n");
        printf("4 - Preencher matriz completa manualmente.\n");
        printf("5 - Preencher matriz completa aleatoriamente.\n");
        printf("6 - Resetar/Zerar matriz.\n");
        printf("Pressione 0 para encerrar o programa.\n");

        scanf("%d", &controle);

        switch(controle){

            case 1:
                printf("Imprimindo valores atuais da matriz...\n");
                imprimirMatriz(matriz);
                pausar();
                break;
            
            case 2:
                inserir(matriz);
                pausar();
                break;

            case 3:
                exibir(matriz);
                pausar();
                break;

            case 4:
                printf("Preenchendo matriz...\n");
                preencherMatriz(matriz);
                printf("Matriz informada:\n");
                imprimirMatriz(matriz);
                pausar();
                break;
                
            case 5:
                printf("Gerando matriz aleatória...\n");
                matrizRand(matriz);
                imprimirMatriz(matriz);
                pausar();
                break;
            
            case 6:
                printf("Zerando matriz...\n");
                zerarMatriz(matriz);
                imprimirMatriz(matriz);
                pausar();
                break;
            
            case 0:
                printf("Encerrando programa...\n");
                break;
            
            default:
                printf("Opção inválida!\n");
                pausar();
                break;
        }

    }while(controle != 0);

    return 0;
}

//AUT VIAM INVENIAM, AUT FACIAM