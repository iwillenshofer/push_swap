/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker_gnl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 22:18:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/21 17:56:13 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**read_stdin(void)
{
	char	buffer[1];
	char	*str;
	char	**ops;

	str = (char *)malloc(sizeof(char) * 1);
	str[0] = '\0';
	while (read(0, buffer, 1))
		str = ft_addchar(str, buffer[0]);
	ops = string_to_operators(str);
	free(str);
	return (ops);
}
