/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:08:11 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/17 19:43:14 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			ft_isdigitand(int c)
{
	return ((ft_isdigit(c) || c == '-' || c == '+'));
}