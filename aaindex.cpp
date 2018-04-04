#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<time.h>
#include<math.h>
using namespace std;
int main()
{
    int i,j,k,l,m,n;
    char str[1000],s[100],str1[100];
    char s1[25]="ARNDCQEGHILKMFPSTWYV";
	FILE *p=fopen("aaindex1.txt","r");
	double x[25];
	n=1;
	while(fgets(str,1000,p))
	{
		m=0;
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[m++]=atof(pp);
			pp=strtok(NULL," ");
		}
		sprintf(s,"aaindex_n_%d.txt",n++);
		FILE *p1=fopen("train_n1.txt","r");
		FILE *p2=fopen(s,"w");
		while(fgets(str1,100,p1))
		{
			l=strlen(str1);
			for(i=0;i<l-1;i++)
			{
				for(j=0;j<m;j++)
				{
					if(str1[i]==s1[j])
					{
						fprintf(p2,"%g ",x[j]);
						break;
					}
				}
				if(j==m)
					fprintf(p2,"0 ");
			}
			fprintf(p2,"\n");
		}
		fclose(p2);
		fclose(p1);
	}
    return(0);
}
