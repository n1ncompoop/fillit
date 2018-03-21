/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkwon <[rkwon@student.42.us.org]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:03:57 by rkwon             #+#    #+#             */
/*   Updated: 2018/03/20 19:04:04 by rkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *tet_name(int *i, int len)
{
	char **name[19];

	name = {"o1", "i1", "i2", "s1", "s2", "z1", "z2", "l1", "l2", "l3", "l4", "j1", "j2", "j3", "j4", "t1", "t2", "t3", "t4"};
	
}

char	*plus_one(int *i, char *piece, int len)
{
	if (*(i + 1) == '#')
	{
		if (*(i + 2) == '#')
			return (name[1]);
		else if (*(i + len) == '#')
			return (name[7]);
		else if (*(i + len + 1) == '#')
			return (name[15]);
		else if (*(i + len + 2) == '#')
			return (name[11]);
	}
	else if (*(i + len) == '#')
	{
		if (*(i + len + 1) == '#')
			return (name[0]);
		else if (*(i + (2 * (len)) == '#')
			return (name[12]);
		else if (*(i + len - 1) == '#')
			return (name[3]);
	}
	else if (*(i + len + 1) == '#')
	{
		if (*(i + len + 2) == '#')
			return (name[5]);
		else if (*(i + (2 * (len)) + 1) == '#')
			return (name[7]);
	}
	return (NULL);
}

char	*plus_y(int *i, char *piece, int len)
{
	if (*(i + len + 1) == '#')
	{
		if (*(i + len + 2) == '#')
			return (name[13]);
		else if (*(i + (2 * len)) == '#')
			return (name[16]);
		else if (*(i + (2 * len) + 1) == '#')
			return (name[4]);
	}
	else if (*(i + (2 * len)) == '#')
	{
		if (*(i + (3 * len)) == '#')
			return (name[2]);
		else if (*(i + (2 * len) + 1) == '#')
			return (name[8]);
		else if (*(i + (2 * len) - 1) == '#')
			return (name[14]);
	}
	else if (*(i + len - 1) == '#')
	{
		if (*(i + len + 1) == '#')
			return (name[17]);
		else if (*(i + (2 * len) == '#')
			return (name[18]);
		else if (*(i + (2 * len) - 1) == '#')
			return (name[6]);
		else if (*(i + len - 2) == '#')
			return (name[9]);
	}
	return (NULL);
}