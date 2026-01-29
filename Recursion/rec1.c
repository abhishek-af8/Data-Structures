#include<stdio.h>

void fun(int num){
    if(num<=0){             //base case, very important in recursion
        return;
    }
    printf("%d \n",num);
    printf("Enter a number : ");
    scanf("%d", &num);
    fun(num);
}

int main(){
    fun(5);                //recursive call
return 0;
}