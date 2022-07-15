#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 100

int *lps(char *);
char *mem_alloc();
int kmp(char *,char *);

int main(int argc,char *argv[])
{
	printf("Enter the string: ");
	char *str=mem_alloc();
	printf("Enter the pattern to search in the given string: ");
	char *pat=mem_alloc();
	int ind=kmp(str,pat);
	if(ind)
		printf("Pattern found at index no. %d.\n",ind);
	else
		printf("Pattern not found in the given string.\n");
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

int kmp(char *str,char *pat)
{
	int *pi=lps(pat);
	int sz=strlen(pat),len=strlen(str);
	int i=0,k=-1;
	for(i=0;i<len;i++)
	{
		while(k>=0 && pat[k+1]!=str[i])
			k=pi[k];
		if(pat[k+1]==str[i])
			k=k+1;
		if(k==sz-1)
		{
			return i-(sz-1);
		}
	}
	return -1;
}

char *mem_alloc()
{
	char *tmp=(char *)calloc(size,sizeof(char));
	fgets(tmp,size,stdin);
	int s=strlen(tmp);
	tmp=realloc(tmp,s);
	return tmp;
}


