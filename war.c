// Bibliotecas necessárias
#include <stdio.h>
#include <string.h>


// Constantes globais
#define MAX_TERRITORIOS 5
#define TAM_STRING 50

// Definindo da estrutura (struct)
struct Territorio{
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};

// --- FUNÇÃO DE LIMPAR O BUFFER DE ENTRADA ---
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){

    struct Territorio territorio[MAX_TERRITORIOS];
    int totalTerritorio = 0;
    int opcao;

    // --- Laço Principal do Menu ---
    do{
        printf("=====================================\n");
        printf("Vamos cadastrar os 5 principais territorios do nosso mundo.\n");
        printf("=====================================\n");

        if (totalTerritorio < MAX_TERRITORIOS) {
        printf("1 - Cadastrar territorios\n");
        }

        printf("2 - Listar todos os territorios\n");
        printf("0 - Sair\n");
        printf("-------------------------------------\n");
        printf("Escolha uma opcao\n");

        // Lê as opções do usuário.
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpar o \n deixado pelo scanf.

        // --- Processamento da Opção ---
        switch (opcao){
            case 1: // CADASTRO DE TERRITÓRIOS
            printf(" --- Cadastro de Territorios ---\n\n");

            if (totalTerritorio >= MAX_TERRITORIOS) {
                printf("Todos os %d territorios ja foram cadastrados!\n", MAX_TERRITORIOS);
            } else {
                // Enquanto não chegar no limite de territórios
                while (totalTerritorio < MAX_TERRITORIOS) {
                    printf("\nCadastro do Territorio %d\n", totalTerritorio + 1);

                    printf("Digite o nome do territorio: ");
                    fgets(territorio[totalTerritorio].nome, TAM_STRING, stdin);

                    printf("Digite a cor do territorio: ");
                    fgets(territorio[totalTerritorio].cor, TAM_STRING, stdin);

                    territorio[totalTerritorio].nome[strcspn(territorio[totalTerritorio].nome, "\n")] = '\0';
                    territorio[totalTerritorio].cor[strcspn(territorio[totalTerritorio].cor, "\n")] = '\0';

                    printf("Digite o numero de tropas: ");
                    scanf("%d", &territorio[totalTerritorio].tropas);
                    limparBufferEntrada();

                    totalTerritorio++;

                    printf("Territorio %d cadastrado com sucesso!\n", totalTerritorio);
                }

                printf("\nTodos os %d territorios foram cadastrados!\n", MAX_TERRITORIOS);
            }

            printf("\nPrecione Enter para continuar...");
            getchar(); //Para o usuário ler a mensagem antes de voltar
            break;

            case 2: // LISTAR TERRITÓRIOS
                printf("=== Lista de Territorios ===\n");

                if(totalTerritorio == 0) {
                    printf("Nenhum territorio cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < totalTerritorio; i++) {
                        printf("-----------------------------------\n");
                        printf("TERRITORIO %d\n", i + 1);
                        printf("Nome do territorio: %s\n", territorio[i].nome);
                        printf("Cor do territorio: %s\n", territorio[i].cor);
                        printf("Numero de tropas: %d\n", territorio[i].tropas);
                    }
                    printf("-----------------------------------\n");
                }

                //Pausa pro usuário ver a lista antes dp loop limpar a tela
                printf("\nPrecione Enter para continuar...\n");
                getchar();
                break;

            case 0: // SAIR - ENCERRAR PROGRAMA
                printf("\nSaindo do sistema...\n");
                break;
            
            default: //OPÇÃO INVÁLIDA
                printf("\nOpção inválida! Tente novamente.");
                printf("\nPrecione Enter para continuar...");
                getchar();
                break;
        }
    } while (opcao !=0);

    return 0; //FIM DO PROGRAMA

};
