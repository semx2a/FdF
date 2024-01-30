/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:44:12 by seozcan           #+#    #+#             */
/*   Updated: 2024/01/29 19:27:37 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "ft_printf.h"

int main(void)
{
	int		selection;
	int		ret = 0;
	
	char	c;
	char	*str;
	void	*ptr;
	
	char	nullc;
	char	*nullstr;
	void	*nullptr;

	c = 'p';
	str = "this is a string";
	ptr = &str;
	
	nullc = '\0';
	nullstr = NULL;
	nullptr = &nullstr;

	while (1)
	{

		selection = -1;
		
		printf("\nWelcome to the ft_printf tester!\n");
		printf("Select the number of the type of conversion you want to test:\n");
		printf("1. %%c\n");
		printf("2. %%s\n");
		printf("3. %%p\n");
		printf("4. %%d\n");
		printf("5. %%i\n");
		printf("6. %%u\n");
		printf("7. %%x\n");
		printf("8. %%X\n");
		printf("9. %%%%\n");
		printf("0. Exit\n");
		printf("Enter your choice: ");
		ret = scanf("%d", &selection);
		
		// Clear input buffer if invalid input
		if (ret != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) { }
		}
		
		printf("\nYou selected: %d\n\n", selection);

		if (ret == 1 && selection >= 0 && selection <= 9) {
			
			switch (selection)
			{
				case 1:
					//	-----------------------------------C-------------------------------------
					printf("ft_printf output for char:\n");
					ft_printf("%c", c);
					fputc('\n', stdout);
					ft_printf("%c", 79);
					fputc('\n', stdout);
					ft_printf("%c", 59);
					fputc('\n', stdout);
					ft_printf("%c", 70);
					fputc('\n', stdout);
					ft_printf("%c", 50);
					fputc('\n', stdout);
					ft_printf("%c", 121);
					fputc('\n', stdout);
					ft_printf("%c", nullc);
					fputc('\n', stdout);
		
					printf("\nprintf output for char:\n");
					printf("%c\n", c);
					printf("%c\n", 79);
					printf("%c\n", 59);
					printf("%c\n", 70);
					printf("%c\n", 50);
					printf("%c\n", 121);
					printf("%c\n", nullc);
					break ;
		
				case 2:
					//	-----------------------------------S-------------------------------------
					printf("ft_printf output for str:\n");
					ft_printf("%s", str);
					fputc('\n', stdout);
					ft_printf("%s", nullstr);
					fputc('\n', stdout);
					ft_printf(" NULL %s NULL", nullstr);
					fputc('\n', stdout);
					ft_printf(" %s %s %s %s %s", " - ", "", "4", "", "2 ");
					fputc('\n', stdout);
					
					printf("\nprintf output for str:\n");
					printf("%s\n", str);
					printf("%s\n", nullstr);
					printf(" NULL %s NULL\n", nullstr);
					printf(" %s %s %s %s %s\n", " - ", "", "4", "", "2 ");
					break ;
				case 3:
					//-----------------------------------P-------------------------------------
					printf("ft_printf output for ptr:\n");
					ft_printf("[0]: %p", ptr);
					fputc('\n', stdout);
					ft_printf("[1]: %p", nullptr);
					fputc('\n', stdout);
		
					printf("\nprintf output for ptr:\n");
					printf("[0]: %p\n", ptr);
					printf("[1]: %p\n", nullptr);
					break ;
				case 4:
					//	-----------------------------------D-------------------------------------
					printf("ft_printf output for decimal:\n");
					ft_printf("%d", 0);
					fputc('\n', stdout);
					ft_printf("%d", -1);
					fputc('\n', stdout);
					ft_printf("%d", 1);
					fputc('\n', stdout);
					ft_printf("%d", 9);
					fputc('\n', stdout);
					ft_printf("%d", 10);
					fputc('\n', stdout);
					ft_printf("%d", 11);
					fputc('\n', stdout);
					ft_printf("%d", 15);
					fputc('\n', stdout);
					ft_printf("%d", 16);
					fputc('\n', stdout);
					ft_printf("%d", 17);
					fputc('\n', stdout);
					ft_printf("%d", 99);
					fputc('\n', stdout);
					ft_printf("%d", 100);
					fputc('\n', stdout);
					ft_printf("%d", 101);
					fputc('\n', stdout);
					ft_printf("%d", -9);
					fputc('\n', stdout);
					ft_printf("%d", -10);
					fputc('\n', stdout);
					ft_printf("%d", -11);
					fputc('\n', stdout);
					ft_printf("%d", -15);
					fputc('\n', stdout);
					ft_printf("%d", -16);
					fputc('\n', stdout);
					ft_printf("%d", -17);
					fputc('\n', stdout);
					ft_printf("%d", -99);
					fputc('\n', stdout);
					ft_printf("%d", -100);
					fputc('\n', stdout);
					ft_printf("%d", -101);
					fputc('\n', stdout);
					ft_printf("%d", -2147483648);
					fputc('\n', stdout);
		
					printf("\nprintf output for decimal:\n");
					printf("%d\n", 0);
					printf("%d\n", -1);
					printf("%d\n", 1);
					printf("%d\n", 9);
					printf("%d\n", 10);
					printf("%d\n", 11);
					printf("%d\n", 15);
					printf("%d\n", 16);
					printf("%d\n", 17);
					printf("%d\n", 99);
					printf("%d\n", 100);
					printf("%d\n", 101);
					printf("%d\n", -9);
					printf("%d\n", -10);
					printf("%d\n", -11);
					printf("%d\n", -15);
					printf("%d\n", -16);
					printf("%d\n", -17);
					printf("%d\n", -99);
					printf("%d\n", -100);
					printf("%d\n", -101);
					printf("%ld\n", -2147483648);
					break ;
		
				case 5:
					//	-----------------------------------I-------------------------------------
					printf("ft_printf output for int:\n");
					ft_printf("%i", 0);
					fputc('\n', stdout);
					ft_printf("%i", -11);
					fputc('\n', stdout);
					ft_printf("%i", -1111111);
					fputc('\n', stdout);
		
					printf("\nprintf output for int:\n");
					printf("%i\n", 0);
					printf("%i\n", -11);
					printf("%i\n", -1111111);
					break ;
				case 6:
					//	-----------------------------------U-------------------------------------
					printf("ft_printf output for unsigned int:\n");
					ft_printf("%u", 0);
					fputc('\n', stdout);
					ft_printf("%u", -1);
					fputc('\n', stdout);
					ft_printf("%u", 1);
					fputc('\n', stdout);
					ft_printf("%u", 9);
					fputc('\n', stdout);
					ft_printf("%u", 10);
					fputc('\n', stdout);
					ft_printf("%u", 11);
					fputc('\n', stdout);
					ft_printf("%u", 15);
					fputc('\n', stdout);
					ft_printf("%u", 16);
					fputc('\n', stdout);
					ft_printf("%u", 17);
					fputc('\n', stdout);
					ft_printf("%u", 99);
					fputc('\n', stdout);
					ft_printf("%u", 100);
					fputc('\n', stdout);
					ft_printf("%u", 101);
					fputc('\n', stdout);
					ft_printf("%u", -9);
					fputc('\n', stdout);
					ft_printf("%u", -10);
					fputc('\n', stdout);
					ft_printf("%u", -11);
					fputc('\n', stdout);
					ft_printf("%u", -15);
					fputc('\n', stdout);
					ft_printf("%u", -16);
					fputc('\n', stdout);
					ft_printf("%u", -17);
					fputc('\n', stdout);
					ft_printf("%u", -99);
					fputc('\n', stdout);
					ft_printf("%u", -100);
					fputc('\n', stdout);
					ft_printf("%u", -101);
					fputc('\n', stdout);
					ft_printf("%u", 2147483647);
					fputc('\n', stdout);
		
					printf("\nprintf output for unsigned int:\n");
					printf("%u\n", 0);
					printf("%u\n", -1);
					printf("%u\n", 1);
					printf("%u\n", 9);
					printf("%u\n", 10);
					printf("%u\n", 11);
					printf("%u\n", 15);
					printf("%u\n", 16);
					printf("%u\n", 17);
					printf("%u\n", 99);
					printf("%u\n", 100);
					printf("%u\n", 101);
					printf("%u\n", -9);
					printf("%u\n", -10);
					printf("%u\n", -11);
					printf("%u\n", -15);
					printf("%u\n", -16);
					printf("%u\n", -17);
					printf("%u\n", -99);
					printf("%u\n", -100);
					printf("%u\n", -101);
					printf("%u\n", 2147483647);
					break ;
		
				case 7:
					//	-----------------------------------x-------------------------------------
					printf("ft_printf output for hexadecimal:\n");
					ft_printf("%x", 0);
					fputc('\n', stdout);
					ft_printf("%x", -1);
					fputc('\n', stdout);
					ft_printf("%x", 1);
					fputc('\n', stdout);
					ft_printf("%x", 42);
					fputc('\n', stdout);
					
					printf("\nprintf output hexadecimal:\n");
					printf("%x\n", 0);
					printf("%x\n", -1);
					printf("%x\n", 1);
					printf("%x\n", 42);
					break ;
				case 8:
					//	-----------------------------------X-------------------------------------
					printf("ft_printf output for HEXADECIMAL:\n");
					ft_printf("%X", 0);
					fputc('\n', stdout);
					ft_printf("%X", -1);
					fputc('\n', stdout);
					ft_printf("%X", 1);
					fputc('\n', stdout);
					ft_printf("%X", 42);
					fputc('\n', stdout);

					printf("\nprintf output for HEXADECIMAL:\n");
					printf("%X\n", 0);
					printf("%X\n", -1);
					printf("%X\n", 1);
					printf("%X\n", 42);
					break ;
		
				case 9:
					//	-----------------------------------%-------------------------------------
					printf("ft_printf output for %%:\n");
					ft_printf("%%");
					fputc('\n', stdout);
					ft_printf("%% %% %%");
					fputc('\n', stdout);
					//ft_printf("%"); /* error */
		
					printf("\nprintf output for %%:\n");
					printf("%%\n");
					printf("%% %% %%\n");
					//printf("%"); /* error */
					break ;
				case 0:
					printf("Exiting...\n");
					return (0);
				default:
					printf("Invalid input\n");
					break ;
			}
		}
	}
	return (0);
}