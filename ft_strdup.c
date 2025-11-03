/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:26:05 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/24 10:29:28 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// char	*ft_strdup(char *s)
// {
// 	char	*newstr;
// 	int		i;

// 	i = 0;
// 	newstr = malloc(sizeof(char) * ft_strlen(s) + 1);
// 	if (newstr == NULL)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		newstr[i] = s[i];
// 		i++;
// 	}
// 	newstr[i] = '\0';
// 	return (newstr);
// }
/*
int main()
{	
	// char *d1 = "Bonjour123456";
	char *d1 = NULL;
	char *d2;
	d2 = strdup(d1);
	// printf("%s\n", d2);
	free(d2);

	char *s1 = "Bonjour123456";
	// char *s1 = NULL;
	char *s2;
	s2 = ft_strdup(s1);
	// printf("%s\n", s2);
	free(s2);
}
*/
