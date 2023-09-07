#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// NOME: THYAGO FABRICIO MELO COSTA
// TURMA 01 DE ALGORITMO
// DATA: 09/09/2023
// PRIMEIRO PERÍODO DE BTI

//o principal propósito deste programa é tornar o processo de registro e
//análise das notas dos alunos em uma disciplina determinada mais clara,
//eficiente e organizada, esperançosa para o aprimoramento do ensino e
//tomada de decisões comportamentais.


// OBS; compilador desse projeto foi online o replit.

// "CAIXINHA DE VARIAVEL DE ALUNOS"
struct var{
  char nome[80];
  float rec,nota1,nota2,nota3,media;
  char situacao[20];
};
// "CAIXINHA DE VARIAVEL DE CADASTRO"
struct cadastro {
    char disciplina[50];
    char login[45];
    char senha[45];
    char email[80]; // 80 caracteres como foi pedido na atividade 
};
int us = -1;
struct cadastro usuario[100];
//DEIXANDO A VARIAVEL GLOBL (ESCOPO GLOBAL );
struct var vars[100];
int qtd; //QUANTIDADE DE ALUNO CADASTRADO DESEJADO PELO PROFESSOR.
int qtd2 = 0;
int matriculaprof;

// FUNCIONALIDADES DO PRROGRAMA CADA FUNÇÃO TENDO UMA FUNCIONALIDADE ESPECÍFICA;
int validaremail(const char* email){
  if (strchr(email, '@') != NULL){
    return 1;
  }
  else{
    return 0;
  }
}
void cadastrarUsuario() {
    do {
        if (qtd < 100) {
            printf("--------------------------------------\n");
            printf("            CADASTRAMENTO             \n");
            printf("--------------------------------------\n");
            printf("DIGITE A DISCIPLINA: ");
            scanf("%s", usuario[qtd2].disciplina);

            printf("DIGITE O LOGIN: ");
            scanf("%s", usuario[qtd2].login);

            printf("DIGITE A SENHA: ");
            scanf("%s", usuario[qtd2].senha);

            printf("DIGITE O EMAIL: ");
            scanf("%s", usuario[qtd2].email);

            if (validaremail(usuario[qtd2].email)) {
                printf("EMAIL VÁLIDO\n");
                printf("USUÁRIÁRIO CDASTRADO COM SUCESSO!\n");
                qtd2++;
                break; 
            } else {
                printf("EMAIL INVÁLIDO! TENTE NOVAMENTE.\n");
                
            }
        } else {
            printf("LIMITE DE USSUÁRIOS ATINGIDOS. \n");
            break;
        }
    } while (1); 
  //system("clear");
}
int login() {
    char login[45];
    char senha[45];
    int i, tentativas = 0;
    int maxTentativas = 3; 

    printf("-----------------------------\n");
    printf("--------TELA DE LOGIN--------\n");
    printf("-----------------------------\n");

    while (tentativas < maxTentativas) { 
        printf("TENTATIVA %d\n", tentativas + 1);
        printf("DIGITE O LOGIN: ");
        scanf("%s", login);
        printf("DIGITE A SENHA: ");
        scanf("%s", senha);

        for (i = 0; i < qtd2; i++) {
            if (strcmp(login, usuario[i].login) == 0 && strcmp(senha, usuario[i].senha) == 0) {
                return i; 
            }
        }

        printf("CRENDENCIAIS INVÁLIDAS. TENTE NOVAMENTE.\n");
        tentativas++;
    }

    printf(" NÚMERO MÁXIMO DE TENTANTIVAS EXCEDIDO.\n");
    return -1; 
}

