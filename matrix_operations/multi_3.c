#include"helper.h"

void multi(int **,int **,int **,int,int,int,int,int,int,int,int);
int check_call(int,int,int);
int main()
{
	int **a,**b,**c,n,r1,r2,c1,c2;
	do{
		printf("Enter no. of rows and columns in first matrix: ");
		scanf("%d%d",&r1,&c1);
		printf("Enter no. of rows and columns in second matrix: ");
		scanf("%d%d",&r2,&c2);
	}while(c1!=r2);
	n=check_call(r1,c1,c2);
	a=mem_alloc(n,n);
	b=mem_alloc(n,n);
	c=mem_alloc(n,n);
	
	printf("Enter %d*%d elements in first matrix:\n",r1,c1);
	input(a,r1,c1);
	printf("Enter %d*%d elements in second matrix:\n",r2,c2);
	input(b,r2,c2);
	printf("\nMatrix A:\n");
	display(a,r1,c1);
	printf("\nMatrix B:\n");
	display(b,r2,c2);
	
	multi(a,b,c,0,n,0,n,0,n,0,n);
	printf("\nMatrix A X Matrix B:\n");
	display(c,r1,c2);
	
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

int check_call(int r,int c,int c2)
{
	int max=r;
	if(c>max)
		max=c;
	if(c2>max)
		max=c2;
	int i=2;
	while(i<max)
		i=i<<1;
	return i;
}
