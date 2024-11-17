/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfunc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:29:47 by mpisani           #+#    #+#             */
/*   Updated: 2024/11/17 17:31:48 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_error(void)
{
	ft_putstr("Error\n");
	return (0);
}
