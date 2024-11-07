#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_TELEFONE 15
#define TAM_EMAIL 50

// Estrutura que representa um contato
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
} Contato;

// Variáveis globais
Contato contatos[MAX_CONTATOS];
int contador = 0;

// Função para exibir o menu
void menu() {
    printf("\nAgenda de Contatos\n");
    printf("1. Adicionar contato\n");
    printf("2. Listar contatos\n");
    printf("3. Buscar contato\n");
    printf("4. Editar contato\n");
    printf("5. Remover contato\n");
    printf("6. Sair\n");
}

// Função para validar telefone
int validarTelefone(const char *telefone) {
    int len = strlen(telefone);
    if (len < 10 || len > 15) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (telefone[i] < '0' || telefone[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Função para validar email
int validarEmail(const char *email) {
    const char *at = strchr(email, '@');
    if (at && strchr(at, '.')) {
        return 1;
    }
    return 0;
}

void adicionarContato() {
    if (contador >= MAX_CONTATOS) {
        printf("Lista de contatos cheia!\n");
        return;
    }

    printf("Digite o nome: ");
    scanf(" %[^\n]", contatos[contador].nome);
    printf("Digite o telefone: ");
    scanf(" %[^\n]", contatos[contador].telefone);
    if (!validarTelefone(contatos[contador].telefone)) {
        printf("Telefone inválido! Deve conter apenas números (10-15 dígitos).\n");
        return;
    }

    printf("Digite o email: ");
    scanf(" %[^\n]", contatos[contador].email);
    if (!validarEmail(contatos[contador].email)) {
        printf("Email inválido! Por favor, insira um email válido.\n");
        return;
    }

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
            if (!validarTelefone(contatos[i].telefone)) {
                printf("Telefone inválido!\n");
                return;
            }

            printf("Novo email: ");
            scanf(" %[^\n]", contatos[i].email);
            if (!validarEmail(contatos[i].email)) {
                printf("Email inválido!\n");
                return;
            }

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
