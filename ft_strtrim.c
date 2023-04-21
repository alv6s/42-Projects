/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:28:09 by pevieira          #+#    #+#             */
/*   Updated: 2023/04/21 17:49:12 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t    ft_check(char const *character, char const *set)
{
    size_t    i;

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
    size_t    i;
    char    *newstr;
    size_t    lenght;

    i = 0;
    lenght = ft_strlen(s1);
    newstr = (char *) malloc(sizeof(char) * (lenght + 1));
    if (!newstr)
        return (NULL);
    while (*s1)
    {
        if(ft_check(s1, set) == 1)
            s1++;
        else
        {    
            newstr[i] = *s1;
            s1++;
            i++;
        }
    }
    newstr[i] = '\0';
    return (newstr);
}