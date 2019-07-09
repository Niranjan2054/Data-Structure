#include <stdio.h>
#include <stdlib.h>
void tow(int a,char s,char d, char t){
    if(a==0){
        return 0;
    }else{
        tow(a-1,s,t,d);
        printf("MOve %d from %c to %c\n",a,s,d);
        tow(a-1,t,d,s);
    }

}
int main()
{
    int a;


    printf("Enter a number: ");
    scanf("%d",&a);
    tow(a,'S','D','T');
    return 0;
}
