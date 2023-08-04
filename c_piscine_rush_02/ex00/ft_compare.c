/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:24:02 by cogata            #+#    #+#             */
/*   Updated: 2023/06/11 22:24:04 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_look_for(unsigned int result, unsigned int *key, char **desc);

void	ft_compare(unsigned int result, unsigned int *key, char **desc)
{
	unsigned int	x;
	unsigned int	divider;

	if (result == 0)
	{
		ft_look_for(result, key, desc);
	}
	while (result != 0)
	{
		if (result > 1000000000 && result < 4294967295)
		{
			divider = 1000000000;
			x = result / divider;
			if (x > 9)
				ft_compare(x, key, desc);
			else
				ft_look_for(x, key, desc);
			ft_look_for(divider, key, desc);
			result = result % divider;
		}
		else if (result == 1000000000)
		{
			ft_look_for(result, key, desc);
		}
		else if (result > 1000000 && result < 1000000000)
		{
			divider = 1000000;
			x = result / divider;
			if (x > 9)
				ft_compare(x, key, desc);
			else
				ft_look_for(x, key, desc);
			ft_look_for(divider, key, desc);
			result = result % divider;
		}
		else if (result == 1000000)
		{
			ft_look_for(result, key, desc);
		}
		else if (result > 1000 && result < 1000000)
		{
			divider = 1000;
			x = result / divider;
			if (x > 9)
				ft_compare(x, key, desc);
			else
				ft_look_for(x, key, desc);
			ft_look_for(divider, key, desc);
			result = result % divider;
		}
		else if (result == 1000)
		{
			ft_look_for(result, key, desc);
		}
		else if (result > 100 && result < 1000)
		{
			divider = 100;
			x = result / divider;
			ft_look_for(x, key, desc);
			ft_look_for(divider, key, desc);
			result = result % divider;
		}
		else if (result == 100)
		{
			ft_look_for(result, key, desc);
		}
		else if (result > 20 && result < 100)
		{
			divider = result / 10;
			x = divider * 10;
			ft_look_for(x, key, desc);
			result = result % 10;
		}
		else if (result <= 20)
		{
			ft_look_for(result, key, desc);
			result = 0;
		}
	}
}
