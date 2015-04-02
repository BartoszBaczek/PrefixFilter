#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Readparameter(int paramSize, char *parameter[]);
char* FindPrefix(int paramSize, char* parameter[]);
char* FindInputFileName(int paramSize, char* parameter[]);
char* FindOutputFileName(int paramSize, char* parameter[]);


void PrintHelpMessage();

int main(int argc, char *argv[])
{

    Readparameter(argc, argv);

    return 0;
}

void Readparameter(int paramSize, char *parameter[])
{


    typedef struct
    {
        char *prefix;
        char *inputFileName;
        char *outputFileName;
    }ProgramParameter;

    char *inputFileName = FindInputFileName(paramSize, parameter);
    char *outputFileName = FindOutputFileName(paramSize, parameter);
    char *prefix = FindPrefix(paramSize, parameter);

    ProgramParameter programParameters = {inputFileName, outputFileName, prefix};

    //strcpy (&programParameters.inputFileName, inputFileName);
    ///strcpy (&programParameters.outputFileName, outputFileName);

   printf("%s\n", programParameters.inputFileName);

   printf("%s\n", programParameters.outputFileName);
   printf("%s\n", programParameters.prefix);
   //printf("%s\n", &programParameters.prefix);




}

char* FindPrefix(int paramSize, char* parameter[])
{
    int i = 0;

    do
    {
        i++;
    }while (strcmp(parameter[i], "-f"));

    char *prefix = malloc(strlen(parameter[i+1]));
    prefix = parameter[i+1];

    return prefix;

}

char* FindInputFileName(int paramSize, char* parameter[])
{
    int i = 0;

    do
    {
        i++;
    }while (strcmp(parameter[i], "-i"));

    char *inputFileName = malloc(strlen(parameter[i+1]));
    inputFileName = parameter[i+1];

    return inputFileName;
}

char* FindOutputFileName(int paramSize, char* parameter[])
{
    int i = 0;

    do
    {
        i++;
    }while (strcmp(parameter[i], "-o"));

    char *outputFileName = malloc(strlen(parameter[i+1]));
    outputFileName = parameter[i+1];

    return outputFileName;
}



void PrintHelpMessage()
{
        printf("\t\t\tPOMOC PROGRAMU FILTR PRZEDROSTKOWY\t\t\n");
        printf("W celu poprawnego uruchomienia programu, musisz zrobic nastepujace rzeczy:\n");
        printf("1) Po przedrostku -o podaj nazwe pliku wyjsciowego (na przyklad -o Output.txt)\n");
        printf("2) Nastpenie po przedrostku -f podaj przedrostek (na przyklad -f pra)\n");
        printf("3) Po przedrostku -i podaj nazwe pliku wejsciowego z ktorego ma zostac \npobrany tekst (-i Input.txt)\n");
}