void cadastrar(){
  int i;
  printf("DIGITE A QUANTIDADE DE ALUNO QUE DESEJA CADASTRAR: ");
  scanf("%d",&qtd);
  for(i = 0; i < qtd; i++){
    printf("-------------------------ALUNO %d --------------------------\n",i+1);
    printf("DIGITE O NOME DO ALUNO: ");
    scanf("%s", vars[i].nome);
    printf("DIGITE A PRIMEIRA NOTA: ");
    scanf("%f",&vars[i].nota1);
    printf("DIGITE A SEGUNDA NOTA: ");
    scanf("%f",&vars[i].nota2);
    printf("DIGITE A TERCEIRA NOTA: ");
    scanf("%f",&vars[i].nota3);
    vars[i].media = (vars[i].nota1 + vars[i].nota2 + vars[i].nota3) / 3;

    if(vars[i].media >= 7){
      strcpy(vars[i].situacao,"APROVADO");
    }
    else if(vars[i].media >= 4 && vars[i].media < 7){
      strcpy(vars[i].situacao,"RECUPERAÇÃO");
    }
    else{
      strcpy(vars[i].situacao,"REPROVADO");
    }
      
  }
}
void recuperacao(){
  int cod;
  printf("DIGITE O MATRICULA DO ALUNO: ");
  scanf("%d",&cod);
  if(cod >= 0 && cod < qtd){
    printf("NOTA REUPERAÇÃO: ");
    scanf("%f",&vars[cod].rec);
    vars[cod].media = (vars[cod].media + vars[cod].rec) / 2;
  
    if(vars[cod].media >= 7){
      strcpy(vars[cod].situacao,"APROVADO");
  }
    else{
      strcpy(vars[cod].situacao,"REPROVADO");
  }
  
    printf("NOME: %s\n",vars[cod].nome);
    printf("NOTAS: %.2f, %.2f, %.2f\n", vars[cod].nota1,vars[cod].nota2,vars[cod].nota3);
    printf("NOTA DA RECUPERAÇÃO: %.2f\n",vars[cod].rec);
    printf("A NOVA MÉDIA DO ALUNO: %.2f\n",vars[cod].media);
    printf("NOVA SITUAÇÃO: %s \n",vars[cod].situacao);
  }
  
  else{
    printf("ESSE ALUNO NÃO ESTÁ CADASTRADO\n");
    printf("-----------------------------\n");
  }
}
void gerartabela(){
  int i;
  printf(" MENU DOS ALUNOS REGISTRADOS\n");
  printf("=============================\n");
  printf("MAT   NOME       SITUAÇÃO    \n");
  printf("=============================\n");

  for( i= 0; i < qtd; i++ ){
    printf("[%2d]   %-14s %s\n", i, vars[i].nome, vars[i].situacao);
    
  }
  printf("=============================\n");
    
}
void detalhealuno() {
    int op;
    printf("-----------------------------\n");
    printf("----DETALHAMENTO DO ALUNO----\n");
    printf("-----------------------------\n");
    printf("DIGITE O CODIGO DO ALUNO: ");
    scanf("%d", &op);

    if (op >= 0 && op < qtd) { // Verifica se o código do aluno é válido
        printf("NOME: %s\n", vars[op].nome);
        printf("NOTAS: %.2f, %.2f, %.2f\n", vars[op].nota1, vars[op].nota2, vars[op].nota3);
        printf("MÉDIA: %.2f\n", vars[op].media);
        printf("RECUPERAÇÃO: %.2f\n", vars[op].rec);
    } else {
        printf("ALUNO NÃO ENCONTRADO\n");
    }
}
void menuinicial(){
  printf("--------------------------------------------------\n");
  printf("               SISTEMA DE CADASTRO                \n");
  printf("--------------------------------------------------\n");
  
  
  printf("----------------MENU------------\n");
  printf("| [1] - CADASTRAMENTO DE LOGIN |\n");
  printf("| [2] - LOGIN                  |\n");
  printf("| [3] - SAIR                   |\n");
  printf("--------------------------------\n");
}
void menuinterno(){
  printf("----------------MENU---------------------\n");
  printf("| [1] CADASTRAR A ALUNO                 |\n");
  printf("| [2] REGISTRAR A NOTA RECUPERAÇÃO      |\n");
  printf("| [3] VER ALUNOS CADASTRADOS            |\n");
  printf("| [4] PESQUISAR ALUNO POR NOME          |\n");
  printf("| [5] VER DETALHAMENTO DO ALUNO         |\n");
  printf("| [6] ALTERAR INFORMAÇÃO DO ALUNO       |\n");
  printf("| [7] CANCELAR MATRICULA DO ALUNO       |\n");
  printf("| [8] REGISTRO DE NÚMERO NO SORTEIO     |\n");
  printf("| [9] SORTEIAR OS NÚMEROS               |\n"); 
  printf("| [10] INFORMAÇÃO DA UNIVERSIDADE       |\n");  
  printf("| [11] PARA SAIR                        |\n");
  printf("-----------------------------------------\n");
  
}
void informcaodauniversidae(){
  printf("-------------THESCOLA TECNICA - TECNOLOGIA DA INFORMAÇÃO-----------------\n"
  "O curso de Tecnologia da Informação da THESCOLA TECNICA é projetado para\n"
  "preparar os alunos para uma carreira bem-sucedida na área de TI.\n"
  "Os alunos estudarão diversas disciplinas, incluindo programação, banco\n"
  "de dados, redes, segurança da informação, inteligência artificial,\n" 
  "entre outras. O curso tem como objetivo fornecer aos alunos uma base\n"
  "sólida de conhecimentos teóricos e práticos, além de promover o\n"
  "desenvolvimento de habilidades técnicas e analíticas.\n"
  "------------------------------------------------------------------------\n"
  "Para mais informações sobre o curso e a instituição, acesse nosso site:\n"
  "www.thescola-tecnica.edu.br\n"
  "------------------------------------------------------------------------\n");
}
void pesquisaraluno(){
  char nome[80];
  int i;
  int encontrado = 0;
  printf("DIGITE O NOME DO ALUNO: ");
  scanf("%s",nome);
// usando a biblioteca de comparação de strimg para encontrar o aluno pelo nome.
  for (i = 0; i < qtd; i++){
    if(strcmp(vars[i].nome, nome) == 0){
      printf("-----------------------------\n");
      printf("----DETALHAMENTO DO ALUNO----\n");
      printf("-----------------------------\n");
      printf("NOME: %s\n",vars[i].nome);
      printf("NOTAS: %.2f, %.2f, %.2f\n", vars[i].nota1,vars[i].nota2,vars[i].nota3);
      printf("MÉDIA: %.2f\n",vars[i].media);
      printf("SITUAÇÃO: %s\n", vars[i].situacao);  
      printf("-----------------------------\n");
      encontrado = 1;
    }
  }
    if(encontrado == 0){
      printf("-----------------------------\n");
      printf("ALUNO NÃO ENCONTRADO. \n");
      printf("-----------------------------\n");
    } 
  
}
void alterarinf(int mat){
  printf("----------------------------\n");
  printf("   DIGITE A NOVA ATUALIZAÇÃO  \n");
  printf("----------------------------\n");
    printf("DIGITE O NOME DO ALUNO: ");
    scanf("%s", vars[mat].nome);
    printf("DIGITE A PRIMEIRA NOTA: ");
    scanf("%f",&vars[mat].nota1);
    printf("DIGITE A SEGUNDA NOTA: ");
    scanf("%f",&vars[mat].nota2);
    printf("DIGITE A TERCEIRA NOTA: ");
    scanf("%f",&vars[mat].nota3);
    vars[mat].media = (vars[mat].nota1 + vars[mat].nota2 + vars[mat].nota3) / 3;

    if(vars[mat].media >= 7){
      strcpy(vars[mat].situacao,"APROVADO");
    }
    else if(vars[mat].media >= 4 && vars[mat].media < 7){
      strcpy(vars[mat].situacao,"RECUPERAÇÃO");
    }
    else{
      strcpy(vars[mat].situacao,"REPROVADO");
    }

}
void matriz(int matriz[][3], char nomes[][3][45]) {
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            printf("DIGITE O VALORES DO SORTEIO [%d][%d]: ", l, c);
            scanf("%d", &matriz[l][c]);
            printf("DIGITE O NOME DA PESSOA DONA DO NÚMERO: ");
            scanf("%s", nomes[l][c]);
        }
    }
    system("clear");

    printf("OS NÚMEROS REGISTRADOS NA MATRIZ\n");

    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            printf("%d\t", matriz[l][c]);
        }
        printf("\n");
    }
}

