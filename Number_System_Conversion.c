#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX_SIZE 100

int push(int *stk,int *top,int item){
    if(*top>=(MAX_SIZE-1)){
        printf("Overflow");
    }
    else{
        stk[++*top] = item;
    }
}

int pop_binadd(int *stk,int *top, int *dec){
    *dec += stk[*top]*pow(2,*top);
        --*top;
}

int pop_octadd(int *stk,int *top, int *dec){
    *dec += stk[*top]*pow(8,*top);
        --*top;
}

int main(){
    int ch;
    printf("What conversion do you want to do :\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Decimal to Octal\n");
    printf("4. Decimal to Hexadecimal\n");
    printf("5. Octal to Decimal\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    if(ch==1){
        int Stk1[MAX_SIZE],Stk2[MAX_SIZE], top1=-1,top2=-1,dec,bin;
        printf("Enter the decimal number : ");
        scanf("%d",&dec);
        while(dec>0){
            bin = dec%2;
            dec /= 2;
            push(&Stk1,&top1,bin);
        }
        for(int j=top1; j>=0; j--){
            push(&Stk2,&top2,Stk1[j]);
        }
        printf("The binary equivalent of the given decimal number is :\n");
        for(int j=0; j<=top2; j++){
            printf("%d",Stk2[j]);
        }
    }
    else if(ch==2){
        int Stk1[MAX_SIZE],Stk2[MAX_SIZE], top1=-1,top2=-1,dec=0,bin;
        printf("Enter the binary number : ");
        scanf("%d",&bin);
        while(bin!=0){
            push(&Stk1, &top1, bin%10);
            bin /= 10;
        }
        int size=top1;
        for(int i=size; i>=0; i--){
            pop_binadd(&Stk1, &top1, &dec);
        }

        printf("The equivalent decimal number is : %d",dec);
    }
    else if(ch==3){
        int Stk1[MAX_SIZE],Stk2[MAX_SIZE], top1=-1,top2=-1,dec,oct;
        printf("Enter the decimal number : ");
        scanf("%d",&dec);
        while(dec>0){
            oct = dec%8;
            dec /= 8;
            push(&Stk1,&top1,oct);
        }
        for(int j=top1; j>=0; j--){
            push(&Stk2,&top2,Stk1[j]);
        }
        printf("The octal equivalent of the given decimal number is :\n");
        for(int j=0; j<=top2; j++){
            printf("%d",Stk2[j]);
        }
    }
    else if(ch==4){
        int Stk1[MAX_SIZE],Stk2[MAX_SIZE], top1=-1,top2=-1,dec,hex;
        printf("Enter the decimal number : ");
        scanf("%d",&dec);
        while(dec>0){
            hex = dec%16;
            dec /= 16;
            push(&Stk1,&top1,hex);
        }
        for(int j=top1; j>=0; j--){
            push(&Stk2,&top2,Stk1[j]);
        }
        printf("The hexadecimal equivalent of the given decimal number is :\n");
        for(int j=0; j<=top2; j++){
            if(Stk2[j]>9){
                switch (Stk2[j])
                {
                case 10:
                    printf("A");
                    break;
                case 11:
                    printf("B");
                    break;
                case 12:
                    printf("C");
                    break;
                case 13:
                    printf("D");
                    break;
                case 14:
                    printf("E");
                    break;
                case 15:
                    printf("F");
                    break;
                default:
                    break;
                }
            }
            else{
            printf("%d",Stk2[j]);
            }
        }
    }
    else if(ch==5){
        int Stk1[MAX_SIZE],Stk2[MAX_SIZE], top1=-1,top2=-1,dec=0,bin;
        printf("Enter the octal number : ");
        scanf("%d",&bin);
        while(bin!=0){
            push(&Stk1, &top1, bin%10);
            bin /= 10;
        }
        int size=top1;
        for(int i=size; i>=0; i--){
            pop_octadd(&Stk1, &top1, &dec);
        }

        printf("The equivalent decimal number is : %d",dec);
    }
    else{
        printf("Wrong Input entered");
    }
}