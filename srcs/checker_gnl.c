/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 22:18:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/20 18:28:42 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char *ft_addchar(char *s1, char c)
{
	int size;
	char *s2;
	int i;

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

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\v' || c == '\r')
		return (TRUE);
	return(FALSE);
}

char **add_item(char **ops, char *item, size_t size)
{
	size_t len;
	char **tmp;
	size_t i;

	len = 0;
	i = 0;
	if (!(size))
		return (ops);
	while (ops[len])
		len++;
	tmp = (char**)malloc(sizeof(char*) * (len + 2));
	while (i < len)
	{
		tmp[i] = ops[i];
		i++;
	}
	tmp[i] = (char*)malloc(sizeof(char) * (size + 1));
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

char **string_to_operators(char *string)
{
	char **ops;
	int i;
	int len;
	
	ops = (char**)malloc(sizeof(char*) * 1);
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
			break;
		i++;
	}
	return(ops);
}

char *read_stdin(void)
{
	char buffer[1];
	char *str;
	char **ops;

	str = (char*)malloc(sizeof(char) * 1);
	str[0] = '\0';
	while (read(0, buffer, 1))
		str = ft_addchar(str, buffer[0]);
	ft_putstr(str);
	ops = string_to_operators(str);
	free(str);
	return (NULL);
}