/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:28:09 by pevieira          #+#    #+#             */
/*   Updated: 2023/04/22 14:46:53 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(char const *character, char const *set)
{
	while (*set)
	{
		if (*character == *set)
			return (1);
		else
			set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	char	*newstr;
	size_t	finish;
	size_t	i;

	i = 0;
	start = 0;
	finish = ft_strlen(s1) - 1;
	while (ft_check(&s1[start], set) == 1)
		start++;
	while (ft_check(&s1[finish], set) == 1)
		finish--;
	newstr = (char *) malloc(sizeof(char) * (finish - start + 2));
	if (!newstr || !set)
		return (NULL);
	while (start <= finish)
		newstr[i++] = s1[start++];
	newstr[i] = '\0';
	return (newstr);
}
