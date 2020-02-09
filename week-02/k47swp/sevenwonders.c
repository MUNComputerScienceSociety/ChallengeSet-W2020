#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    scanf("%[^\n]s", str);
    int i=0, c=0, t=0, g=0, m=0;
    while(str[i] != '\0') {
        char s = str[i] & ~32;
        if(s=='C') c++;
        if(s=='T') t++;
        if(s=='G') g++;
        i++;
    }
    m = 7 * (c<t ? (c<g ? c:g) : (t<g ? t:g));
    printf("%d\n",c*c+t*t+g*g+m);
    return 0;
}