#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Readparameter(int paramSize, char *parameter[]);
char* FindPrefix(int paramSize, char* parameter[]);
char FindInputFileName(int paramSize, char *parameter[]);
char FindOutputFileName(int paramSize, char *parameter[]);


void PrintHelpMessage();

int main(int argc, char *argv[])
{

    Readparameter(argc, argv);

    return 0;
}

void Readparameter(int paramSize, char *parameter[])
{
    char *prefix = FindPrefix(paramSize, parameter);

    struct Programparameter
    {
        char prefix;
        char inputFileName;
        char outputFileName;
    };

    //strcpy( prefix, FindPrefix(paramSize, parameter));

    printf("%s", prefix);
    //inputFileName = FindInputFileName
}

char* FindPrefix(int paramSize, char* parameter[])
{
    printf("%s", parameter[2]);

    char *ret = malloc(strlen(parameter[2]));
    ret = parameter[2];

    return ret;

}

char FindInputFileName(int paramSize, char *parameter[])
{

}

char FindOutputFileName(int paramSize, char *parameter[])
{

}



void PrintHelpMessage()
{
        printf("\t\t\tPOMOC PROGRAMU FILTR PRZEDROSTKOWY\t\t\n");
        printf("W celu poprawnego uruchomienia programu, musisz zrobic nastepujace rzeczy:\n");
        printf("1) Po przedrostku -o podaj nazwe pliku wyjsciowego (na przyklad -o Output.txt)\n");
        printf("2) Nastpenie po przedrostku -f podaj przedrostek (na przyklad -f pra)\n");
        printf("3) Po przedrostku -i podaj nazwe pliku wejsciowego z ktorego ma zostac \npobrany tekst (-i Input.txt)\n");
}
