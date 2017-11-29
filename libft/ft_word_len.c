/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:52:19 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/10 15:15:10 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_len(char const *s, char c)
{
	size_t len;

	if (s == NULL || c == '\0')
		return (0);
	len = 0;
	while (ft_iswhitespace(*s))
		s++;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
