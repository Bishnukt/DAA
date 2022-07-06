#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *mem_alloc();
int match_string(char *,char *);

int main()
{
	char *string,*pat;
	printf("Enter the string: ");	
	string=mem_alloc();
	printf("Enter the pattern to search: ");
	pat=mem_alloc();
	int in=match_string(string,pat);
	if(in<0)
		printf("Pattern not found in given text.\n");
	else
		printf("Pattern found at index %d in given text.\n",in);
	return 0;

}

char *mem_alloc()
{
	char *str=(char *)calloc(100,sizeof(char));
	scanf("%s",str);
	return str;
}	

int match_string(char *string,char *pat)
{
	int in=-1;
	int j=0;
	int len1=strlen(string),len2=strlen(pat);
	printf("Length of text=%d chars, pattern=%d chars.\n",len1,len2);
	for(int i=0;string[i]!='\0';i++)
	{
		if(string[i]==pat[0])
		{
			for(j=i;pat[j]!='\0' && string[j]!='\0';j++)
				if(pat[j]!=string[j])
					break;
		}
		if(j==len2)
		{
			in=i;
			break;
		}	
	}
	return in;
}
