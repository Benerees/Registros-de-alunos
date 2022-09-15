#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
  int dia;
  int mes;
  int ano;
} data;

typedef struct aluno {
  char nome[30];
  data dataNasc;
  int ra;
  float notas[3];
  int freq;
} aluno;

void imprimeMenu() {
  printf("\n1 - Inserir Aluno.");
  printf("\n2 - Remover Aluno.");
  printf("\n3 - Listar Alunos.");
  printf("\n4 - Buscar Aluno.");
  printf("\n5 - Sair.");
}

void removeAluno(aluno turma[], int *n) {
  int i, p, j;
  if (*n < 1) {
    printf("Lista vazia! \n");
    return;
  }
  i = buscarAluno(turma, *n);
  p = i;
  if (i != -1) {
    if (*n > 1) {
      while (p < *n - 1) {
        strcpy(turma[p].nome, turma[p + 1].nome);
        turma[p].dataNasc.dia = turma[p + 1].dataNasc.dia;
        turma[p].dataNasc.mes = turma[p + 1].dataNasc.mes;
        turma[p].dataNasc.ano = turma[p + 1].dataNasc.ano;
        turma[p].ra = turma[p + 1].ra;
        for (j = 0; j < 3; j++) {
          turma[p].notas[j] = turma[p + 1].notas[j];
        }
        p++;
      }
    }
    printf("Remoção feita com sucesso! \n");
    *n = *n - 1;
    return;
  }
  printf("Não foi possível fazer a remoção! \n");
}

int buscarAluno(aluno turma[], int n) {
  int buscaRA;
  printf("Digite o RA: ");
  scanf("%d", &buscaRA);
  for (int cont = 0; cont < n; cont++) {
    if (turma[cont].ra == buscaRA)
      return cont;
  }
  return -1;
}

void insereAluno(aluno turma[], int n) {
  int i;

  getchar();
  printf("Nome: ");
  fgets(turma[n].nome, sizeof(turma[n].nome), stdin);
  turma[n].nome[strlen(turma[n].nome) - 1] = '\0';
  printf("Data de Nascimento\n");
  printf("Dia: ");
  scanf("%i", &turma[n].dataNasc.dia);
  printf("Mes: ");
  scanf("%i", &turma[n].dataNasc.mes);
  printf("Ano: ");
  scanf("%i", &turma[n].dataNasc.ano);
  printf("RA: ");
  scanf("%i", &turma[n].ra);
  for (i = 0; i < 3; i++) {
    printf("Nota %i: ", i + 1);
    scanf("%f", &turma[n].notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i", &turma[n].freq);
}

void listaAlunos(aluno turma[], int n) {
  int i, j;
  if (n > 0) {
    for (i = 0; i < n; i++) {
      printf("\n\nNome: %s\n", turma[i].nome);
      printf("Data de Nascimento: %i/%i/%i\n", turma[i].dataNasc.dia,
             turma[i].dataNasc.mes, turma[i].dataNasc.ano);
      printf("RA: %i\n", turma[i].ra);
      for (j = 0; j < 3; j++)
        printf("Nota %i: %.2f\n", j + 1, turma[i].notas[j]);
      printf("Frequencia: %i\n", turma[i].freq);
    }
  } else
    printf("Lista vazia! \n");
}

int main() {
  aluno turmaAED[50];
  int n = 0, op = 0, i = 0, j = 0;

  while (op != 5) {
    imprimeMenu();
    printf("\nOpcao: ");
    scanf("%i", &op);
    switch (op) {
    case 1:
      if (n < 50) {
        insereAluno(turmaAED, n);
        n++;
      } else
        printf("Lista cheia!");
      break;
    case 2:
      removeAluno(turmaAED, &n);
      break;
    case 3:
      listaAlunos(turmaAED, n);
      break;
    case 4:
      if (n > 0) {
        i = buscarAluno(turmaAED, n);
        if (i != -1) {
          printf("\n\nNome: %s\n", turmaAED[i].nome);
          printf("Data de Nascimento: %i/%i/%i\n", turmaAED[i].dataNasc.dia,
                 turmaAED[i].dataNasc.mes, turmaAED[i].dataNasc.ano);
          printf("RA: %i\n", turmaAED[i].ra);
          for (j = 0; j < 3; j++)
            printf("Nota %i: %.2f\n", j + 1, turmaAED[i].notas[j]);
          printf("Frequencia: %i\n", turmaAED[i].freq);
        } else {
          printf("RA não encontrado! \n");
        }
      } else
        printf("Lista vazia! \n");
      break;
    case 5:
      printf("\nObrigado.");
      break;
    default:
      printf("\nOpção Inválida.");
      break;
    }
  }

  return 0;
}