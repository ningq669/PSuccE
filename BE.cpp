#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<time.h>
using namespace std;
int main()
{
	int i,j,k,l,m,n,ran[2000],cou,cc;
	char aa[25]="ACDEFGHIKLMNPQRSTVWY",str[50],str1[50];
	FILE *p=fopen("train_n1.txt","r");//Ñù±¾Æ¬¶Î 
	FILE *p1=fopen("BE_train_n.txt","w");
	cou=1;
	while(fgets(str,50,p))
	{
		l=strlen(str)-1;
		n=1;
		for(i=0;i<l;i++)
		{
			//if(i==l/2)continue;
			for(j=0;j<20;j++)
			{
				if(str[i]==aa[j])break;
			}
			for(k=0;k<20;k++)
			{
				if(k==j)fprintf(p1,"1 ");
				else fprintf(p1,"0 ");
			}
		}
		fprintf(p1,"\n");
		cou++;
	}
	return 0;
}
