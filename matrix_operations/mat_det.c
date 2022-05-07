//#include <stdio.h>
//#include <stdlib.h>
#include"helper.h"

int det(int **, int);
int **mem_alloc(int, int);
void input(int **, int, int);
void display(int **, int, int);

int main()
{
    int n,res;
    int **mat;
    printf("**Square Matrix**\n");
    printf("Enter the size of rows and columns of the matrix: ");
    scanf("%d", &n);
    mat = mem_alloc(n,n);
    printf("Enter %d*%d elements: ",n,n);
    input(mat,n,n);
    printf("Given Matrix: \n");
    display(mat,n,n);
    res = det(mat,n);
    printf("Determinant of given matrix: %d.\n", res);
    return 0;
}

int det(int **mat, int n)
{
	int i,j,k,**tmp,x=0,res=0;

	if(n==2)
	{
		return (mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
	}
	tmp=mem_alloc(n-1,n-1);
	for(k=0;k<n;k++)
	{
		for(i=1;i<n;i++){
			for(j=0;j<n;j++)
			{
				if(j!=k){
					tmp[i-1][x]=mat[i][j];
					x++;
				}
			}
		x=0;
		}
		if(k%2==0)
			res+=mat[0][k]*det(tmp,n-1);
		else
			res-=mat[0][k]*det(tmp,n-1);
	}
	return res;

}

