#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char ch;
    char inputFile[50], outputFile[50];

    printf("Enter name of input file: ");
    scanf("%s", inputFile);

    printf("Enter name of output file: ");
    scanf("%s", outputFile);

    fp1 = fopen(inputFile, "r");
    if (fp1 == NULL)
    {
        printf("Cannot open input file.\n");
        return 1;
    }

    fp2 = fopen(outputFile, "w");
    if (fp2 == NULL)
    {
        printf("Cannot create output file.\n");
        fclose(fp1);
        return 1;
    }

    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }

    printf("File copied successfully.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}