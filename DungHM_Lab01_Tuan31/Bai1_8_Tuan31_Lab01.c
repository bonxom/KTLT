/* Bài 1.8 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <stdio.h>
#include <stdlib.h>

void allocate_mem(int ***mt_dunghm, int m_dunghm, int n_dunghm){
    //#Allocate memory for the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/

    int i_dunghm = 0, j_dunghm = 0;
    *mt_dunghm = (int**)malloc(m_dunghm * sizeof(int*));
    for (i_dunghm = 0; i_dunghm < m_dunghm; i_dunghm++){
        (*mt_dunghm)[i_dunghm] = (int*)malloc(n_dunghm * sizeof(int));
    }
}


void input(int **mt_dunghm, int m_dunghm, int n_dunghm){
    //#Input elements of the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    int i_dunghm = 0, j_dunghm = 0;
    for (i_dunghm = 0; i_dunghm < m_dunghm; i_dunghm++){
        for (j_dunghm = 0; j_dunghm < n_dunghm; j_dunghm++){
            scanf("%d", &mt_dunghm[i_dunghm][j_dunghm]);
        }
    }
}

void output(int **mt_dunghm, int m_dunghm, int n_dunghm){
    //# Print all elements of the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/ 
   int i_dunghm = 0, j_dunghm = 0;

    for (i_dunghm = 0; i_dunghm < m_dunghm; i_dunghm++){
        for (j_dunghm = 0; j_dunghm < n_dunghm; j_dunghm++){
            printf("mt[%d][%d] = ", i_dunghm, j_dunghm);
        }
    }
    
    for (i_dunghm = 0; i_dunghm < m_dunghm; i_dunghm++){
        for (j_dunghm = 0; j_dunghm < n_dunghm; j_dunghm++){
            printf("%d ", mt_dunghm[i_dunghm][j_dunghm]);
        }
        printf("\n");
    }
}

int process(int **mt_dunghm, int m_dunghm, int n_dunghm){
    int tong_dunghm = 0;
    //# Calculate the sum of all even elements in the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    int i_dunghm = 0, j_dunghm = 0;
    for (i_dunghm = 0; i_dunghm < m_dunghm; i_dunghm++){
        for (j_dunghm = 0; j_dunghm < n_dunghm; j_dunghm++){
            if (mt_dunghm[i_dunghm][j_dunghm] % 2 == 0) tong_dunghm += mt_dunghm[i_dunghm][j_dunghm];
        }
    }
    return tong_dunghm;
}

void free_mem(int **mt_dunghm, int m_dunghm, int n_dunghm){
    //# Free memory
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    int i_dunghm = 0;
    for (i_dunghm = 0; i_dunghm < m_dunghm; i_dunghm++){
        free(mt_dunghm[i_dunghm]);
    }
    free(mt_dunghm);
}

int main(){
    printf("Ho Minh Dung - 5050\n");
    int m_dunghm, n_dunghm, **mt_dunghm;
    printf("Enter m, n = ");
    scanf("%d%d", &m_dunghm, &n_dunghm);
    allocate_mem(&mt_dunghm, m_dunghm, n_dunghm);
    input(mt_dunghm, m_dunghm, n_dunghm);
    output(mt_dunghm, m_dunghm, n_dunghm);
    printf("The sum of all even elements is %d", process(mt_dunghm, m_dunghm, n_dunghm));
    free_mem(mt_dunghm, m_dunghm, n_dunghm);
    return 0;
}