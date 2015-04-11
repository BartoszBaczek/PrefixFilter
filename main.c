#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PARAMETERS HANDLING
char* GetPrefix(int paramSize, char* parameter[]);
char* GetInputFileName(int paramSize, char* parameter[]);
char* GetOutputFileName(int paramSize, char* parameter[]);
void PassWordsWithPrefixes(char *word, char* outputFileName, char* prefix);
void PrintHelpMessage();
void ReadFileWordByWord(char* inputFileName, char* outputFileName, char* prefix);
int WordHasPrefix(char* word, char* prefix);

int main(int argc, char *argv[])
{

    typedef struct
    {
        char *prefix;
        char *inputFileName;
        char *outputFileName;
    }ProgramParameter;

    ProgramParameter programParameter = {GetPrefix(argc, argv)
                                        , GetInputFileName(argc, argv)
                                        , GetOutputFileName(argc, argv)};

    ReadFileWordByWord(programParameter.inputFileName, programParameter.outputFileName, programParameter.prefix);
    return 0;
}



char* GetPrefix(int paramSize, char* parameter[])
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

char* GetInputFileName(int paramSize, char* parameter[])
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

char* GetOutputFileName(int paramSize, char* parameter[])
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

void ReadFileWordByWord(char* inputFileName, char* outputFileName, char* prefix)
{
    {
        FILE *inputFile;
        char singleWord[100];
        char c;

        inputFile = fopen(inputFileName,"r");

        do
        {
            c = fscanf(inputFile,"%s",singleWord);
            PassWordsWithPrefixes(&singleWord, outputFileName, prefix);
        } while (c != EOF);

         fclose(inputFile);
	}
}
int WordHasPrefix(char* word, char* prefix)
{
    int i;
    int returnValue = 1;

    for (i = 1; i <strlen(prefix); i++)
    {
        if  (!(prefix[i] == word[i]))
            return 0;
    }
    return 1;
}
void PassWordsWithPrefixes(char* word, char* outputFileName, char* prefix)
{
    if (WordHasPrefix(word, prefix))
    {
        FILE *outputFile;

        outputFile = fopen(outputFileName, "a");
        fprintf(outputFile, word);
        fclose(outputFile);
    }
}
void PrintHelpMessage()
{
        printf("\t\t\tPOMOC PROGRAMU FILTR PRZEDROSTKOWY\t\t\n");
        printf("W celu poprawnego uruchomienia programu, musisz zrobic nastepujace rzeczy:\n");
        printf("1) Po przedrostku -o podaj nazwe pliku wyjsciowego (na przyklad -o Output.txt)\n");
        printf("2) Nastpenie po przedrostku -f podaj przedrostek (na przyklad -f pra)\n");
        printf("3) Po przedrostku -i podaj nazwe pliku wejsciowego z ktorego ma zostac \npobrany tekst (-i Input.txt)\n");
}
