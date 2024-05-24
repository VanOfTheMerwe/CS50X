#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

//*Variables to be used
BYTE buffer[512];
int count = 0;
FILE *image_pointer = NULL;
char filename[8];

int main(int argc, char *argv[])
{
    //! If the correct input isn't given, display error message
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    else
    {
        //*Open card.raw
        char *input_file_name = argv[1];
        FILE *input_pointer = fopen(input_file_name, "r");

        //! If there is no file, display error message
        if (input_pointer == NULL)
        {
            printf("Error: cannot open %s\n", input_file_name);
            return 2;
        }

        //*Repeat until end
        while (fread(&buffer, 512, 1, input_pointer) == 1)
        {
            //*If start of a new JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0)
            {
                //*If not first JPEG, close previous
                if (!(count == 0))
                {
                    fclose(image_pointer);
                }
                //*Initialise file
                sprintf(filename, "%03i.jpg", count);
                image_pointer = fopen(filename, "w");
                count++;
            }
            //*If JPEG has been found, write to file
            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, image_pointer);
            }
        }
        fclose(input_pointer);
        fclose(image_pointer);
        return 0;
    }
}
