#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanho máximo de cada tipo de string
// #define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_TELEFONE 15
#define TAM_EMAIL 50

// Classe (ou struct) contato
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
} Contato;

Contato contatos[MAX_CONTATOS]; //Lista
int contador = 0; //Mostra quantos usuários já foram cadastrados

void adicionarContato() {
    if (contador >= MAX_CONTATOS) {
        printf("Lista de contatos cheia!\n");
        return;
    }

    printf("Digite o nome: ");
    scanf(" %[^\n]", contatos[contador].nome);
    printf("Digite o telefone: ");
    scanf(" %[^\n]", contatos[contador].telefone);
    printf("Digite o email: ");
    scanf(" %[^\n]", contatos[contador].email);

    contador++;
    printf("Contato adicionado com sucesso!\n");
}

void listarContatos() {
    if (contador == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("Lista de contatos:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d - Nome: %s | Telefone: %s | Email: %s\n", i + 1, contatos[i].nome, contatos[i].telefone, contatos[i].email);
    }
}

void buscarContato() {
    char nome[TAM_NOME];
    printf("Digite o nome do contato que deseja buscar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < contador; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            printf("Contato encontrado:\nNome: %s | Telefone: %s | Email: %s\n", contatos[i].nome, contatos[i].telefone, contatos[i].email);
            return;
        }
    }

    printf("Contato não encontrado.\n");
}

void editarContato() {
    char nome[TAM_NOME];
    printf("Digite o nome do contato que deseja editar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < contador; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            printf("Editar contato:\n");
            printf("Novo nome: ");
            scanf(" %[^\n]", contatos[i].nome);
            printf("Novo telefone: ");
            scanf(" %[^\n]", contatos[i].telefone);
            printf("Novo email: ");
            scanf(" %[^\n]", contatos[i].email);

            printf("Contato editado com sucesso!\n");
            return;
        }
    }

    printf("Contato não encontrado.\n");
}

void removerContato() {
    char nome[TAM_NOME];
    printf("Digite o nome do contato que deseja remover: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < contador; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            for (int j = i; j < contador - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            contador--;
            printf("Contato removido com sucesso!\n");
            return;
        }
    }

    printf("Contato não encontrado.\n");
}

void menu() {
    printf("\nAgenda de Contatos\n");
    printf("1. Adicionar contato\n");
    printf("2. Listar contatos\n");
    printf("3. Buscar contato\n");
    printf("4. Editar contato\n");
    printf("5. Remover contato\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                listarContatos();
                break;
            case 3:
                buscarContato();
                break;
            case 4:
                editarContato();
                break;
            case 5:
                removerContato();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    return 0;
}
