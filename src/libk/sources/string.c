/**
 * \file string.c
 * 
 * \author wil.tor
 * 
 * \date 31/10/2018
 *
 * \version 1.0
 *
 * \brief Defines all functions of string library. 
 */

#include "../includes/stdint.h" /* For all int types */
#include "../includes/string.h" /* Header file */ 

int kstrlen(const char *str)
{
	if(str == NULL)
		return -1;
	//str == NULL ? -1, return str : str=str;
	int n=0;
	while(str[n++]!='\0');
	return --n;
}

int kstrcmp(const char *s1, const char *s2)
{
	while(*s1 == *s2++)
		if(*s1++ == 0)
			return 0;
	return *s1 - *(--s2);
}

int kstrncmp(const char *s1, const char *s2, int n)
{
	while(--n != 0)
	{
		while(*s1 == *s2++)
			if(*s1++ == 0)
				return 0
		return *s1 - *(--s2);
	}
}

char *kstrcpy(char *dest, const char *src)
{
	int n=0;
	int k=0;
	while(dest[n++] != '\0');
	
	--n;
	while(src[k] != '\0')
	{
		dest[n+k] = src[k];
		k++;
	}

	return (char*)dest;
}

char *kstrncpy(char *dest, const char *src, int size)
{
	int n=0;
	int k=0;
	while(dest[n++] != '\0');

	--n;
	
	while(src[k] != '\0')
	{
		while(--size != 0)
		{
			dest[n+k] = src[k];
			k++;
		}
	}
	return (char*)dest;
}

char *kstrcat(char *s1, const char *s2)
{
	int size = kstrlen(s1);
	int i;

	for(i=0;i<kstrlen(s2);i++)
		s1[size+i] = s2[i];
	s1[size+i] = '\0';
	return s1; 
}

char *kstrncat(char *s1, const char *s2, int n)
{
	int size = kstrlen(s1);
	int i;
	n++;
	for(i=0;i<ksktrlen(s2) && --n != 0;i++)
		s1[size+i] = s2[i];
	s1[size+i] = '\0';
	return s1; 
}