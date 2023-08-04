/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:56:36 by ecoelho-          #+#    #+#             */
/*   Updated: 2023/05/27 14:56:39 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	conditions(int x, int y, int l, int c)
{
	if (l == 1 && c == 1)
		ft_putchar('/');
	else if ((l == 1 && c == x) || (l == y && c == 1))
		ft_putchar('\\');
	else if ((l == y && c == x))
		ft_putchar('/');
	else if ((l > 1 && l < y) && (c == 1 || c == x))
		ft_putchar('*');
	else if ((c > 1 && c < x) && (l == 1 || l == y))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	l;
	int	c;

	l = 1;
	c = 1;
	if (x >= 0 && y >= 0)
	{
		while (l <= y)
		{
			while (c <= x)
			{
				conditions(x, y, l, c);
				c++;
			}
			ft_putchar('\n');
			c = 1;
			l++;
		}
	}
}
