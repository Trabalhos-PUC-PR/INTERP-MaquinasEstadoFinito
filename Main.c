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
        
        printf("#%u: %s | %s", i, (passesCheck==1)?"OK":"FL", readString);
    }

    fclose(inputFile);
    printf("\n");
    return 0;
}

bool isVerified(char* readString){
    int length = strlen(readString);

    for(int i = 0; i < length; i++){
        if(readString[i] != 'a' && readString[i] != 'b' && readString[i] != '\n'){
            // printf("found a strange, unknown character! (%c)", readString[i]);
            return false;
        }

        if(readString[i] == 'a' && (readString[i+1] != 'b' || readString[i+2] != 'b')){
            // printf("%c found, but is followed by '%c%c', and not 'bb'",readString[i],readString[i+1],readString[i+2]);
            return false;
        }
    }

    return true;
}