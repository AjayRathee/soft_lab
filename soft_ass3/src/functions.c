/*
 * functions.c
 *
 *  Created on: 31-Jan-2015
 *      Author: ajay
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/functions.h"

int max,flag=0,h=0;

int fun(int len, char*buffer,FILE *fp_w)
{
	int r,l,j,t;char arr,str[256],temp[256];

	for(j=0;j<len;j++)
		{
			arr=buffer[j];t=0;
			if (arr == ',')
			{

				strncpy(str,buffer,j);
				r=atoi (str);h++;
				fprintf(fp_w,"%d,",r);

				for(l=0;l<len;l++)
				temp[l]=buffer[l];

				for(l=0;l<len-j;l++)
				buffer[l]=buffer[j+1+l];

				len=strlen(buffer);

				for(l=0;l<len;l++)
				{
					if(buffer[l] ==',')
					t=t+1;

				}


				if(t!=0)
				fun(len,buffer,fp_w);
				else if(t==0 && flag==0)
					{	strcpy(str,buffer);
						r=atoi (str);
						flag=1;
						 max=r;
						 fprintf(fp_w,"%d\n",r);
					}
			}
		}
			if(h==0)
			{
				r=atoi(buffer);
				fprintf(fp_w,"%d",r);

			}

return 0;
}


void operation(char *in_file)
{
	int i,j,l,m,a,b,c,d,arr[5],fl=0;FILE *fp_r,*fp_w;


	fp_r=fopen(in_file,"r");
	// find file size
	size_t pos = ftell(fp_r);    // Current position
	 fseek(fp_r, 0, SEEK_END);    // Go to end
	 size_t length = ftell(fp_r); // read the position which is the size
	 fseek(fp_r, pos, SEEK_SET);  // restore original position

	 h=(length-1)/2;			// account for commas and newline
	 printf("size of file = %d\n",h);
	fp_w=fopen("output.txt","w");
	fprintf(fp_w,"The possible a,b,c,d values are:\n");

			for(j=0;j<h;j++)
			{
				fscanf(fp_r,"%d%*c",&arr[j]);
				printf("array = %d\n",arr[j]);
			}

max = arr[h-1];
	for(i=0;i<h;i++)
		{
			a=arr[i];
			for(j=0;j<h;j++)
			{
				if(j!=i)
				{
					b=arr[j];
					for(m=0;m<h;m++)
					{
						if (m!=j && m!=i)
						{
							c=arr[m];
							for(l=0;l<h;l++)
							{	if (l!=m && l!=j && l!=i )
								{
									d=arr[l];
									if(a+b+c*d <=max)
									{
										fl=fl+1;
										fprintf(fp_w,"[%d,%d,%d,%d]\n",a,b,c,d);
									}
								}
							}
						}
					}
				}


			 }
		}
fprintf(fp_w,"******************************************************************************************\n");
if(fl==0)
{
printf("No possible combinations found\n");
fprintf(fp_w,"No possible combinations found\n");
}
else
{
printf("Found %d possible combinations\n",fl);
fprintf(fp_w,"Found %d possible combinations\n",fl);
}
fclose(fp_r);
 fclose(fp_w);
}

