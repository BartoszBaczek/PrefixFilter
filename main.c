#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PARAMETERS HANDLING
char* Prefix(int paramSize, char* parameter[]);
char* InputFileName(int paramSize, char* parameter[]);
char* OutputFileName(int paramSize, char* parameter[]);
void PassWordsWithPrefixes(char* fileLine, char* outputFileName, char* prefix);
void PrintHelpMessage();

void ReadFileLineByLine(char* inputFileName, char* outputFileName, char* prefix);

int main(int argc, char *argv[])
{

    typedef struct
    {
        char *prefix;
        char *inputFileName;
        char *outputFileName;
    }ProgramParameter;

    ProgramParameter programParameter = {Prefix(argc, argv)
                                        , InputFileName(argc, argv)
                                        , OutputFileName(argc, argv)};


    ReadFileLineByLine(programParameter.inputFileName, programParameter.outputFileName, programParameter.prefix);
    return 0;
}



char* Prefix(int paramSize, char* parameter[])
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

char* InputFileName(int paramSize, char* parameter[])
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

char* OutputFileName(int paramSize, char* parameter[])
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

void ReadFileLineByLine(char* inputFileName, char* outputFileName, char* prefix)
{
    {
    	FILE *inputFile;
        char *fileLine;

        inputFile = fopen(inputFileName ,"r");

        if (!inputFile)
            return 1;

        while (fgets(fileLine,1000, inputFile)!=NULL)
            PassWordsWithPrefixes(fileLine, outputFileName, prefix);



		fclose(inputFile);
    		return 0;
	}
}

void PassWordsWithPrefixes(char* fileLine, char* outputFileName, char* prefix)
{

    FILE *outputFile;
    outputFile = fopen(outputFileName, "a");

    if (!inputFile)
        return 1;

    fprintf(output file, )

    int i = 0;
    int lineLength = strlen(fileLine);

    while ((fileLine[i]!=' ') && (i != lineLength-1))
    {
        printf("%c", fileLine[i]);
        i++;
    }
    printf("|||");

    /*
      char str[] ="- This, a sample string.";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ,.-");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }
  return 0;*/




    /*
    123 12345
    12345
    1234567 12345
    12345
    1234567
    */

}
void PrintHelpMessage()
{
        printf("\t\t\tPOMOC PROGRAMU FILTR PRZEDROSTKOWY\t\t\n");
        printf("W celu poprawnego uruchomienia programu, musisz zrobic nastepujace rzeczy:\n");
        printf("1) Po przedrostku -o podaj nazwe pliku wyjsciowego (na przyklad -o Output.txt)\n");
        printf("2) Nastpenie po przedrostku -f podaj przedrostek (na przyklad -f pra)\n");
        printf("3) Po przedrostku -i podaj nazwe pliku wejsciowego z ktorego ma zostac \npobrany tekst (-i Input.txt)\n");
}
