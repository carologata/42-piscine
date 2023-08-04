/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:24:26 by cogata            #+#    #+#             */
/*   Updated: 2023/06/11 22:24:30 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void			ft_error(void);
void			ft_get_key_desc(unsigned int result, char *buffer);
void			ft_init_key(unsigned int *key, char *buffer);
void			ft_init_desc(char **desc, char *buffer);
unsigned int	ft_atoi(char *str);
void			ft_compare(unsigned int result, unsigned int *key, char **desc);

void	ft_data(unsigned int result, char *path)
{
	int				fd;
	char			buffer[4096];
	int				file_size;
	unsigned int	key[500];
	char			**desc;
	int				i;

	desc = malloc(500 * sizeof(char *));
	i = 0;
	while (i < 500)
	{
		desc[i] = malloc(500 * sizeof(char));
		i++;
	}
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		file_size = read(fd, buffer, 4096);
		ft_init_key(key, buffer);
		ft_init_desc(desc, buffer);
		close(fd);
		buffer[file_size] = '\0';
		ft_compare(result, key, desc);
	}
	else
		ft_error();
	free(desc);
}

void	ft_init_key(unsigned int *key, char *buffer)
{
	char	char_key[500][500];
	int		i;
	int		index_row;
	int		index_col;

	i = 0;
	index_row = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] >= '0' && buffer[i] <= '9')
		{
			index_col = 0;
			char_key[index_row][index_col] = buffer[i];
			index_col = 1;
			while (buffer[i + index_col] >= '0' && buffer[i + index_col] <= '9')
			{
				char_key[index_row][index_col] = buffer[i + index_col];
				index_col++;
			}
			key[index_row] = ft_atoi(&char_key[index_row][0]);
			i = i + index_col - 1;
			index_row++;
		}
		i++;
	}
}

void	ft_init_desc(char **desc, char *buffer)
{
	int	i;
	int	index_row;
	int	index_col;

	i = 0;
	index_row = 0;
	while (buffer[i] != '\0')
	{
		if ((buffer[i] >= 32 && buffer[i] <= 126))
		{
			if (buffer[i] > 58)
			{
				index_col = 0;
				desc[index_row][index_col] = buffer[i];
				index_col = 1;
				while (buffer[i + index_col] >= 'a' && buffer[i
					+ index_col] <= 'z')
				{
					desc[index_row][index_col] = buffer[i + index_col];
					index_col++;
				}
				i = i + index_col - 1;
				index_row++;
			}
		}
		i++;
	}
}
	// while (buffer[i] != '\0')
	// {
	//     if ((buffer[i] >= 32 && buffer[i] <= 126))
	//     {
	//         if(buffer[i] == ':')
	//             found_separator = 1;
	//         if (buffer[i] != 32 && buffer[i] != ':' && found_separator == 1)
	//         {
	//             index_col = 0;
	//             found_separator = 0;
	//             desc[index_row][index_col] = buffer[i];
	//             index_col = 1;
	//             while (buffer[i + index_col] >= 32 && buffer[i
	//	+ index_col] <= 126 && buffer[i + index_col] != '\n')
	//             {
	//                 desc[index_row][index_col] = buffer[i + index_col];
	//                 index_col++;
	//             }
	//             i = i + index_col - 1;
	//             index_row++;
	//         }
	//     }
	//     i++;
	// }

