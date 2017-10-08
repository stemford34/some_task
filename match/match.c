/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 18:21:09 by okovalch          #+#    #+#             */
/*   Updated: 2017/09/03 18:21:10 by okovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int Compare_lane(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int d = 0;
    while ( s1[i] != '\0')
        i++;
    while ( s2[j] != '\0')
        {
            if (s2[j] == '*')
                k++;
            j++;
        }
    if (j - k > i)
        return (0);
    i = 0;
    j = 0;
    k = 0;
    while ( s2[i] != '\0')
    {
        while ( s1[j] != '\0')
        {
            if (s2[i] == s1[j] || s2[i] == '*')
                d++;
            j++;
        }
        if ( d == 0)
            return (0);
        j = 0;
        i++;
    d = 0;
    }
    return (1);
}
int first_end(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    while ( s2[i] != '*' && s2[i] != '\0')
    {
        if (s2[i] == s1[i])
            {
                s2[i] = '*';
                s1[i] = '*';
                i++;
            }
        else
            return (0);
    }
    while (s2[j] != '\0')
        j++;
    i = 0;
    while (s1[i] != '\0')
        i++;
    while ( s2[j] != '*' && i != 0)
    {
        if (s2[j] == s1[i])
            {
                i--;
                j--;
                s2[j] = '*';
                s1[i] = '*';
            }
        else
            return (0);
    }
    return (1);
}
char    *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;
    int c;
    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        if (str[i] == to_find[j])
        {
            c = i;
            while (to_find[j] != '\0' && str[c] == to_find[j])
            {
                if (to_find[j + 1] == '\0')
                {
                    return (str + i);
                }
                j++;
                c++;
            }
        }
        i++;
    }
    return (0);
}
int main()
{
    int g;
    int h;
    char s1[] = "manmacinan";
    char s2[] = "ma*fgdfg****n";
    g = Compare_lane(s1, s2);
    h = first_end(s1, s2);
    printf("%s\n", s1);
    printf("%s\n", s2);
    int i = 0;
    while (s2[i] != '\0')
    {
        if (s2[i] != '*')
        {
            int y = 0;
            while (s2[y] != '*')
        }
        else
            i++;
    }
    printf("%d\n", h);
    printf("%d\n", g);
    return (0);
}