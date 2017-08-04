package interpreterbinario;

public abstract class InterpreterBinario 
{
   public void interpretar(Contexto contexto)
   {
      if(contexto.getInput().length() == 0) return;
      
      if(contexto.getInput().startsWith(zero()))
      {
         MenosUmaCasaInput(contexto);
      }
      
      if(contexto.getInput().startsWith(um()))
      {
         SomarValorOutput(contexto,1);
         MenosUmaCasaInput(contexto);
      }
   }
      
   private void MenosUmaCasaInput(Contexto contexto) 
   {
      contexto.setInput(contexto.getInput().substring(1)); //EXCLUI OS ZEROS
   }
      
   private void SomarValorOutput(Contexto contexto, int numero) //SOMA VALOR DO BINARIO SELECIONADO AO INT OUTPUT
   {
      contexto.setOutput(contexto.getOutput() + (numero * multiplicador(contexto)));
   }
      
   public abstract String um();

   public abstract String zero();

   public abstract int multiplicador(Contexto contexto);
   
}
