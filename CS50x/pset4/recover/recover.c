#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int is_raw_image(char *s);
int recover(char *filename);

int main(int argc, char *argv[])
{
    //checking if such arguments are valid
    if (argc < 2 || is_raw_image(argv[1]) == 1)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    recover(argv[1]);
    return 0;
}


//function for validation
int is_raw_image(char *s)
{
    int length = 0; 
    for (; s[length] != '\0'; ++length);
    
    for (int i = 0; i < length - 2; ++i)
    {
        //check if the last 3 characters spell .raw
        if (s[i + 0] == 'r' && s[i + 1] == 'a' && s[i + 2] == 'w')
        {
            return 0;
        }
    }
    
    return 1;
}

int recover(char *filename)
{
    //file pointers to read and write
    FILE *file_to_read = NULL; 
    FILE *file_to_write = NULL;
    
    //stream buffer 
    uint8_t *buffer = malloc(sizeof(uint8_t) * 512);
    
    //opening forantics file
    if ((file_to_read = fopen(filename, "r")) == NULL)
    {
        printf("%s does not exist", filename);
        return 1;
    }
    
    int fileNumber = 0;
    size_t size;
    char *file_jpg = malloc(sizeof(char) * 10);
    
    //read forantice file will end of file
    while (!feof(file_to_read))
    {
        size = fread(buffer, sizeof(uint8_t), 512, file_to_read);
        
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if ((buffer[3] & 0xf0) == 0xe0)
            {
                //if file is not null then we close it 
                //and open a new one because we found the first 4 bits that
                //represent a new jpg file
                if (file_to_write != NULL)
                {
                    fclose(file_to_write);
                    ++fileNumber;
                }  
                sprintf(file_jpg, "%03i.jpg", fileNumber);
                
                //if fopen returns null then 
                //flush all streams and free all memories 
                if ((file_to_write = fopen(file_jpg, "w")) == NULL)
                {
                    printf("Unable to creat file\n");
                    fflush(file_to_read);
                    fclose(file_to_read);
                    free(buffer);
                    free(file_jpg);
                    return 1;
                }
            }
        }
        
        //only write to write file if it's not null
        if (file_to_write != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), size, file_to_write);
        }
    }
    
    //flush and free all memories before end of 
    //recovery function
    fflush(file_to_write);
    fclose(file_to_write);
    fflush(file_to_read);
    fclose(file_to_read);
    free(file_jpg);
    free(buffer);
    
    return 0;
}
