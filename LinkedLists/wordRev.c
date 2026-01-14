#include<stdio.h>
#include<string.h>

void revString(char*start, char*end){
    while(start<end){
        char tempStart = *start;
        *start = *end;
        *end = tempStart;
        start++;
        end--;
    }
}

void revWord(char*c){
    int n = strlen(c);
    char*start = c;
    char*end = c+(n-1);
    revString(start, end);
    start = c;
    end = c;

    while(*start!='\0'){
        while(*end!=' ' && *end!='\0'){
            end++;
        }
        char*tempend = end;
        end--;
        revString(start, end);
        if(*tempend=='\0'){
            start = tempend;
        }
        else{
            start = tempend+1;
        }
        end = start;
    }
}

int main(){
    char c[] = "Hi Bi  my";
    revWord(c);
    printf("%s\n", c);
return 0;
}