#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ConverterParaINT(char* expressao, int* valor);
int RetirarSinal(char* expressao);
void RetirarEspacos(char* expressao);

int main()
{
  int valor=0;
  char expressao[11];
  printf("\nInsira o numero de no maximo 9 caracteres: \n");
  fflush(stdin);
  fgets(expressao,11,stdin);
  if(ConverterParaINT(expressao,&valor)==1) printf("\n\nValor inserido: %d\n\n", valor);
  return 0;
}

//TABELA ASC (subtraindo 48 do char): -5=='+',-3=='-',-16==' '

void RetirarEspacos(char* expressao)
{
  int i;
  for(i=0;i<=strlen(expressao);i++)
  {
    if(expressao[i]-48==-16)
    {
      memmove(&expressao[i], &expressao[i + 1], strlen(expressao) - i);//MOVIMENTA TODOS OS ITENS DA STRING A PARTIR DA POSI플O i+1 PARA A POSI플O i: A QUANTIDADE DE ITENS
      if(i!=0)i--;                                                     //TOTAL QUE SERA MOVIMENTADA DEPENDE DO TERCEIRO VALOR: strlen(expressao)-i, OU SEJA, NESSE CASO, A QUANTIDADE DE ITENS
    }                                                                  //SER� A QUANTIDADE DE ITENS NA STRING A PARTIR DA POSI플O i MENOS O ITEM DA POSI플O i
  }
}

int RetirarSinal(char* expressao)
{
  int i=1;
  if(expressao[0]-48==-3||expressao[0]-48==-5)
  {
    if(expressao[0]-48==-3)i=-1;
    memmove(&expressao[0], &expressao[1], strlen(expressao));
  }
  return i;
}

int ConverterParaINT(char* expressao,int* valor)
{
  int i, multiplicador, casas;
  RetirarEspacos(expressao);
  multiplicador=RetirarSinal(expressao);
  casas=strlen(expressao);
  for(i=0;i<=casas-2;i++)
  {
    if(expressao[i]-48<0||expressao[i]-48>9)
    {
      printf("\n\nERRO: A expressao so pode conter numeros, space e sinais. Alem disso, os sinais so podem estar antes do numero.\n");
      printf("\n\n%d",i);
      return 0;
    }
    else *valor = *valor+(expressao[i]-48)*pow(10,casas-2-i);
  }
  *valor = *valor * multiplicador;
  return 1;
}
