#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int N = 0;
    scanf("%d", &N);
    while(N-- > 0) {
        scanf("%1000s", str);
        printf("%zu\n", strlen(str));
    }
    return 0;
}