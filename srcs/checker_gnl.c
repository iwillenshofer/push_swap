/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 22:18:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/08 21:55:51 by iwillens         ###   ########.fr       */
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

char **add_item(char **ops, char *item, size_t size)
{
	
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
		len = 0;
		while (string[i + len] && (string[i + len] != '\n'))
			len++;
		if (len)
			ops = add_item(ops, &string[i], len);
		i += len;
		i++;
	}
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