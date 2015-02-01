/*
 * main.c
 *
 *  Created on: 31-Jan-2015
 *      Author: ajay
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/functions.h"


int main ()
	{
		int i,input,len;
		char buffer[256],in_file[256];
		FILE *fp_w;

		//printf("%s",buffer);
		printf("Enter the input method Manual or Text File: 1 for manual and 0 for text file\n ");
		scanf("%d",&input);
		if(input)
		{
			fp_w = fopen("input.txt","w");
			printf("Enter the input as comma separated values. Last value should be the test number\n");
		scanf("%s",buffer);
		len=strlen(buffer);

		fun(len,buffer,fp_w);
		fclose(fp_w);
		operation("input.txt");
		}
		else
		{
			printf("Specify the file name\n");
			scanf("%s",in_file);
			printf("File = %s\n",in_file);
			operation(in_file);

		}


		return 0;
	}
