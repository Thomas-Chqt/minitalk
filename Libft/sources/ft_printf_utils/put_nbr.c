/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:59:02 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	put_signed(long long nbr,
				char *base, t_conv_specs conv_specs);
static char	*get_signe(long long nbr, t_conv_specs conv_specs);

int	put_di(t_conv_specs conv_specs, t_arg_list *args)
{
	char	*base;

	base = "0123456789";
	if (conv_specs.length_mod == hh)
		return (put_signed((char)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == h)
		return (put_signed((short)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == 0)
		return (put_signed((int)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == l || conv_specs.length_mod == j
		|| conv_specs.length_mod == t || conv_specs.length_mod == z)
		return (put_signed((long)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == ll || conv_specs.length_mod == q)
		return (put_signed((long long)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else
		return (0);
}

static int	put_signed(long long nbr,
	char *base, t_conv_specs conv_specs)
{
	int		print_count;
	char	*str;
	char	*signe;

	print_count = 0;
	signe = get_signe(nbr, conv_specs);
	if (conv_specs.precision && *(conv_specs.precision) == 0 && nbr == 0)
		str = ft_strdup("");
	else if (conv_specs.precision)
		str = strjoinf(create_str('0', *(conv_specs.precision)
					- nbr_base_len(nbr, base)), itoa_base_no_minus(nbr, base));
	else
		str = itoa_base_no_minus(nbr, base);
	if ((conv_specs.flags & zero) == zero)
		str = strjoinf(create_str('0', conv_specs.width
					- ft_strlen(str) - ft_strlen(signe)), str);
	str = strjoinf(signe, str);
	if ((conv_specs.flags & minus) == minus)
		str = strjoinf(str, create_str(' ', conv_specs.width - ft_strlen(str)));
	else if ((conv_specs.flags & zero) != zero)
		str = strjoinf(create_str(' ', conv_specs.width - ft_strlen(str)), str);
	ft_putstr_fd(str, 1);
	print_count += ft_strlen(str);
	free(str);
	return (print_count);
}

static char	*get_signe(long long nbr, t_conv_specs conv_specs)
{
	if (nbr < 0)
		return (ft_strdup("-"));
	if ((conv_specs.flags & plus) == plus)
		return (ft_strdup("+"));
	if ((conv_specs.flags & space) == space)
		return (ft_strdup(" "));
	return (NULL);
}
