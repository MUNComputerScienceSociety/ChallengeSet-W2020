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
        
        FILE *input = fopen(argv[1], "r");
        
        
        for(int i = 0; i < 9; i++)
        {
            fgets(line, 300, input);
            char delim[] = " ";
            char *num = strtok(line, delim);
            input_data[i][0] = atoi(num);
            
            for(int j = 1; j<9;j++)
            {
                
                num = strtok(NULL, delim);
                input_data[i][j] = atoi(num);
                
                
            }
            
            
        }
        fclose(input);
        
        for(int i = 0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                printf("%d ", input_data[i][j]);
            }
            printf("\n");
        }


    }
    return 0;
    
    
}

void *checkrow(void *param)
{
    int validity[9];
    int valid_indicator = 1;
    for(int i = 0; i<9; i++)
    {
        int num = input_data[param.row][i];
        validity[num-1]++;
    }

    for(int i = 0;i<9;i++)
    {
        if(validity[i] != 1)
        {
            valid_indicator = 0;
        }
    }
    if(valid_indicator)
    {
        validity_data[0][param.row] = 1;
    }
}

void *checkcolumn(void *param)
{
    int validity[9];
    int valid_indicator = 1;
    for(int i = 0; i<9; i++)
    {
        int num = input_data[i][param.column];
        validity[num-1]++;
    }

    for(int i = 0;i<9;i++)
    {
        if(validity[i] != 1)
        {
            valid_indicator = 0;
        }
    }
    if(valid_indicator)
    {
        validity_data[1][param.column] = 1;
    }
}

void *checksquare(void *param)
{
    int validity[9];
    int valid_indicator = 1;
    for(int i=param.row;i<param.row + 3;i++)
    {
        for(int j = param.column; j < param.column + 3; j++)
        {
            int num = input_data[i][j];
            validity[num-1] ++;
        }
    }

    for(int i = 0;i<9;i++)
    {
        if(validity[i] != 1)
        {
            valid_indicator = 0;
        }
    }
    if(valid_indicator)
    {
        if(param.row == 1 && param.column ==1)
        {
            validity_data[2][0] = 1;
        }

        else if(param.row == 1 && param.column ==4)
        {
            validity_data[2][1] = 1;
        }

        else if(param.row == 1 && param.column ==7)
        {
            validity_data[2][2] = 1;
        }

        else if(param.row == 4 && param.column ==1)
        {
            validity_data[2][3] = 1;
        }

        else if(param.row == 4 && param.column ==4)
        {
            validity_data[2][4] = 1;
        }

        else if(param.row == 4 && param.column ==7)
        {
            validity_data[2][5] = 1;
        }

        else if(param.row == 7 && param.column ==1)
        {
            validity_data[2][6] = 1;
        }

        else if(param.row == 7 && param.column ==4)
        {
            validity_data[2][7] = 1;
        }

        else if(param.row == 7 && param.column ==7)
        {
            validity_data[2][8] = 1;
        }
    }
}