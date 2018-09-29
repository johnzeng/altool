
#define MAX_NODE 100
int A[MAX_NODE][MAX_NODE];

void Floyd()
{
    int i , j , k;
    for(i = 0 ; i < MAX_NODE ; i++)
        for(j = 0 ; j < MAX_NODE ; j++)
            for(k = 0 ; k < MAX_NODE ; k++)
                if(A[j][k] > A[j][i] + A[i][k])
                {
                    A[j][k] = A[j][i] + A[i][k];
                }
}

