/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:21:36 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/17 13:40:01 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main()
{
	
/* -----------------------------------------------------------------------------
** 						%c CHARS TESTS
** ---------------------------------------------------------------------------*/

	printf("-------------------\n");
	printf(" %%c CHARS TESTS\n");
	printf("-------------------\n");

	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", ' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1',':',';','<','=','>','?','@','A','B','[','\\',']','^','_','`','a','b','{','|','}','~','');
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", ' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1',':',';','<','=','>','?','@','A','B','[','\\',']','^','_','`','a','b','{','|','}','~','');
	
	printf("------------------------------\n");
	
	ft_printf("%c%c%c%c%c\n", 35, 40, 45, 50, 55);
	printf("%c%c%c%c%c\n", 35, 40, 45, 50, 55);

	printf("------------------------------\n");
	
	ft_printf("|%1c|%2c|%3c|%4c|%5c|\n", 'a', 'a', 'a', 'a', 'a');
	printf("|%1c|%2c|%3c|%4c|%5c|\n", 'a', 'a', 'a', 'a', 'a');

	printf("------------------------------\n");

	ft_printf("|%-1c|%-2c|%-3c|%-4c|%-5c|\n", 'a', 'a', 'a', 'a', 'a');
	printf("|%-1c|%-2c|%-3c|%-4c|%-5c|\n", 'a', 'a', 'a', 'a', 'a');

	printf("\n\n");
	
/* -----------------------------------------------------------------------------
** 						%s STRING TESTS
** ---------------------------------------------------------------------------*/

	printf("-------------------\n");
	printf(" %%s STRING TESTS\n");
	printf("-------------------\n");

	ft_printf("%s%s%s%s%s\n", "bonjour ", "salut ", "tout ", "le ", "monde ");
	printf("%s%s%s%s%s\n", "bonjour ", "salut ", "tout ", "le ", "monde ");

	printf("------------------------------\n");
	
	ft_printf("%11s%12s%13s%14s%15s\n", "bonjour ", "salut ", "tout ", "le ", "monde ");
	printf("%11s%12s%13s%14s%15s\n", "bonjour ", "salut ", "tout ", "le ", "monde ");

	printf("------------------------------\n");
	
	ft_printf("%-11s%-12s%-13s%-14s%-15s\n", "bonjour ", "salut ", "tout ", "le ", "monde ");
	printf("%-11s%-12s%-13s%-14s%-15s\n", "bonjour ", "salut ", "tout ", "le ", "monde ");
	
	printf("------------------------------\n");
		
	ft_printf("%.2s %.2s %.2s %.2s %.2s\n", "bonjour ", "salut ", "tout ", "le ", "monde ");
	printf("%.2s %.2s %.2s %.2s %.2s\n", "bonjour ", "salut ", "tout ", "le ", "monde ");

	printf("------------------------------\n");
	
	ft_printf("|%11.5s|%12.5s|%13.5s|%14.5s|%15.5s|\n", "bonjour ", "salut ", "tout", "le ", "monde ");
	printf("|%11.5s|%12.5s|%13.5s|%14.5s|%15.5s|\n", "bonjour ", "salut ", "tout", "le ", "monde ");

	printf("------------------------------\n");
	
	ft_printf("%s\n", NULL);
	printf("%s\n", NULL);

	printf("------------------------------\n");
	
	ft_printf("%.s\n", "bonjour");
	printf("%.s\n", "bonjour");
	
	printf("------------------------------\n");
	
	ft_printf("%.0s\n", "bonjour");
	printf("%.0s\n", "bonjour");
	
	printf("\n\n");

/* -----------------------------------------------------------------------------
** 						%d INTEGER TESTS
** ---------------------------------------------------------------------------*/

	printf("-------------------\n");
	printf(" %%d INTEGER TESTS\n");
	printf("-------------------\n");

	ft_printf("%d %d %d %d %d\n", 0, 15, -15, 2147483647, -2147483678);
	printf("%d %d %d %d %d\n", 0, 15, -15, 2147483647, -2147483678);

	printf("------------------------------\n");
	
	ft_printf("%10d %10d %10d\n", 0, 15, -15);
	printf("%10d %10d %10d\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%.10d %.10d %.10d\n", 0, 15, -15);
	printf("%.10d %.10d %.10d\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%010d %010d %010d\n", 0, 15, -15);
	printf("%010d %010d %010d\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%010.5d %010.5d %010.5d\n", 0, 15, -15);
	printf("%010.5d %010.5d %010.5d\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%0.10d %0.10d %0.10d\n", 0, 15, -15);
	printf("%0.10d %0.10d %0.10d\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%-10d %-10d %-10d\n", 0, 15, -15);
	printf("%-10d %-10d %-10d\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%10.5d %10.5d %10.5d\n", 0, 15, -15);
	printf("%10.5d %10.5d %10.5d\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%0-10d %0-10d %0-10d\n", 0, 15, -15);
	printf("%0-10d %0-10d %0-10d\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%.d\n", 0);
	printf("%.d\n", 0);
	
	printf("------------------------------\n");
	
	ft_printf("%.0d\n", 0);
	printf("%.0d\n", 0);

	printf("\n\n");
	
/* -----------------------------------------------------------------------------
** 						%i INTEGER TESTS
** ---------------------------------------------------------------------------*/

	printf("-------------------\n");
	printf(" %%i INTEGER TESTS\n");
	printf("-------------------\n");

	ft_printf("%i %i %i %i %i\n", 0, 15, -15, 2147483647, -2147483678);
	printf("%i %i %i %i %i\n", 0, 15, -15, 2147483647, -2147483678);

	printf("------------------------------\n");
	
	ft_printf("%10i %10i %10i\n", 0, 15, -15);
	printf("%10i %10i %10i\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%.10i %.10i %.10i\n", 0, 15, -15);
	printf("%.10i %.10i %.10i\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%010i %010i %010i\n", 0, 15, -15);
	printf("%010i %010i %010i\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%010.5i %010.5i %010.5i\n", 0, 15, -15);
	printf("%010.5i %010.5i %010.5i\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%0.10i %0.10i %0.10i\n", 0, 15, -15);
	printf("%0.10i %0.10i %0.10i\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%-10i %-10i %-10i\n", 0, 15, -15);
	printf("%-10i %-10i %-10i\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%10.5i %10.5i %10.5i\n", 0, 15, -15);
	printf("%10.5i %10.5i %10.5i\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%0-10i %0-10i %0-10i\n", 0, 15, -15);
	printf("%0-10i %0-10i %0-10i\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%.i\n", 0);
	printf("%.i\n", 0);
	
	printf("------------------------------\n");
	
	ft_printf("%.0i\n", 0);
	printf("%.0i\n", 0);

	printf("\n\n");
	
/* -----------------------------------------------------------------------------
** 						%u UNSIGNED INTEGERS TESTS
** ---------------------------------------------------------------------------*/

	printf("------------------------------\n");
	printf(" %%u UNSIGNED INTEGERS TESTS\n");
	printf("------------------------------\n");

	ft_printf("%u %u %u %u %u\n", 0, 15, -15, 2147483647, -2147483678);
	printf("%u %u %u %u %u\n", 0, 15, -15, 2147483647, -2147483678);

	printf("------------------------------\n");
	
	ft_printf("%10u %10u %10u\n", 0, 15, -15);
	printf("%10u %10u %10u\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%.10u %.10u %.10u\n", 0, 15, -15);
	printf("%.10u %.10u %.10u\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%010u %010u %010u\n", 0, 15, -15);
	printf("%010u %010u %010u\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%010.5u %010.5u %010.5u\n", 0, 15, -15);
	printf("%010.5u %010.5u %010.5u\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%0.10u %0.10u %0.10u\n", 0, 15, -15);
	printf("%0.10u %0.10u %0.10u\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%-10u %-10u %-10u\n", 0, 15, -15);
	printf("%-10u %-10u %-10u\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%10.5u %10.5u %10.5u\n", 0, 15, -15);
	printf("%10.5u %10.5u %10.5u\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%0-10u %0-10u %0-10u\n", 0, 15, -15);
	printf("%0-10u %0-10u %0-10u\n", 0, 15, -15);

	printf("------------------------------\n");
	
	ft_printf("%.u\n", 0);
	printf("%.u\n", 0);
	
	printf("------------------------------\n");
	
	ft_printf("%.0u\n", 0);
	printf("%.0u\n", 0);
	
	printf("\n\n");

/* -----------------------------------------------------------------------------
** 						%x HEXADECIMAL LOWERS TESTS 
** ---------------------------------------------------------------------------*/

	printf("------------------------------\n");
	printf(" %%x HEXADECIMAL LOWERS TESTS \n");
	printf("------------------------------\n");

	ft_printf("%x %x %x %x %x %x %x %x %x %x %x\n", 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55);
	printf("%x %x %x %x %x %x %x %x %x %x %x\n", 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55);

	printf("------------------------------\n");
	
	ft_printf("%x %x %x %x %x\n", 0, 15, -15, 2147483647, -2147483678);
	printf("%x %x %x %x %x\n", 0, 15, -15, 2147483647, -2147483678);

	printf("------------------------------\n");
	
	ft_printf("%10x %10x %10x\n", 0, 150, -150);
	printf("%10x %10x %10x\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%.10x %.10x %.10x\n", 0, 150, -150);
	printf("%.10x %.10x %.10x\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%010x %010x %010x\n", 0, 150, -150);
	printf("%010x %010x %010x\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%010.5x %010.5x %010.5x\n", 0, 150, -150);
	printf("%010.5x %010.5x %010.5x\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%0.10x %0.10x %0.10x\n", 0, 150, -150);
	printf("%0.10x %0.10x %0.10x\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%-10x %-10x %-10x\n", 0, 150, -150);
	printf("%-10x %-10x %-10x\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%10.5x %10.5x %10.5x\n", 0, 150, -150);
	printf("%10.5x %10.5x %10.5x\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%0-10x %0-10x %0-10x\n", 0, 150, -150);
	printf("%0-10x %0-10x %0-10x\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%.x\n", 0);
	printf("%.x\n", 0);
	
	printf("------------------------------\n");
	
	ft_printf("%.0x\n", 0);
	printf("%.0x\n", 0);

	printf("\n\n");

/* -----------------------------------------------------------------------------
** 						%X HEXADECIMAL UPPERS TESTS 
** ---------------------------------------------------------------------------*/

	printf("------------------------------\n");
	printf(" %%X HEXADECIMAL UPPERS TESTS \n");
	printf("------------------------------\n");

	ft_printf("%X %X %X %X %X %X %X %X %X %X %X\n", 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55);
	printf("%X %X %X %X %X %X %X %X %X %X %X\n", 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55);

	printf("------------------------------\n");
	
	ft_printf("%X %X %X %X %X\n", 0, 15, -15, 2147483647, -2147483678);
	printf("%X %X %X %X %X\n", 0, 15, -15, 2147483647, -2147483678);

	printf("------------------------------\n");
	
	ft_printf("%10X %10X %10X\n", 0, 150, -150);
	printf("%10X %10X %10X\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%.10X %.10X %.10X\n", 0, 150, -150);
	printf("%.10X %.10X %.10X\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%010X %010X %010X\n", 0, 150, -150);
	printf("%010X %010X %010X\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%010.5X %010.5X %010.5X\n", 0, 150, -150);
	printf("%010.5X %010.5X %010.5X\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%0.10X %0.10X %0.10X\n", 0, 150, -150);
	printf("%0.10X %0.10X %0.10X\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%-10X %-10X %-10X\n", 0, 150, -150);
	printf("%-10X %-10X %-10X\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%10.5X %10.5X %10.5X\n", 0, 150, -150);
	printf("%10.5X %10.5X %10.5X\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%0-10X %0-10X %0-10X\n", 0, 150, -150);
	printf("%0-10X %0-10X %0-10X\n", 0, 150, -150);

	printf("------------------------------\n");
	
	ft_printf("%.x\n", 0);
	printf("%.x\n", 0);
	
	printf("------------------------------\n");
	
	ft_printf("%.0x\n", 0);
	printf("%.0x\n", 0);

	printf("\n\n");

/* -----------------------------------------------------------------------------
** 						%p POINTER TESTS 
** ---------------------------------------------------------------------------*/

	printf("------------------------------\n");
	printf(" %%p POINTER TESTS \n");
	printf("------------------------------\n");

	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;

	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);

	printf("------------------------------\n");
	
	ft_printf("%p %p %p %p %p %p %p %p %p %p %p %p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("%p %p %p %p %p %p %p %p %p %p %p %p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

	printf("------------------------------\n");
	
	ft_printf("%70p\n",&a01);
	printf("%70p\n", &a01);

	printf("------------------------------\n");
	
	ft_printf("%5p\n",&a02);
	printf("%5p\n",&a02);

	printf("------------------------------\n");
	
	ft_printf("%16p\n",&a03);
	printf("%16p\n",&a03);

	printf("------------------------------\n");
	
	ft_printf("%8p\n",&a04);
	printf("%8p\n",&a04);
	
	printf("------------------------------\n");
		
	ft_printf("%32p\n",&a05);
	printf("%32p\n",&a05);

	printf("------------------------------\n");
	
	ft_printf("%032p\n",&a05);
	printf("%032p\n",&a05);

	printf("------------------------------\n");
	
	ft_printf("%.70p\n",&a01);
	printf("%.70p\n", &a01);

	printf("------------------------------\n");
	
	ft_printf("%.5p\n",&a02);
	printf("%.5p\n",&a02);

	printf("------------------------------\n");
	
	ft_printf("%.16p\n",&a03);
	printf("%.16p\n",&a03);

	printf("------------------------------\n");
	
	ft_printf("%.8p\n",&a04);
	printf("%.8p\n",&a04);
	
	printf("------------------------------\n");
		
	ft_printf("%.32p\n",&a05);
	printf("%.32p\n",&a05);

	printf("------------------------------\n");
	
	ft_printf("%-70p|\n",&a06);
	printf("%-70p|\n",&a06);

	printf("------------------------------\n");
	
	ft_printf("%-5p|\n",&a07);
	printf("%-5p|\n",&a07);

	printf("------------------------------\n");
	
	ft_printf("%-16p|\n",&a08);
	printf("%-16p|\n",&a08);

	printf("------------------------------\n");
	
	ft_printf("%-8p|\n",&a09);
	printf("%-8p|\n",&a09);

	printf("------------------------------\n");
	
	ft_printf("%-32p|\n",&a10);
	printf("%-32p|\n",&a10);

	printf("\n\n");

/* -----------------------------------------------------------------------------
** 						OTHER TESTS
** ---------------------------------------------------------------------------*/

	printf("------------------------------\n");
	printf(" 	OTHER TESTS \n");
	printf("------------------------------\n");
	
	ft_printf("%%\n");
	printf("%%\n");
	
	printf("------------------------------\n");
	
	ft_printf("%.10%\n");
	printf("%.10%\n");

	printf("------------------------------\n");
	
	ft_printf("%010%\n");
	printf("%010%\n");

	printf("------------------------------\n");
	
	ft_printf("%10%\n");
	printf("%10%\n");

	printf("------------------------------\n");
	
	ft_printf("%-10%|\n");
	printf("%-10%|\n");

	printf("------------------------------\n");
	
	ft_printf("%-010%|\n");
	printf("%-010%|\n");

	printf("\n\n");

/* -----------------------------------------------------------------------------
** 							MOULINETTE TESTS
** ---------------------------------------------------------------------------*/

	printf("------------------------------\n");
	printf(" 	MOULINETTE TESTS \n");
	printf("------------------------------\n");

	printf("%%c tests\n\n");

	ft_printf("%c\n", 42);
	printf("%c\n", 42);

	printf("------------------------------\n");

	ft_printf("Kashim a %c histoires à raconter\n", 1001);
	printf("Kashim a %c histoires à raconter\n", 1001);

	printf("------------------------------\n");

	ft_printf("Il fait au moins %c\n", -8000);
	printf("Il fait au moins %c\n", -8000);

	printf("------------------------------\n");

	ft_printf("%c|\n", -0);
	printf("%c|\n", -0);

	printf("------------------------------\n");

	ft_printf("%c|\n", 0);
	printf("%c|\n", 0);

	printf("------------------------------\n");

	ft_printf("%c\n", 2147483647);
	printf("%c\n", 2147483647);

	printf("------------------------------\n");

	ft_printf("%c\n", -2147483648);
	printf("%c\n", -2147483648);

	printf("------------------------------\n");

	ft_printf("%c\n", 'c');
	printf("%c\n", 'c');

	printf("------------------------------\n");

	ft_printf("%c", '\n');
	printf("%c", '\n');

	printf("------------------------------\n");

	ft_printf("%c\n", 'l');
	printf("%c\n", 'l');

	printf("------------------------------\n");

	ft_printf("%c\n", '\r');
	printf("%c\n", '\r');

	printf("------------------------------\n");

	ft_printf("%c\n", '\t');
	printf("%c\n", '\t');

	printf("\n %%s tests\n\n");

	ft_printf(" pouet %s !!\n", "camembert");
	printf(" pouet %s !!\n", "camembert");

	printf("------------------------------\n");

	ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
	printf("%s !\n", "Ceci n'est pas un \0 exercice !");

	printf("------------------------------\n");

	ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
	printf("%s!\n", "Ceci n'est toujours pas un exercice !");

	printf("------------------------------\n");

	ft_printf("%s!\n", NULL);
	printf("%s!\n", NULL);

	printf("\n %%d tests\n\n");

	ft_printf("%d\n", 42);
	printf("%d\n", 42);

	printf("------------------------------\n");

	ft_printf("%d\n", -0);
	printf("%d\n", -0);

	printf("------------------------------\n");

	ft_printf("%d\n", 2147483647);
	printf("%d\n", 2147483647);

	printf("------------------------------\n");

	ft_printf("%d\n", -2147483648);
	printf("%d\n", -2147483648);

	printf("------------------------------\n");

	ft_printf("%d\n", 2147483647 + 1);
	printf("%d\n", 2147483647 + 1);

	printf("------------------------------\n");

	ft_printf("%d\n", -2147483648 - 1);
	printf("%d\n", -2147483648 - 1);

	printf("------------------------------\n");

	ft_printf("%%d 0000042 == |%d|\n", 0000042);
	printf("%%d 0000042 == |%d|\n", 0000042);

	printf("------------------------------\n");

	ft_printf("%%d \t == |%d|\n", '\t');
	printf("%%d \t == |%d|\n", '\t');

	printf("------------------------------\n");

	ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
	printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');

	printf("\n %%i tests\n\n");

	ft_printf("%i\n", 42);
	printf("%i\n", 42);

	printf("------------------------------\n");

	ft_printf("%i\n", -0);
	printf("%i\n", -0);

	printf("------------------------------\n");

	ft_printf("%i\n", 2147483647);
	printf("%i\n", 2147483647);

	printf("------------------------------\n");

	ft_printf("%i\n", -2147483648);
	printf("%i\n", -2147483648);

	printf("------------------------------\n");

	ft_printf("%i\n", 2147483647 + 1);
	printf("%i\n", 2147483647 + 1);

	printf("------------------------------\n");

	ft_printf("%i\n", -2147483648 - 1);
	printf("%i\n", -2147483648 - 1);

	printf("------------------------------\n");

	ft_printf("%%i 0000042 == |%i|\n", 0000042);
	printf("%%i 0000042 == |%i|\n", 0000042);

	printf("------------------------------\n");

	ft_printf("%%i \t == |%i|\n", '\t');
	printf("%%i \t == |%i|\n", '\t');

	printf("------------------------------\n");

	ft_printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');
	printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');

	printf("\n %%x tests\n\n");

	ft_printf("%x\n", 42);
	printf("%x\n", 42);

	printf("------------------------------\n");

	ft_printf("Kashim a %x histoires à raconter\n", 1001);
	printf("Kashim a %x histoires à raconter\n", 1001);

	printf("------------------------------\n");

	ft_printf("Il fait au moins %x\n", -8000);
	printf("Il fait au moins %x\n", -8000);

	printf("------------------------------\n");

	ft_printf("%x\n", -0);
	printf("%x\n", -0);

	printf("------------------------------\n");

	ft_printf("%x\n", 0);
	printf("%x\n", 0);

	printf("------------------------------\n");

	ft_printf("%x\n", 2147483647);
	printf("%x\n", 2147483647);

	printf("------------------------------\n");

	ft_printf("%x\n", -2147483648);
	printf("%x\n", -2147483648);

	printf("------------------------------\n");

	ft_printf("%x\n", 2147483647 + 1);
	printf("%x\n", 2147483647 + 1);

	printf("------------------------------\n");

	ft_printf("%x\n", -2147483648 - 1);
	printf("%x\n", -2147483648 - 1);

	printf("------------------------------\n");

	ft_printf("%%x 0000042 == |%x|\n", 0000042);
	printf("%%x 0000042 == |%x|\n", 0000042);

	printf("------------------------------\n");

	ft_printf("%%x \t == |%x|\n", '\t');
	printf("%%x \t == |%x|\n", '\t');

	printf("------------------------------\n");

	ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');

	printf("\n other tests\n\n");

	ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");

	printf("------------------------------\n");

	ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
	printf("%%04.5i 42 == |%04.5i|\n", 42);

	printf("------------------------------\n");

	ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	printf("%%04.3i 42 == |%04.3i|\n", 42);

	printf("------------------------------\n");

	ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	printf("%%04.2i 42 == |%04.2i|\n", 42);

	printf("------------------------------\n");

	ft_printf("%%04i 42 == |%04i|\n", 42);
	printf("%%04i 42 == |%04i|\n", 42);

	printf("------------------------------\n");

	ft_printf("%%05i 42 == |%05i|\n", 42);
	printf("%%05i 42 == |%05i|\n", 42);

	printf("------------------------------\n");

	ft_printf("%%0i 42 == |%0i|\n", 42);
	printf("%%0i 42 == |%0i|\n", 42);

	printf("------------------------------\n");

	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);
	printf("%%0d 0000042 == |%0d|\n", 0000042);

	printf("------------------------------\n");

	ft_printf("%%-i 42 == %-i\n", 42);
	printf("%%-i 42 == %-i\n", 42);

	printf("------------------------------\n");

	ft_printf("%%-d 42 == %-d\n", -2147483648);
	printf("%%-d 42 == %-d\n", -2147483648);

	printf("------------------------------\n");

	ft_printf("%%-i -42 == %-i\n", -42);
	printf("%%-i -42 == %-i\n", -42);

	printf("------------------------------\n");

	ft_printf("%%-4d 42 == |%-4d|\n", 42);
	printf("%%-4d 42 == |%-4d|\n", 42);

	printf("------------------------------\n");

	ft_printf("%%-5d -42 == |%-5d|\n", -42);
	printf("%%-5d -42 == |%-5d|\n", -42);

	printf("------------------------------\n");

	ft_printf("|%3i|%-3i|\n", 42, 42);
	printf("|%3i|%-3i|\n", 42, 42);

	printf("------------------------------\n");

	ft_printf("%%-4i 42 == |%-4i|\n", 42);
	printf("%%-4i 42 == |%-4i|\n", 42);

	printf("------------------------------\n");

	printf("\n\n");
	/*
	printf("------------------------------\n");
	printf("|%*.*x|\n", 50, 10, 2);
	ft_printf("|%*.*x|\n", 50, 10, 2);
	*/
}