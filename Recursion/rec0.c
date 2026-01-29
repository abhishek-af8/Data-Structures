#include<stdio.h>

void fun(){
    static int count;
    count++;
    printf("%d\n", count);
    fun();
}

int main(){
    fun();
return 0;
}

//this is an infinite recursion, there is no base case which stops the function from calling itself ever, ultimately running out of stack causing stack overflow and which in turn causing segmenatation fault.