void sorteio(int matriz[][3], char nomes[][3][45]) {
    srand(time(NULL));
    int linhaSorteada = rand() % 3;
    int colunaSorteada = rand() % 3;

    int numeroSorteado = matriz[linhaSorteada][colunaSorteada];
    char nomeSorteado[45];
    strcpy(nomeSorteado, nomes[linhaSorteada][colunaSorteada]);
    printf("---------------SORTEIO----------------\n");
    printf("NÚMERO SORTEADO: %d\n", numeroSorteado);
    printf("NOME DA PESSOA: %s\n", nomeSorteado); 
    printf("--------------------------------------\n");
}

// esse excluir foi ensinado dentro de sala de aula, ele vai procurar por cada posição a pessoa que deseja excluir 
int psq(int mat) {
    int i;
    for (i = 0; i < qtd; i++) {
        if (i == mat) {
            return i;
        }
    }
    return -1;
}
void excluir(int mat) {
    int i;
    int pos = psq(mat);

    if (pos == -1) {
        printf("IMPOSSÍVEL EXCLUIR: ALUNO NÃO ENCONTRADO\n");
    } else {
        printf("MATRÍCULA CANCELADA COM SUCESSO.\n");

        for (i = pos; i < qtd - 1; i++) {
            vars[i] = vars[i + 1];
        }
        qtd--;
    }
}



