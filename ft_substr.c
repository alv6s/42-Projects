/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:28:30 by pedroalves        #+#    #+#             */
/*   Updated: 2023/04/21 13:20:13 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char            *sub;
    unsigned int    i;
    
    i = 0;
    sub = (char *) malloc(sizeof(char) * (len + 1));
    if (!sub)
        return (NULL);
    while (i < len && s[start + i] != '\0')
    {
       sub[i] = s[start + i];
       i++;
    }
    sub[i] = '\0';
    return (sub);
}