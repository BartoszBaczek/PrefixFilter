#ifndef TEXTHANDLING_H_INCLUDED
#define TEXTHANDLING_H_INCLUDED

/*
FUNCTIONS INCLUDED IN THIS HEADER FILE:


int HelpIsNeeded(int paramNumber, char* parameter[]);
void PrintHelpMessage();
char* GetPrefix(int paramNumber, char* parameter[]);
char* GetInputFileName(int paramNumber, char* parameter[]);
char* GetOutputFileName(int paramNumber, char* parameter[]);
void CopyWordsToNewFile(char* inputFileName, char* outputFileName, char* prefix);
int Exists(char *fileName);
void PassWordsWithPrefixes(char *word, char* outputFileName, char* prefix);
int WordHasPrefix(char* word, char* prefix);


*/


int HelpIsNeeded(int paramNumber, char* parameter[])
{
        int i = 0, j;
        int returnValue = 0;

        while (i <= paramNumber-1)                      //
        {                                               //
            if (!strcmp(parameter[i], "-h"))            // Petla sprawdzajaca, czy
            {                                           // uzytkownik podal jako
                return 1;                               // parametr w dowolnym miejscu
            }                                           // '-h'
            i++;                                        //
        }                                               //



        for (i = 1; i < paramNumber; i++)                                                                           //
        {                                                                                                           //
            for (j = 1; j < paramNumber; j++)                                                                       //
            {                                                                                                       //
                if (j != i)                                                                                         //  Petle sprawdzaja,
                    {                                                                                               //  czy uzytkownik nie
                        if (!strcmp(parameter[i], parameter[j]))                                                    //  uzyl dwóch takich
                        {                                                                                           //  samych wartosci
                            printf("Podales ta sama nazwe dla pliku wejsciowego, jak i wyjsciowego.\n\n\n");        //  parametrow (np.
                            return 1;                                                                               //  takiej samej nazwy
                        }                                                                                           //  plike wej. i pliku wyj.)
                    }                                                                                               //
            }                                                                                                       //
        }                                                                                                           //


        return 0;
}

void PrintHelpMessage()
{
        printf("\t\t\tPOMOC PROGRAMU FILTR PRZEDROSTKOWY\t\t\n");
        printf("W celu poprawnego uruchomienia programu, musisz zrobic nastepujace rzeczy:\n");
        printf("1) Po przedrostku -o podaj nazwe pliku wyjsciowego (na przyklad -o Output.txt)\n");
        printf("2) Nastpenie po przedrostku -f podaj przedrostek (na przyklad -f pra)\n");
        printf("3) Po przedrostku -i podaj nazwe pliku wejsciowego z ktorego ma zostac \npobrany tekst (-i Input.txt)\n");
}

char* GetPrefix(int paramNumber, char* parameter[])
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

char* GetInputFileName(int paramNumber, char* parameter[])
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

char* GetOutputFileName(int paramNumber, char* parameter[])
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


void CopyWordsToNewFile(char* inputFileName, char* outputFileName, char* prefix)
{
    {
        FILE *inputFile;
        char singleWord[100];
        char c;

        if (Exists(inputFileName))
        {
            inputFile = fopen(inputFileName,"r");

            do
            {
                c = fscanf(inputFile,"%s",singleWord);
                PassWordsWithPrefixes(&singleWord, outputFileName, prefix);
            } while (c != EOF);

            fclose(inputFile);
        }
        else
            printf("Plik o nazwie '%s' nie istnieje. \nSprawdz czy podales podales poprawna nazwe pliku.  \nW celu uzyskania pomocy uzyj komendy 'PrefixFilter -h'.\n\n", inputFileName);

	}
}

int Exists(char *fileName)
{
    FILE *file;
    if (file = fopen(fileName, "r"))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

void PassWordsWithPrefixes(char* word, char* outputFileName, char* prefix)
{
    if (WordHasPrefix(word, prefix))
    {
        FILE *outputFile;

        outputFile = fopen(outputFileName, "a");
        fprintf(outputFile, word);
        fprintf(outputFile, " ");
        fclose(outputFile);
    }
}

int WordHasPrefix(char* word, char* prefix)
{
    int i;

    for (i = 1; i <strlen(prefix); i++)
    {
        if  (!(prefix[i] == word[i]))
            return 0;
    }
    return 1;
}





#endif // TEXTHANDLING_H_INCLUDED
