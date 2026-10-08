/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiakhel <smiakhel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:28:21 by smiakhel          #+#    #+#             */
/*   Updated: 2026/09/19 22:34:27 by smiakhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

/*
 * it is static function only be used inside this rush.c file
 * it used only to print pattern trangle
 * output based on arguments / parameters 5,3 
 * o---o
 * |   |
 * o---o
 * 2nd function rush takes 2 arguments and loops through it like rows and cols
 * safe guard is there for taking care of negatives values and skip it 
*/
static void	ft_print_pattern(int row, int col, int width, int length)
{
	if ((row == 0 && col == 0) || (row == 0 && col == width -1)
		|| (row == length -1 && col == 0)
		|| (row == length -1 && col == width -1))
		ft_putchar('o');
	else if ((row > 0 && row < length -1) && (col == 0 || col == width -1))
		ft_putchar('|');
	else if ((row > 0 && row < length -1) && (col > 0 || col == width -1))
		ft_putchar(' ');
	else
		ft_putchar('-');
}

void	rush(int x, int y)
{
	int	rows;
	int	cols;

	if (y < 0 || x < 0)
	{
		write(1, "Invalid arguments passed try positive numbers\n", 47);
		return ;
	}
	rows = 0;
	while (rows < y)
	{
		cols = 0;
		while (cols < x)
		{
			ft_print_pattern(rows, cols, x, y);
			cols++;
		}
		write(1, "\n", 2);
		rows++;
	}
}
