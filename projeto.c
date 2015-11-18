/*A Tarefa 2 consiste em procurar para cada arquivo indicado no argumento uma
assinatura padrão, identificando o tipo do arquivo. Essas assinaturas tipicamente
ocorrem nos primeiros bytes de um arquivo, e indicam o formato binário real do
arquivo. Pede-se que sejam identificados pelo menos os seguintes padrões:
PNG, ZIP, PDF, WAV, AVI, EXE e ELF. Caso contrário, indique que o arquivo
não foi identificado.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Programa para verificacao de tipo de arquivo.\n");
        printf("Uso: projeto nomeArquivo\n");
        return 0;
    }

    int i;
    for (i = 1; i < argc; i++) 
    {
        printf("[%d] %s\n", i, argv[i]);
        
        FILE *f = NULL;
        f = fopen(argv[i], "r");
        if (f == NULL) 
        {
            printf("Erro ao abrir o arquivo '%s'\n", argv[i]);
            return 1;
        }
        
        int c, count = 0;
        c = fgetc(f);
        while (c != EOF)
        {
           count++;
           c = fgetc(f);
           printf("%d\n", c);
        }
        //printf("count=%d\n", count);
        
        fclose(f); f = NULL;
    }

    return 0;
}