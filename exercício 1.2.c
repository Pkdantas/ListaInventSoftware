#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int VerificarExpressao(char *expressao);

int main()
{
  char expressao[20];
  printf("\nInsira a expressao: ");
  fflush(stdin);
  fgets(expressao,20,stdin);
  if (VerificarExpressao(expressao)==0) printf("\n\nA expressao esta correta!\n\n");
  else printf("\n\nERRO: A expressao esta incorreta!\n\n");
  return 0;
}

int VerificarExpressao(char *expressao)
{
  int i;
  int chaves=0;
  int colchetes=0;
  int parenteses=0;
  for(i=0;i<=strlen(expressao);i++)
  {
    if(expressao[i]==')')
    {
      if(parenteses==0) return 1;
      parenteses--;
    }
    else if(expressao[i]==']')
    {
      if(colchetes==0) return 1;
      colchetes--;
    }
    else if(expressao[i]=='}')
    {
      if(chaves==0) return 1;
      chaves--;
    }
    else if(expressao[i]=='(') parenteses++;
    else if(expressao[i]=='[') colchetes++;
    else if(expressao[i]=='{') chaves++;
  }
  return (chaves+colchetes+parenteses);
}
