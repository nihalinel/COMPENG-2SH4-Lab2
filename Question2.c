#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr [])
{

    // This is the first programming (scripting) question without any initial setup as hints.

    // This is also the first question requiring you to come up with an algorithm on paper 
    // with mathematical analysis before implementing the code.

    // High Level Hint:
    //  Assume a 3x3 square matrix, look at the SUM of the row and column indices of each element.
    //  You should be able to see a numerical pattern after doing so.

    int x;
    int y;
    int z=0;
    int arr_i=0;
    //int size = N3*N3;

    for (x = 0; x < N3; x++)
    {
        for (y = 0; y < N3; y++)
        {
            z = x + y;            
            //int mid = N3 - 1;

            switch (z)
            {
                case 0:
                    arr[arr_i] = mat[x][y];
                    arr_i++;
                    break;

                case 1:
                    if (x==0)
                    {
                        arr[arr_i] = mat[x][y];
                        arr[arr_i+1] = mat[y][x];
                        arr_i = arr_i+2;                        
                    }
                    break;

                case 2:
                    if (x==0)
                    {
                        arr[arr_i] = mat[x][y];
                        arr[arr_i+1] = mat[x+1][y-1];
                        arr[arr_i+2] = mat[y][x];
                        arr_i = arr_i+3;
                        
                    }
                    break;

                case 3:
                    if (y==2)
                    {
                        arr[arr_i] = mat[x][y];
                        arr[arr_i+1] = mat[y][x];
                        arr_i = arr_i+2;
                    }
                    break;

                case 4:
                    arr[arr_i] = mat[x][y];
                    arr_i++;
                    break;

            }
        }
    }  

}