/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:58:33 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/10 15:15:26 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespace(const char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0);
}
