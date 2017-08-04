package interpreterbinario;

import java.util.ArrayList;

public class Teste {
   
   public static void main(String[] args) 
   {
      ArrayList<InterpreterBinario> interpretadores = new ArrayList<InterpreterBinario>();
              
      String binario = "101101";
      
      for (int i=0; i<binario.length(); i++)
      {
         interpretadores.add(new Binario()); //ADICIONAR UMA INSTANCIA DA CLASSE BINARIO PRA CADA NUMARO DA STRING INPUT
      }
      
      Contexto contexto = new Contexto(binario);
      
      for (InterpreterBinario bin : interpretadores)
      {
         bin.interpretar(contexto); //INTERPRETAR ENQUANTO HOUVER INTERPRETADORES
      }
      
      System.out.println(binario + " = " + Integer.toString(contexto.getOutput()));
   }
     
}
