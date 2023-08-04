/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:23:20 by jaqribei          #+#    #+#             */
/*   Updated: 2023/06/11 16:37:38 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_error(void);
char	ft_is_digit(char *str);

char	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_error();
			return ('f');
		}
		i++;
	}
	return ('t');
}

void	ft_error(void)
{
	write(1, "error\n", 6);
}
