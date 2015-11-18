#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
  int a;	
  if(argc==1){
    printf("Este programa tem o objetivo de listar o formato de um ou mais arquivos\n");
    printf("Uso: tarefa <arquivo.formato>\n");
  }
  else{

    for(a=1;a<argc;a++){

      // abrir o arquivo para leitura no modo binário

      FILE *arquivo = fopen(argv[a], "r");

      if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
      } 

      int n,tam; 
      tam = 500;
      unsigned char *p_c = NULL;
      p_c = malloc(tam * sizeof(char));
      n = fread(p_c, sizeof(char), tam, arquivo);
      n=n;

      if(p_c[0]==0x25 && p_c[1]==0x50 && p_c[2]==0x44 && p_c[3]==0x46){
        printf("Arquivo: %s é do tipo PDF\n",argv[a]);
      }
      else{
        if(p_c[0]==0x89 && p_c[1]==0x50 && p_c[2]==0x4E && p_c[3]==0x47 && p_c[4]==0x0D && p_c[5]==0x0A && p_c[6]==0x1A && p_c[7]==0x0A){
          printf("Arquivo: %s é do tipo PNG\n",argv[a]);			
        }
        else{
          if(p_c[0]==0x50 && p_c[1]==0x4B && p_c[2]==0x03 && p_c[3]==0x04){
            printf("Arquivo: %s é do tipo ZIP\n",argv[a]);
          }
          else{
            if(p_c[0]==0x50 && p_c[1]==0x4B && p_c[2]==0x05 && p_c[3]==0x06){
              printf("Arquivo: %s é do tipo ZIP\n",argv[a]);
            }
            else{
              if(p_c[0]==0x50 && p_c[1]==0x4B && p_c[2]==0x07 && p_c[3]==0x08){
                printf("Arquivo: %s é do tipo ZIP\n",argv[a]);
              }
              else{
                if(p_c[0]==0x52 && p_c[1]==0x49 && p_c[2]==0x46 && p_c[3]==0x46 && p_c[8]==0x57 && p_c[9]==0x41 && p_c[10]==0x56 && p_c[11]==0x45){
                  printf("Arquivo: %s é do tipo WAV\n",argv[a]);
                }
                else{
                  if(p_c[0]==0x52 && p_c[1]==0x49 && p_c[2]==0x46 && p_c[3]==0x46 && p_c[8]==0x41 && p_c	[9]==0x56 && p_c[10]==0x49 && p_c[11]==0x20){
                    printf("Arquivo: %s é do tipo AVI\n",argv[a]);
                  }
                  else{
                    if(p_c[0]==0x4D && p_c[1]==0x5A){
                      printf("Arquivo: %s é do tipo EXE\n",argv[a]);
                    }
                    else{	
                      if(p_c[0]==0x7F && p_c[1]==0x45 && p_c[2]==0x4C && p_c[3]==0x46){
                        printf("Arquivo: %s é do tipo ELF\n",argv[a]);
                      }
                      else{
                        printf("Arquivo: %s não foi reconhecido\n",argv[a]);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      fclose(arquivo);
      free(p_c);
    }
  }

  return 0;
}

