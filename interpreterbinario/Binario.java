package interpreterbinario;

public class Binario extends InterpreterBinario
{
   @Override
   public String um()
   {
      return "1";
   }
   
   @Override
   public String zero()
   {
      return "0";
   }
   
   @Override
   public int multiplicador(Contexto contexto)
   {      
      return (int) Math.pow(2, contexto.getInput().length()-1); //LOGICA PRINCIPAL DE CONVERSAO ENTRE BINARIO E DECIMAL
   }
}
