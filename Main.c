#include <stdio.h>

#define stringSize 256

typedef enum 
{ 
    false = 0, 
    true = 1
} bool;

bool isVerified(char *readString);

int main(){

    FILE* inputFile;
    int totalLines;
    char readString[stringSize];
    bool passesCheck = false;

    inputFile = fopen("input.txt", "r");

    
    if(inputFile == NULL){
        printf("No file names \"input.txt\" found!");
        fclose(inputFile);
        return -1;
    }

    fgets(readString, stringSize, inputFile);
    sscanf(readString, "%d", &totalLines);
    printf("lines: %i\n", totalLines);

    for(int i = 0; i < totalLines; i++){
        passesCheck = false;
        fgets(readString, stringSize, inputFile);
        
        if(isVerified(readString) == true){
            passesCheck = true;
        }
        
        printf("#%u: %s | %s", i, (passesCheck==1)?"OK":"FAIL", readString);
    }

    fclose(inputFile);
    return 0;
}

bool isVerified(char* readString){
    int length = strlen(readString);
    int doLoop = true;

    for(int i = 0; i < length; i++){
        
    }

    printf("end");
    return true;
}