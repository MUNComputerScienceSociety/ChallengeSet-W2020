#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>


/* structure for passing data to threads */
struct parameters{
  int row;
  int column;
};



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
        
        pthread_t tids[27];
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        struct parameters *data;

        


        for(int i=0;i<9;i++)
        {
            data = malloc(sizeof(struct parameters));
            (*data).row = i;
            pthread_create(&tids[i], &attr, checkrow, (void*)data);
        }

        for(int i=0;i<9;i++)
        {
            data = malloc(sizeof(struct parameters));
            (*data).column = i;
            pthread_create(&tids[i+9], &attr, checkcolumn, (void*)data);
        }

        int k = 0;
        for(int i=0;i<9;i = i+3)
        {
            for(int j=0;j<9;j = j+3)
            {
                data = malloc(sizeof(struct parameters));
                (*data).row = i;
                (*data).column = j;
                pthread_create(&tids[18+k], &attr, checksquare, (void*)data);
                //printf("row: %d, column: %d, k: %d\n", (*data).row, (*data).column, k);
                k++;
            }
        }

        for(int i = 0;i<27;i++)
        {
            pthread_join(tids[i], NULL);
        }

        int valid_solution = 1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(validity_data[i][j] != 1)
                {
                    valid_solution = 0;
                }
            }
        }
        
        //printf(" validity: \n");
        for(int i = 0;i<9;i++)
        {
            //printf("rows: %d, column: %d, square: %d\n", validity_data[0][i], validity_data[1][i], validity_data[2][i]);
        }



        if(valid_solution == 1)
        {
            printf("valid\n");
        }
        else if(valid_solution == 0)
        {
            printf("invalid\n");
        }


    }
    return 0;
    
    
}

void *checkrow(void *param)
{
    int validity[9] = {0,0,0,0,0,0,0,0,0};
    //validity[8] = 0;
    
    
    int valid_indicator = 1;

    struct parameters *data = (struct parameters*)param;
    //printf("row: %d last index of validity: %d\n",(*data).row, validity[8]);
    
    
    for(int i = 0; i<9; i++)
    {
        int num = input_data[(*data).row][i];
        validity[num-1]++;
        //printf("row: %d array index: %d  validity value: %d\n",(*data).row, num-1, validity[num-1]);
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
        validity_data[0][(*data).row] = 1;
    }
}

void *checkcolumn(void *param)
{
    int validity[9] = {0,0,0,0,0,0,0,0,0};
    int valid_indicator = 1;
    
    struct parameters *data = (struct parameters*)param;
    for(int i = 0; i<9; i++)
    {
        int num = input_data[i][(*data).column];
        validity[num-1]++;
        //printf("column: %d array index: %d  validity value: %d\n",(*data).column, num-1, validity[num-1]);
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
        validity_data[1][(*data).column] = 1;
    }
}

void *checksquare(void *param)
{
    int validity[9] = {0,0,0,0,0,0,0,0,0};
    int valid_indicator = 1;

    struct parameters *data = (struct parameters*)param;
    //printf("row index: %d column index: %d\n", (*data).row, (*data).column);
    for(int i=(*data).row;i<(*data).row + 3;i++)
    {
        for(int j = (*data).column; j < (*data).column + 3; j++)
        {
            int num = input_data[i][j];
            validity[num-1] ++;
            
        }
    }

    for(int i = 0;i<9;i++)
    {
        //printf("i value: %d validity: %d\n", i, validity[i]);
        if(validity[i] != 1)
        {
            valid_indicator = 0;
        }
    }

    if(valid_indicator)
    {
        if((*data).row == 0 && (*data).column ==0)
        {
            validity_data[2][0] = 1;
        }

        else if((*data).row == 0 && (*data).column ==3)
        {
            validity_data[2][1] = 1;
        }

        else if((*data).row == 0 && (*data).column ==6)
        {
            validity_data[2][2] = 1;
        }

        else if((*data).row == 3 && (*data).column ==0)
        {
            validity_data[2][3] = 1;
        }

        else if((*data).row == 3 && (*data).column ==3)
        {
            validity_data[2][4] = 1;
        }

        else if((*data).row == 3 && (*data).column ==6)
        {
            validity_data[2][5] = 1;
        }

        else if((*data).row == 6 && (*data).column ==0)
        {
            validity_data[2][6] = 1;
        }

        else if((*data).row == 6 && (*data).column ==3)
        {
            validity_data[2][7] = 1;
        }

        else if((*data).row == 6 && (*data).column ==6)
        {
            validity_data[2][8] = 1;
        }
    }
}