//INICIO DO PROGRAMA;
int main() {
    char op[4];
    int escolha, mat,escolha1;
    char nomeusuario[45] ="";
    int matrizNumeros[3][3];
    char nomes[3][3][45];
    do {
      
        menuinicial();
        printf("DIGITE O CODIGO DA OPÇÃO: ");
        scanf("%d", &escolha1);

        switch (escolha1) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
              system("clear");
              us = login();
                if (us != -1) {
                    system("clear");

                    do {
                        strcpy(nomeusuario, usuario[us].login);  
                        printf("------------------------------------------------------\n");
                        printf("BEM VINDO THESCOLA TECNICA , SR(A) %s !\n", nomeusuario);
                        printf("------------------------------------------------------\n");
                        menuinterno();
                        printf("DIGITE O CODIGO: ");
                        scanf("%d", &escolha);

                        switch (escolha) {
                            case 1:
                                do {
                                    cadastrar();
                                    printf("DESEJA CONTINUAR? (SIM OU NÃO): ");
                                    scanf("%s", op);
                                } while (strcmp(op, "SIM") == 0);
                                system("clear");
                                break;
                            case 2:
                                do {
                                    gerartabela();
                                    recuperacao();
                                    printf("DESEJA CONTINUAR? (SIM OU NÃO): ");
                                    scanf("%s", op);
                                } while (strcmp(op, "SIM") == 0);
                                system("clear");
                                break;
                            case 3:
                                do {
                                    gerartabela();
                                    printf("PARA SAIR (DIGITE 'S'): ");
                                    scanf("%s", op);
                                } while (strcmp(op, "S") != 0);
                                system("clear");
                                break;

                            case 4:
                                do {
                                    pesquisaraluno();
                                    printf("DESEJA CONTINUAR? (SIM OU NÃO): ");
                                    scanf("%s", op);
                                } while (strcmp(op, "SIM") == 0);
                                system("clear");
                                break;

                            case 5:
                                gerartabela();
                                do {
                                    detalhealuno();
                                    printf("DESEJA CONTINUAR? (SIM OU NÃO): ");
                                    scanf("%s", op);
                                } while (strcmp(op, "SIM") == 0);
                                system("clear");
                                break;

                            case 6:
                              do{
                                  gerartabela();
                                  printf("DIGITE A MATRICULA DO ALUNO: ");
                                  scanf("%d",&mat);
                                  alterarinf(mat);
                                  printf("DESEJA CONTINUAR? (SIM OU NÃO): ");
                                  scanf("%s", op);
                              }while (strcmp(op, "SIM") == 0);
                                system("clear");
                                break;
                            case 7:
                                gerartabela();
                                do {
                                    printf("INFORME A MATRICULA DO ALUNO A SER EXCLUÍDO: ");
                                    scanf("%d", &mat);
                                    excluir(mat);
                                    printf("DESEJA CONTINUAR? (SIM OU NÃO): ");
                                    scanf("%s", op);
                                } while (strcmp(op, "SIM") == 0);
                                system("clear");
                                break;
                            case 8:
                              do{
                                  matriz(matrizNumeros, nomes);
                                  printf("DESEJA PARA SAIR ('S'): ");
                                  scanf("%s", op);
                              } while(strcmp(op, "S") == 0);
                                system("clear");
                                break;
                            case 9:
                              do{
                                sorteio(matrizNumeros, nomes);
                                printf("DESEJA PARA SAIR ('S'): ");
                                  scanf("%s", op);
                              } while(strcmp(op, "S") == 0);
                                system("clear");
                                break;

                            case 10:
                                do{
                                  informcaodauniversidae();
                                  printf("PARA SAIR (DIGITE 'S'): ");
                                  scanf("%s", op);
                                } while (strcmp(op, "SIM") == 0);
                                system("clear");
                                break;
                            case 11:
                                printf("-----------------------------\n");
                                printf("VOLTE SEMPRE, ATÉ MAIS !!! \n");
                                printf("-----------------------------\n");
                                break;
                            default:
                                printf("OPÇÃO INVÁLIDA. TENTE NOVAMENTE.\n");
                                break;
                        }
                    } while (escolha != 11);
                } 
                else {
                    printf("Você precisa fazer login primeiro.\n");
                }
                break;
            case 3:
                printf("--------------------------------------------------\n");
                printf("                 VOLTE SEMPRE!!                   \n");
                printf("--------------------------------------------------\n");
                break;
            default:
                printf("OPÇÃO INVÁLIDA. TENTE NOVAMENTE.\n");
                break;
        }
    } while (escolha1 != 3);
    return 0;
}