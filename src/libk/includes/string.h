/**
 * \file string.h
 * 
 * \author wil.tor
 * 
 * \date 31/10/2018
 *
 * \version 1.0
 *
 * \brief Defines all functions of string library. 
 */

#ifndef STRING_H
#define STRING_H

#include "stdint.h" /* For all int types */

/**********************************************************************
 * FUNCTIONS
 *********************************************************************/

char 			*kstrcpy(char *dest, char *src);
char 			*kstrncpy(char *dest, char *src, int n);
char 			*kstrcat(char *dest, const char *src);
char			*kstrncat(char *dest, const char *src, int n);;
int		 		*kstrcmp(const char *s1, const char *s2);
int 			*kstrncmp(const char *s1, const char *s2, int n);
int				kstrlen(const char *str);

#endif /* STRING_H */