/*
	Bora praticar :)
	Jogo da velha em C
*/

#include <stdio.h>
#define JUCA 3

int coe; 
int menu(void);
void clear(void);
void ZeraOTabuleiro(int tabuleiro[][JUCA]);
void MostraOTabuleiro(int tabuleiro[][JUCA]);
void jogar(int tabuleiro[][JUCA]);
int qualLocal(int tabuleiro[][JUCA], int linha, int coluna);
int qualLinha(int tabuleiro[][JUCA]);
int qualColuna(int tabuleiro[][JUCA]);
int qualDiagonal(int tabuleiro[][JUCA]);
int deuEmpate(int tabuleiro[][JUCA]);
int fim(int tabuleiro[][JUCA], int coe);
void jogada(int tabuleiro[][JUCA]);
 
int main(void)
{
    int tabuleiro[JUCA][JUCA],
        continuar;
 
    do
    {
        coe=1;
        continuar = menu();
        if(continuar == 1)
            jogar(tabuleiro);
 
    }while(continuar);
 
    return 0;
}
 
int menu(void)
{
    int opcao;
 
        printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+\n");
    	printf("|                    .::      BORA PRATICAR     ::.                     |\n");
    	printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+\n");
    	printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+\n");
    	printf("|                    .::   JOGO DA VELHA EM C   ::.                     |\n");
    	printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+\n");
    	printf("|-----|--------|--------|-----|--------|--------|-----|--------|--------|\n");
    	printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+\n");
    	printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+\n");
    	printf("|  1  |      JOGAR      |           OPCAO       |  0  |      SAIR       |\n");
    	printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+\n");
    
    	printf("\n");
    	printf("\tESCOLHA UMA OPCAO: ");
 
        scanf("%d", &opcao);
 
        switch(opcao)
        {
           case 1:
           case 0:
                break;
           default:
                clear();
                printf("Opcao invalida. Tente de novo!\n");
        }
 
    return opcao;
}
 
void clear(void)
{
    int count=0;
 
    while(count != 100)
    {
        putchar('\n');
        count++;
    }
}
 
void ZeraOTabuleiro(int tabuleiro[][JUCA])
{
    int linha, coluna;
    for(linha = 0 ; linha < JUCA ; linha++)
        for(coluna = 0 ; coluna < JUCA ; coluna++)
            tabuleiro[linha][coluna] = 0;
}
 
void MostraOTabuleiro(int tabuleiro[][JUCA])
{
    int linha, coluna;
    putchar('\n');
 
    for(linha = 0 ; linha < JUCA ; linha++)
    {
        for(coluna = 0 ; coluna < JUCA ; coluna++)
        {
            if(tabuleiro[linha][coluna] == 0)
                printf("    ");
            else
                if(tabuleiro[linha][coluna] == 1)
                    printf("  X ");
                else
                    printf("  O ");
 
            if(coluna != (JUCA-1))
                printf("|");
        }
        putchar('\n');
    }
    putchar('\n');
}
 
void jogar(int tabuleiro[][JUCA])
{
    int continua;
    ZeraOTabuleiro(tabuleiro);
 
    do
    {
        clear();
        MostraOTabuleiro(tabuleiro);
        jogada(tabuleiro);
 
    }while(fim(tabuleiro, coe) != 1);
}
 
 
int qualLocal(int tabuleiro[][JUCA], int linha, int coluna)
{
    if(linha < 0 || linha > (JUCA-1) || coluna < 0 || coluna > (JUCA-1) || tabuleiro[linha][coluna] != 0)
        return 0;
    else
        return 1;
}
 
int qualLinha(int tabuleiro[][JUCA])
{
    int linha, coluna,
        soma;
 
    for(linha = 0 ; linha < JUCA ; linha++)
    {
        soma=0;
 
        for(coluna = 0 ; coluna < JUCA ; coluna++)
            soma += tabuleiro[linha][coluna];
 
        if(soma==JUCA || soma == (-1)*JUCA)
            return 1;
    }
 
    return 0;
}
 
int qualColuna(int tabuleiro[][JUCA])
{
    int linha, coluna,
        soma;
 
 
    for(coluna = 0 ; coluna < JUCA ; coluna++)
    {
        soma=0;
 
        for(linha = 0 ; linha < JUCA ; linha++)
            soma += tabuleiro[linha][coluna];
 
        if(soma==JUCA || soma == (-1)*JUCA)
            return 1;
    }
 
    return 0;
}
 
int qualDiagonal(int tabuleiro[][JUCA])
{
    int linha,
        diagonal_principal=0,
        diagonal_secundaria=0;
 
    for(linha = 0 ; linha < JUCA ; linha++)
    {
        diagonal_principal += tabuleiro[linha][linha];
        diagonal_secundaria += tabuleiro[linha][JUCA-linha-1];
    }
 
    if(diagonal_principal==JUCA || diagonal_principal==(-1)*JUCA ||
       diagonal_secundaria==JUCA || diagonal_secundaria==(-1)*JUCA)
       return 1;
 
    return 0;
}
 
int deuEmpate(int tabuleiro[][JUCA])
{
    int linha, coluna;
 
    for(linha = 0 ; linha < JUCA ; linha++)
        for(coluna = 0 ; coluna < JUCA ; coluna++)
            if(tabuleiro[linha][coluna] == 0)
                return 0;
 
    return 1;
}
 
int fim(int tabuleiro[][JUCA], int coe)
{
    if(qualLinha(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (coe%2)+1);
        MostraOTabuleiro(tabuleiro);
        return 1;
    }
 
    if(qualColuna(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (coe%2)+1);
        MostraOTabuleiro(tabuleiro);
        return 1;
    }
 
    if(qualDiagonal(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (coe%2)+1);
        MostraOTabuleiro(tabuleiro);
        return 1;
    }
 
    if(deuEmpate(tabuleiro))
    {
        printf("Jogo encerrado. Ocorreu um empate! !\n\n");
        MostraOTabuleiro(tabuleiro);
        return 1;
    }
 
    return 0;
}
 
void jogada(int tabuleiro[][JUCA])
{
    int linha, coluna;
    coe++;
    printf("\n--> Jogador %d \n", (coe % 2) + 1);
 
    do
    {
        printf("Linha: ");
        scanf("%d", &linha);
        linha--;
 
        printf("Coluna: ");
        scanf("%d", &coluna);
        coluna--;
 
        if(qualLocal(tabuleiro, linha, coluna) == 0)
            printf("Posicao ocupada ou inexistente, escolha outra.\n");
 
    } while(qualLocal(tabuleiro, linha, coluna) == 0);
 
    if(coe%2)
        tabuleiro[linha][coluna] = -1;
    else
        tabuleiro[linha][coluna] = 1;
}

