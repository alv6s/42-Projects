/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:08:09 by pevieira          #+#    #+#             */
/*   Updated: 2023/04/19 18:58:06 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destcast;
	unsigned const char	*srccast;

	destcast = (unsigned char *) dest;
	srccast = (unsigned const char *) src;
	while (n-- > 0)
		*destcast++ = *srccast++;
	return (dest);
}
