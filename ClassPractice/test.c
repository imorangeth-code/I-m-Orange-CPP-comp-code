#include <stdio.h>
#include <stdlib.h>

char *chr;

const char *select_manu()
{
    chr = malloc(100); 

    printf("Enter character for menu :: ");
    scanf("%99s", chr); 
    return chr;
}

int main() {
    const char *result = select_manu();
    printf("%s\n", result);
    free(chr); 
    return 0;
}
