/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:56:17 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/21 17:59:34 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f'
		|| c == '\v' || c == '\r')
		return (TRUE);
	return (FALSE);
}

char	*ft_addchar(char *s1, char c)
{
	int		size;
	char	*s2;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (size + 2));
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[size] = c;
	s2[size + 1] = '\0';
	free(s1);
	return (s2);
}

char	**add_item(char **ops, char *item, size_t size)
{
	size_t	len;
	char	**tmp;
	size_t	i;

	len = 0;
	i = 0;
	while (ops[len])
		len++;
	tmp = (char **)malloc(sizeof(char *) * (len + 2));
	tmp[len + 1] = NULL;
	while (i < len)
	{
		tmp[i] = ops[i];
		i++;
	}
	tmp[i] = (char *)malloc(sizeof(char) * (size + 1));
	tmp[i][size] = '\0';
	len = 0;
	while (len < size)
	{
		tmp[i][len] = item[len];
		len++;
	}
	free(ops);
	return (tmp);
}

int	array_lenght(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**string_to_operators(char *string)
{
	char	**ops;
	int		i;
	int		len;

	ops = (char **)malloc(sizeof(char *) * 1);
	ops[0] = NULL;
	i = 0;
	while (string[i])
	{
		while (ft_isspace(string[i]))
			i++;
		len = 0;
		while (string[i + len] && !ft_isspace(string[i + len]))
			len++;
		if (len)
			ops = add_item(ops, &string[i], len);
		i += len;
		if (!(string[i]))
			break ;
		i++;
	}
	return (ops);
}
