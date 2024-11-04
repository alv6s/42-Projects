/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:03:19 by pedroalves        #+#    #+#             */
/*   Updated: 2024/10/29 13:38:15 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*together;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	together = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!together)
		return (NULL);
	ft_memcpy(together, s1, len1);
	ft_memcpy(together + len1, s2, len2);
	together[len1 + len2] = '\0';
	free((char *)s1);
	return (together);
}
