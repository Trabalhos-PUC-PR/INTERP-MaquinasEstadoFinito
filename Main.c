// André Luiz Kovalski
#include <stdio.h>
#include <string.h>

#define stringSize 256

typedef enum { false = 0, true = 1 } bool;
int selectFile();
bool isVerified(char *readString);

/*
    Para obter os pontos relativos a este trabalho, você deverá criar um programa, utilizando a
linguagem Python, C, ou C++. Este programa, quando executado, irá determinar se uma string de
entrada faz parte da linguagem 𝐿 definida por 𝐿 = {𝑥 | 𝑥 ∈ {𝑎, 𝑏}∗ 𝑒 𝑐𝑎𝑑𝑎 𝑎 𝑒𝑚 𝑥 é 𝑠𝑒𝑔𝑢𝑖𝑑𝑜 𝑝𝑜𝑟 𝑝𝑒𝑙𝑜 𝑚𝑒𝑛𝑜𝑠 𝑑𝑜𝑖𝑠 𝑏}
segundo o alfabeto Σ = {𝑎, 𝑏, 𝑐}.
    O programa que você desenvolverá irá receber como entrada um arquivo de texto (.txt)
contendo várias strings. A primeira linha do arquivo indica quantas strings estão no arquivo de texto de
entrada. As linhas subsequentes contém uma string por linha. A seguir está um exemplo das linhas que
podem existir em um arquivo de testes para o programa que você irá desenvolver:
  
    3
    abbaba
    abababb
    bbabbaaab

    Neste exemplo temos 3 strings de entrada. O número de strings em cada arquivo será
representado por um número inteiro positivo. A resposta do seu programa deverá conter uma, e
somente uma linha de saída para cada string. Estas linhas conterão a string de entrada e o resultado
da validação conforme o formato indicado a seguir:
    
    abbaba: não pertence.

    A saída poderá ser enviada para um arquivo de textos, ou para o terminal padrão e será
composta de uma linha de saída por string de entrada. No caso do exemplo, teremos 3 linhas de saída.
Para que seu programa possa ser testado você deve criar, no mínimo, três arquivos de entrada
contendo um número diferente de strings diferentes. Os arquivos de entrada criados para os seus testes
devem estar disponíveis tanto no ambiente repl.it quanto no ambiente Github. Observe que o professor
irá testar seu programa com os arquivos de testes que você criar e com, no mínimo um arquivo de
testes criado pelo próprio professor.
*/

int main() {

  FILE *inputFile;
  int totalLines;
  char readString[stringSize];
  bool passesCheck = false;

  char file[50];

  printf("a) input1.txt\n");
  printf("b) input2.txt\n");
  printf("c) input3.txt\n");
  printf("d) custom.txt (Teacher's file)\n");

  int selection = selectFile();

  if (selection == -1) {
    printf("Invalid selection!\n");
    return -1;
  }

  if (selection == 4) {
    strcpy(file, "custom.txt");
  } else {
    char strSelect[10];
    strcpy(file, "input");
    sprintf(strSelect, "%d", selection);
    strcat(file, strSelect);
    strcat(file, ".txt");
  }

  inputFile = fopen(file, "r");

  if (inputFile == NULL) {
    printf("No file names \"%s\" found!", file);
    // fclose(inputFile);
    return -1;
  }

  fgets(readString, stringSize, inputFile);
  sscanf(readString, "%d", &totalLines);
//   printf("lines: %i\n", totalLines);

  for (int i = 0; i < totalLines; i++) {
    passesCheck = false;
    fgets(readString, stringSize, inputFile);

    if (isVerified(readString) == true) {
      passesCheck = true;
    }

    if (passesCheck == false) {
      int length = strlen(readString);
      readString[length - 1] = 0;
      printf("%s: não pertence.\n", readString);
    }
    // sprintf("#%s: %s | %s", i, (passesCheck==1)?"OK":"FL", readString);
  }

  fclose(inputFile);
  printf("\n");
  return 0;
}

bool isVerified(char *readString) {
  int length = strlen(readString);

  for (int i = 0; i < length; i++) {
    if (readString[i] != 'a' && readString[i] != 'b' && readString[i] != '\n') {
      // printf("found a strange, unknown character! (%c)", readString[i]);
      return false;
    }

    if (readString[i] == 'a' &&
        (readString[i + 1] != 'b' || readString[i + 2] != 'b')) {
      // printf("%c found, but is followed by '%c%c', and not
      // 'bb'",readString[i],readString[i+1],readString[i+2]);
      return false;
    }
  }

  return true;
}

int selectFile() {
  char option;
  scanf("%c", &option);
  int selection = option - 96;

  if (selection > 4 || selection < 1) {
    return -1;
  }
  return selection;
}