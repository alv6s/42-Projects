/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:13:46 by pevieira          #+#    #+#             */
/*   Updated: 2023/04/20 15:54:33 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	if (c == '\0')
		p = (char *)s + ft_strlen(s);
	else
	{
		while (*s != '\0')
		{
			if (*s == c)
				p = (char *)s;
			s++;
		}
	}
	return (p);
}
