#include <stdio.h>
#include <stdlib.h>

void CalcularMenorCaminho(int piramide[4][4]);
void PreencherPiramide(int piramide[4][4]);
void ImprimirPiramide(int piramide[4][4]);

int main()
{
  int piramide[4][4];
  PreencherPiramide(piramide);
  ImprimirPiramide(piramide);
  CalcularMenorCaminho(piramide);
  return 0;
}

void CalcularMenorCaminho(int piramide[4][4])
{
  int linha,coluna,limitador_linha,limitador_coluna,caminho[4];
  limitador_linha=4; //A PIRÂMIDE DADA SÓ TEM 4 LINHAS
  limitador_coluna=0;
  for(linha=0;linha<4;linha++)
  {
    caminho[linha]=piramide[linha][0];
    for(coluna=1;coluna<=limitador_coluna;coluna++)
    {
      if(piramide[linha][coluna]<caminho[linha]) caminho[linha]=piramide[linha][coluna];
    }
    limitador_coluna++;
  }
  printf("\nMenor Caminho: ");
  for(linha=0;linha<4;linha++)
  {
    printf(" %d ",caminho[linha]);
  }
}

void PreencherPiramide(int piramide[4][4])
{
  piramide[0][0]=5;
  piramide[1][0]=3;
  piramide[1][1]=4;
  piramide[2][0]=1;
  piramide[2][1]=9;
  piramide[2][2]=3;
  piramide[3][0]=12;
  piramide[3][1]=33;
  piramide[3][2]=2;
  piramide[3][3]=6;
}

void ImprimirPiramide(int piramide[4][4])
{
  int linha,coluna,limitador_linha,limitador_coluna,caminho[4];
  limitador_linha=4; //A PIRÂMIDE DADA SÓ TEM 4 LINHAS
  limitador_coluna=0;
  for(linha=0;linha<4;linha++)
  {
    printf("\n");
    for(coluna=0;coluna<=limitador_coluna;coluna++)
    {
      printf(" %d ",piramide[linha][coluna]);
    }
    limitador_coluna++;
  }
}
