// André Luiz Kovalski
#include <stdio.h>
#include <string.h>

#define stringMaxSize 256

typedef enum
{
  false = 0,
  true = 1
} bool;

typedef enum
{
  S0 = 0,
  S1 = 1,
  S2 = 2,
  S_1 = -1
} machineState;

int selectFile();
bool passStateMachine(char *string);

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

int main()
{

  FILE *inputFile;
  int totalLines;
  char readString[stringMaxSize];
  bool passesCheck = false;

  char file[50];

  printf("a) input1.txt\n");
  printf("b) input2.txt\n");
  printf("c) input3.txt\n");
  printf("d) custom.txt (Teacher's file)\n");

  int selection = selectFile();

  if (selection == -1)
  {
    printf("Invalid selection!\n");
    return -1;
  }

  if (selection == 4)
  {
    strcpy(file, "custom.txt");
  }
  else
  {
    char strSelect[10];
    strcpy(file, "input");
    sprintf(strSelect, "%d", selection);
    strcat(file, strSelect);
    strcat(file, ".txt");
  }

  inputFile = fopen(file, "r");

  if (inputFile == NULL)
  {
    printf("No file names \"%s\" found!", file);
    return -1;
  }

  fgets(readString, stringMaxSize, inputFile);
  sscanf(readString, "%d", &totalLines);

  for (int i = 0; i < totalLines; i++)
  {
    passesCheck = false;
    fgets(readString, stringMaxSize, inputFile);

    if (passStateMachine(readString) == true)
    {
      passesCheck = true;
    }

    if (passesCheck == false)
    {
      int length = strlen(readString);
      if (i + 1 != totalLines)
      {
        readString[length - 1] = 0;
      }
      printf("%s: não pertence.\n", readString);
    }
    else
    {
      int length = strlen(readString);
      if (i + 1 != totalLines)
      {
        readString[length - 1] = 0;
      }
      printf("%s: pertence.\n", readString);
    }
  }

  fclose(inputFile);
  printf("\n");
  return 0;
}

int selectFile()
{
  char option;
  scanf("%c", &option);
  int selection = option - 96;

  if (selection > 4 || selection < 1)
  {
    return -1;
  }
  return selection;
}

bool passStateMachine(char *string)
{
  machineState state = S_1;
  int stringSize = strlen(string);
  for (int i = 0; i < stringSize; i++)
  {
    switch (string[i])
    {
    case ('a'):
      if (state != S_1 && state != S0)
      {
        return false;
      }
      state = S2;
      break;

    case ('b'):
      if (state != S0 && state != S_1)
      {
        state--;
      }
      else
      {
        state = S0;
      }
      break;

    case 99:
    case 10:
      break;

    default:
      return false;
      break;
    }
  }

  if (state == 0)
  {
    return true;
  }
  return false;
}