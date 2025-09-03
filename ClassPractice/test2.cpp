#include <bits/stdc++.h>

using namespace std;

int main()
{
    printf("*** Enter integer Number 1-100 ***\n");
    int a = 1;
    srand(time(0));
    int b = 0+rand() % (100-0+1) ;
    while(true)
    {
        if(a > 7)
        {
            printf("YOu lose !!!!!\n");
            break;
        }
        int guess;
        printf("Guesstimate #%d >> ",a);
        scanf("%d",&guess);
        a++;
        if(guess == b){
            printf("Congratulation! \n");
            break;
        }else if(guess > b) printf("The number is less than %d\n",guess);
        else printf("The number is greater than %d\n",guess);
        printf("Try again bruh \n");

    }    
}