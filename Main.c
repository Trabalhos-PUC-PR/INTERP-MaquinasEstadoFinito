#include <stdio.h>

int main(){

    FILE* input;

    input = fopen("input.txt", "r");

    if(input == NULL){
        printf("No file names \"input.txt\" found!");
        return 1;
    }

    printf("file exists!");
    return 0;
}