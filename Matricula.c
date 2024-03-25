#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Aluno {
    char nome[30];
    struct Data data_nascimento;
    char cpf[12]; // incluindo o caractere nulo '\0'
    int matricula;
};

int validarCPF(char *cpf) {

    return 1; // Retorna 1 se o CPF for válido, 0 caso contrário
}

void cadastrarAluno(struct Aluno *alunos, int indice) {
    printf("Cadastrando Aluno %d\n", indice + 1);

    printf("Nome: ");
    scanf("%s", alunos[indice].nome);

    printf("Data de Nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &alunos[indice].data_nascimento.dia,
          &alunos[indice].data_nascimento.mes,
          &alunos[indice].data_nascimento.ano);

    printf("CPF: ");
    scanf("%s", alunos[indice].cpf);

    // Validar o CPF
    if (!validarCPF(alunos[indice].cpf)) {
        printf("CPF inválido. Cadastro não realizado.\n");
        return;
    }

    printf("Matrícula: ");
    scanf("%d", &alunos[indice].matricula);
}

void findByCPF(struct Aluno *alunos, int tamanho, char *cpf) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(alunos[i].cpf, cpf) == 0) {
            printf("Aluno Encontrado:\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Data de Nascimento: %02d/%02d/%04d\n",
                   alunos[i].data_nascimento.dia,
                   alunos[i].data_nascimento.mes,
                   alunos[i].data_nascimento.ano);
            printf("CPF: %s\n", alunos[i].cpf);
            printf("Matrícula: %d\n", alunos[i].matricula);
            return;
        }
    }

    printf("Aluno com CPF %s não encontrado.\n", cpf);
}

int main() {
    struct Aluno alunos[10];

    for (int i = 0; i < 10; i++) {
        cadastrarAluno(alunos, i);
    }

    char cpf_busca[12];
    printf("Digite o CPF para buscar um aluno: ");
    scanf("%s", cpf_busca);

    findByCPF(alunos, 10, cpf_busca);

    return 0;
}
