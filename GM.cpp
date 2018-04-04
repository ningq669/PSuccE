#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<time.h>
#include<math.h>
using namespace std;
char ss[100],path[100],s1[100],s2[100],s3[100],s4[100],s5[100],s6[100],s7[100],s8[100],s9[100],s10[100];
char s11[100],s12[100],s13[100],s14[100],s15[100],s16[100],s17[100],s18[100],s19[100],s20[100];
int main(int argc,char *argv[])
{
	sscanf(argv[1],"%s",ss); 
	sprintf(s1, "%saaindex_1.txt", ss);
	sprintf(s2, "%saaindex_2.txt", ss);
	sprintf(s3, "%saaindex_3.txt", ss);
	sprintf(s4, "%saaindex_4.txt", ss);
	sprintf(s5, "%saaindex_5.txt", ss);
	sprintf(s6, "%saaindex_6.txt", ss);
	sprintf(s7, "%saaindex_7.txt", ss);
	sprintf(s8, "%saaindex_8.txt", ss);
	sprintf(s9, "%saaindex_9.txt", ss);
	sprintf(s10, "%saaindex_10.txt", ss);
	sprintf(s11, "%sgm_1.txt", ss);
	sprintf(s12, "%sgm_2.txt", ss);
	sprintf(s13, "%sgm_3.txt", ss);
	sprintf(s14, "%sgm_4.txt", ss);
	sprintf(s15, "%sgm_5.txt", ss);
	sprintf(s16, "%sgm_6.txt", ss);
	sprintf(s17, "%sgm_7.txt", ss);
	sprintf(s18, "%sgm_8.txt", ss);
	sprintf(s19, "%sgm_9.txt", ss);
	sprintf(s20, "%sgm_10.txt", ss);
    int i,j,k,l,m,n,kk;
	double t;
    char str[1000];
    double x[1000];
    double x1[1000];
    double B[100][100];
    double B1[100][100];
    double MG[100][100];
    double MG1[100][100];
    double MG2[100][100];
    double MG3[100][100];
    double Y[100];
	FILE *p1=fopen(s1,"r");
	FILE *p2=fopen(s2,"r");
	FILE *p3=fopen(s3,"r");
	FILE *p4=fopen(s4,"r");
	FILE *p5=fopen(s5,"r");
	FILE *p6=fopen(s6,"r");
	FILE *p7=fopen(s7,"r");
	FILE *p8=fopen(s8,"r");
	FILE *p9=fopen(s9,"r");
	FILE *p10=fopen(s10,"r");
	FILE *p11=fopen(s11,"w");
	FILE *p12=fopen(s12,"w");
	FILE *p13=fopen(s13,"w");
	FILE *p14=fopen(s14,"w");
	FILE *p15=fopen(s15,"w");
	FILE *p16=fopen(s16,"w");
	FILE *p17=fopen(s17,"w");
	FILE *p18=fopen(s18,"w");
	FILE *p19=fopen(s19,"w");
	FILE *p20=fopen(s20,"w");
	while(fgets(str,1000,p1))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p11,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p11,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
		while(fgets(str,1000,p2))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p12,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p12,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
		while(fgets(str,1000,p3))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p13,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p13,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
		while(fgets(str,1000,p4))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p14,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p14,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
		while(fgets(str,1000,p5))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p15,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p15,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
		while(fgets(str,1000,p6))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p16,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p16,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
		while(fgets(str,1000,p7))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p17,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p17,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
		while(fgets(str,1000,p8))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p18,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p18,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
		while(fgets(str,1000,p9))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p19,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p19,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
	while(fgets(str,1000,p10))
	{
		i=0;
		l=strlen(str);
		str[l-1]='\0';
		char *pp=strtok(str," ");
		while(pp!=NULL)
		{
			x[i++]=atof(pp);
			pp=strtok(NULL," ");
		}
		n=i;
		memset(x1,0,sizeof(x1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				x1[i]+=x[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			B[i][0]=(x1[i]+x1[i+1])*(-0.5);
			B[i][1]=1;
			Y[i]=x[i+1];
			B1[0][i]=B[i][0];
			B1[1][i]=B[i][1];
		}
		memset(MG1,0,sizeof(MG1));
		memset(MG2,0,sizeof(MG2));
		memset(MG3,0,sizeof(MG3));
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<2;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG1[i][j]=MG1[i][j]+B1[i][k]*B[k][j];    
				}   
			} 
 		}
 		
 		if(MG1[0][1]*MG1[1][0]==MG1[0][0]*MG1[1][1])
 		{
			fprintf(p20,"0 0\n");
			continue;
		}
		t=MG1[0][0]*MG1[1][1]-MG1[0][1]*MG1[1][0];
		t=1.0/t;
		MG[0][0]=t*MG1[1][1];
		MG[1][1]=t*MG1[0][0];
		MG[0][1]=-t*MG1[0][1];
		MG[1][0]=-t*MG1[1][0];
 		for(i=0;i<2;i++)  
		{   
			for(j=0;j<n-1;j++)   
			{    
				for(k=0;k<2;k++)    
				{     
					MG2[i][j]=MG2[i][j]+MG[i][k]*B1[k][j];    
				}   
			} 
 		}
		for(i=0;i<2;i++)  
		{   
			for(j=0;j<1;j++)   
			{    
				for(k=0;k<n-1;k++)    
				{     
					MG3[i][j]=MG3[i][j]+MG2[i][k]*Y[k];    
				}   
			} 
 		}
 		fprintf(p20,"%g %g\n",MG3[0][0],MG3[1][0]);
	}
    return(0);
}
