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
    int cou[25];
    char str[1000];
    char s[25]="ARNDCQEGHILKMFPSTWYV";
	FILE *p=fopen("train_n1.txt","r");
	freopen("AAC_train_n.txt","w",stdout);
	int sum=0;
	while(fgets(str,1000,p))
	{
		l=strlen(str)-1;
		memset(cou,0,sizeof(cou));
		for(i=0;i<l;i++)
		{
			for(j=0;j<20;j++)
			{
				if(str[i]==s[j])
					break;
			}
			cou[j]++;
		}
		//if(cou[20]==0)sum++;
		for(i=0;i<=20;i++)
		{
			printf("%g ",cou[i]*1.0/l);
		}
		printf("\n");
	}
	//printf("%d",sum);
    return(0);
}
