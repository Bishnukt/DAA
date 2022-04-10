#include"helper.h"

void multi(int **,int **,int **,int,int,int,int,int,int,int,int);

int main()
{
	int **a,**b,**c,n;
	printf("Enter no. of rows and columns in two square matrices: ");
	scanf("%d",&n);
	a=mem_alloc(n,n);
	b=mem_alloc(n,n);
	c=mem_alloc(n,n);
	
	printf("Enter %d*%d elements in first matrix:\n",n,n);
	input(a,n,n);
	printf("Enter %d*%d elements in second matrix:\n",n,n);
	input(b,n,n);
	printf("\nMatrix A:\n");
	display(a,n,n);
	printf("\nMatrix B:\n");
	display(b,n,n);
	
	multi(a,b,c,0,n,0,n,0,n,0,n);
	printf("\nMatrix A X Matrix B:\n");
	display(c,n,n);
	
	freeall(a,n);
	freeall(b,n);
	freeall(c,n);

	return 0;
}

void multi(int **a,int **b,int **c,int ars,int are,int acs,int ace,int brs,int bre,int bcs,int bce)
{
	if(are-ars==1)
		c[ars][bcs]+=a[ars][acs]*b[acs][bcs];
	else
	{
		multi(a,b,c,ars,(ars+are)/2,acs,(acs+ace)/2,brs,(brs+bre)/2,bcs,(bcs+bce)/2);
		multi(a,b,c,ars,(ars+are)/2,(acs+ace)/2,ace,(brs+bre)/2,bre,bcs,(bcs+bce)/2);
		multi(a,b,c,ars,(ars+are)/2,acs,(acs+ace)/2,brs,(brs+bre)/2,(bcs+bce)/2,bce);
		multi(a,b,c,ars,(ars+are)/2,(acs+ace)/2,ace,(brs+bre)/2,bre,(bcs+bce)/2,bce);
		multi(a,b,c,(ars+are)/2,are,acs,(acs+ace)/2,brs,(brs+bre)/2,bcs,(bcs+bce)/2);
		multi(a,b,c,(ars+are)/2,are,(acs+ace)/2,ace,(brs+bre)/2,bre,bcs,(bcs+bce)/2);
		multi(a,b,c,(ars+are)/2,are,acs,(acs+ace)/2,brs,(brs+bre)/2,(bcs+bce)/2,bce);
		multi(a,b,c,(ars+are)/2,are,(acs+ace)/2,ace,(brs+bre)/2,bre,(bcs+bce)/2,bce);
	}
}

