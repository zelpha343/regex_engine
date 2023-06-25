#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./main <filename> <regex>\n");
        return 1;
    }

    char *regex = argv[2];
    if (regex == NULL)
    {
        printf("Failed to get the regex\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc((file_size + 1) * sizeof(char));
    if (content == NULL)
    {
        printf("Failed to allocate memory.\n");
        fclose(file);
        return 1;
    }

    fread(content, sizeof(char), file_size, file);
    fclose(file);
    content[file_size] = '\0';

    printf("%s\n%s\n", content, regex);

    free(content);

    return 0;
}
