#include <stdio.h>

int main(void)
{
    FILE *file = NULL;
    file = fopen("bla.txt", "r");
    if (file == NULL) {
        printf("erro ao abrir arquivo!\n");
        return 1;
    }

    int c, count = 0;
    c = fgetc(file);
    while (c != EOF) {
       count++;
       c = fgetc(file);
    }
    printf("count=%d\n", count);

    fclose(file);

    return 0;
}