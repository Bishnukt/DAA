#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 100

int *lps(char *);
char *mem_alloc();
int *kmp(char *,char *,int *);

int main(int argc,char *argv[])
{
	int j=0;
	printf("Enter the string: ");
	char *str=mem_alloc();
	printf("Enter the pattern to search in the given string: ");
	char *pat=mem_alloc();
	int *ind=kmp(str,pat,&j);
	if(j==0)
		printf("Pattern not found in the given string.\n");
	else
	{
		printf("Pattern found at index no.s-> ");
		for(int i=0;i<j;i++)
			printf("%d\t",ind[i]);
		printf("\n");
	}
	return 0;
}

int *lps(char *pat)
{
	int sz=strlen(pat);
	int *pi=(int *)calloc(sz,sizeof(int));
	int k=-1;
	for(int i=1;i<sz;i++)
	{
		while(k>=0 && pat[i]!=pat[k+1])
			k=pi[k];
		if(pat[i]==pat[k+1])
			k=k+1;
		pi[i]=k;
	}
	return pi;
}

int *kmp(char *str,char *pat,int *j)
{
	int *pi=lps(pat);
	int sz=strlen(pat),len=strlen(str);
	int i=0,k=-1;
	int *res=(int *)calloc(len,sizeof(int));
	for(i=0;i<len-1;i++)
	{
		while(k>=0 && pat[k+1]!=str[i])
			k=pi[k];
		if(pat[k+1]==str[i])
			k=k+1;
		if(k==sz-2)
		{
			res[*j]=i-(sz-2);
			++*j;
			k=pi[k];
		}
	}
	return res;
}

char *mem_alloc()
{
	char *tmp=(char *)calloc(size,sizeof(char));
	fgets(tmp,size,stdin);
	int s=strlen(tmp);
	tmp=realloc(tmp,s);
	return tmp;
}
