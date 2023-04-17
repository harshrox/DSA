#include<stdio.h>

void toh(int n,char s,char h,char d){
   
    if(n==1){
        printf("Move 1 disk from %c to %c\n",s,d);
    }
    else{
        toh(n-1,s,d,h);
        printf("Move 1 disk from %c to %c\n",s,d);
        toh(n-1,h,s,d);
    }
    
}
int main(){
    int num;
    printf("Enter a number-");
    scanf("%d",&num);
    char source='A',helper='B',destination='C';
    toh(num,source,helper,destination);
    return 0;
}