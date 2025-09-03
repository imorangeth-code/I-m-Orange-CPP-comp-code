#include <stdio.h>
#include <stdlib.h>

char *chr;

const char *select_manu()
{
    chr = new char[100]; // allocate 100 bytes
    if (chr == NULL) {
        perror("malloc failed");
        exit(1);
    }

    printf("Enter character for menu :: ");
    scanf("%99s", chr); // safe with limit
    return chr;
}

int main() {
    const char *result = select_manu();
    printf("%s\n", result);
    free(chr); // release memory
    return 0;
}
