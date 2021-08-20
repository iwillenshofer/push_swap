/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:58:40 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/20 18:29:19 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** modified version of ft_strcmp. Returns true if identical.
*/

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (FALSE);
		i++;
	}
	if (s1[i] == s2[i])
		return (TRUE);
	return (FALSE);
}

int checker_validate_ops(char **ops)
{
	int i;
	int j;
	int valid;
	char operator[4];

	operator[3] = '\0';
	i = 0;
	while (ops[i])
	{
		j = 0;
		valid = FALSE;
		while (VALID_OPS[j])
		{
			operator[0] = VALID_OPS[j];
			operator[1] = VALID_OPS[j + 1];
			operator[2] = VALID_OPS[j + 2];
			if (ft_strcmp(ops[i], operator))
				valid = TRUE;
			j += 4;
		}
		if (!(valid))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
