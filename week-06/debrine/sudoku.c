#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>


/* structure for passing data to threads */
typedef struct {
  int row;
  int column;
} parameters;

int validity_data[3][9];
int input_data[9][9];
char line[300];

void *checkrow(void *param);
void *checkcolumn(void *param);
void *checksquare(void *param);

int main(int argc, char **argv)
{
    
    if(argc < 2)
    {
        printf("Please input a text file as a command line argument\n");
    }
    else
    {
        //printf("made it to else \n");
        FILE *input = fopen(argv[1], "r");
        
        
        for(int i = 0; i < 9; i++)
        {
            fgets(line, 300, input);
            char delim[] = " ";
            char *num = strtok(line, delim);
            
            for(int j = 0; j<9;j++)
            {
                printf("%s\n", num);
                num = strtok(line, delim);
                input_data[i][j] = atoi(num);
                
                
            }
        }
        fclose(input);
        
        for(int i = 0;i++;i<9)
        {
            for(int j=0;j++;j<9)
            {
                //printf("%c ", input_data[i][j]);
            }
            //printf("\n");
        }


    }
    return 0;
    
    
}