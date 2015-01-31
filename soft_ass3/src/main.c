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
		int len;

		char buffer [256];
		FILE *fp_w;
	        fp_w = fopen("input.txt","w");
		//printf("%s",buffer);
		printf("Enter the set S first and the value of k separated by commas :\n ");
		scanf("%s",buffer);
		len=strlen(buffer);

		fun(len,buffer,fp_w);
		fclose(fp_w);
		operation();

		return 0;
	}
