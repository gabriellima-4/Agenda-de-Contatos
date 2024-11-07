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

// Função para adicionar um novo contato, usando ponteiro para modificar o contador
void adicionarContato() {
    if (contador >= MAX_CONTATOS) {
        printf("Lista de contatos cheia!\n");
        return;
    }

    Contato *novoContato = &contatos[contador];

    printf("Digite o nome: ");
    scanf(" %[^\n]", novoContato->nome);
    printf("Digite o telefone: ");
    scanf(" %[^\n]", novoContato->telefone);
    if (!validarTelefone(novoContato->telefone)) {
        printf("Telefone inválido! Deve conter apenas números (10-15 dígitos).\n");
        return;
    }

    printf("Digite o email: ");
    scanf(" %[^\n]", novoContato->email);
    if (!validarEmail(novoContato->email)) {
        printf("Email inválido! Por favor, insira um email válido.\n");
        return;
    }

    contador++;
    printf("Contato adicionado com sucesso!\n");
}

// Função para listar todos os contatos
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

// Função para buscar um contato pelo nome
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

// Função para editar um contato existente usando ponteiro
void editarContato() {
    char nome[TAM_NOME];
    printf("Digite o nome do contato que deseja editar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < contador; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            Contato *contato = &contatos[i];
            printf("Editar contato:\n");

            printf("Novo nome: ");
            scanf(" %[^\n]", contato->nome);

            printf("Novo telefone: ");
            scanf(" %[^\n]", contato->telefone);
            if (!validarTelefone(contato->telefone)) {
                printf("Telefone inválido!\n");
                return;
            }

            printf("Novo email: ");
            scanf(" %[^\n]", contato->email);
            if (!validarEmail(contato->email)) {
                printf("Email inválido!\n");
                return;
            }

            printf("Contato editado com sucesso!\n");
            return;
        }
    }

    printf("Contato não encontrado.\n");
}

// Função para remover um contato, ajustando o contador por ponteiro
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
