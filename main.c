#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texthandling.h"


int main(int argc, char *argv[])
{

    typedef struct
    {
        char *prefix;
        char *inputFileName;
        char *outputFileName;
    }ProgramParameter;

    if (HelpIsNeeded(argc, argv))
    {
        PrintHelpMessage();
    }
    else
    {

        ProgramParameter programParameter = {GetPrefix(argc, argv)
                                        , GetInputFileName(argc, argv)
                                        , GetOutputFileName(argc, argv)};

        CopyWordsToNewFile(programParameter.inputFileName, programParameter.outputFileName, programParameter.prefix);

    }

    return 0;
}
