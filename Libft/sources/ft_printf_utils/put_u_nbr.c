/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:06:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	put_signed(unsigned long long nbr,
				char *base, t_conv_specs conv_specs);
static char	*get_pre_str(unsigned long long nbr, t_conv_specs conv_specs);

int	put_u(t_conv_specs conv_specs, t_arg_list *args)
{
	char	*base;

	base = "0123456789";
	if (conv_specs.length_mod == hh)
		return (put_signed((unsigned char)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == h)
		return (put_signed((unsigned short)get_arg(conv_specs.arg_index,
					args), base, conv_specs));
	else if (conv_specs.length_mod == 0)
		return (put_signed((unsigned int)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == l || conv_specs.length_mod == j
		|| conv_specs.length_mod == t || conv_specs.length_mod == z)
		return (put_signed((unsigned long)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == ll || conv_specs.length_mod == q)
		return (put_signed((unsigned long long)get_arg(conv_specs.arg_index,
					args), base, conv_specs));
	else
		return (0);
}

int	put_x(t_conv_specs conv_specs, t_arg_list *args)
{
	char	*base;

	base = "0123456789abcdef";
	if (conv_specs.length_mod == hh)
		return (put_signed((unsigned char)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == h)
		return (put_signed((unsigned short)get_arg(conv_specs.arg_index,
					args), base, conv_specs));
	else if (conv_specs.length_mod == 0)
		return (put_signed((unsigned int)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == l || conv_specs.length_mod == j
		|| conv_specs.length_mod == t || conv_specs.length_mod == z)
		return (put_signed((unsigned long)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == ll || conv_specs.length_mod == q)
		return (put_signed((unsigned long long)get_arg(conv_specs.arg_index,
					args), base, conv_specs));
	else
		return (0);
}

int	put_upx(t_conv_specs conv_specs, t_arg_list *args)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (conv_specs.length_mod == hh)
		return (put_signed((unsigned char)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == h)
		return (put_signed((unsigned short)get_arg(conv_specs.arg_index,
					args), base, conv_specs));
	else if (conv_specs.length_mod == 0)
		return (put_signed((unsigned int)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == l || conv_specs.length_mod == j
		|| conv_specs.length_mod == t || conv_specs.length_mod == z)
		return (put_signed((unsigned long)get_arg(conv_specs.arg_index, args),
				base, conv_specs));
	else if (conv_specs.length_mod == ll || conv_specs.length_mod == q)
		return (put_signed((unsigned long long)get_arg(conv_specs.arg_index,
					args), base, conv_specs));
	else
		return (0);
}

static int	put_signed(unsigned long long nbr,
	char *base, t_conv_specs conv_specs)
{
	int		print_count;
	char	*str;
	char	padding_char;

	print_count = 0;
	padding_char = ' ';
	if ((conv_specs.flags & zero) == zero)
		padding_char = '0';
	if (conv_specs.precision && *(conv_specs.precision) == 0 && nbr == 0)
		str = ft_strdup("");
	else if (conv_specs.precision)
		str = strjoinf(create_str('0', *(conv_specs.precision)
					- unbr_base_len(nbr, base)), itoa_base(nbr, base));
	else
		str = itoa_base(nbr, base);
	str = strjoinf(get_pre_str(nbr, conv_specs), str);
	if ((conv_specs.flags & minus) != minus)
		print_count += put_n_c(conv_specs.width, ft_strlen(str), padding_char);
	ft_putstr_fd(str, 1);
	print_count += ft_strlen(str);
	if ((conv_specs.flags & minus) == minus)
		print_count += put_n_c(conv_specs.width, ft_strlen(str), padding_char);
	free(str);
	return (print_count);
}

static char	*get_pre_str(unsigned long long nbr, t_conv_specs conv_specs)
{
	if (conv_specs.conversion_type == p)
		return (ft_strdup("0x"));
	if ((conv_specs.flags & hash) == hash && conv_specs.conversion_type == x
		&& nbr > 0)
		return (ft_strdup("0x"));
	if ((conv_specs.flags & hash) == hash && conv_specs.conversion_type == upx
		&& nbr > 0)
		return (ft_strdup("0X"));
	if ((conv_specs.flags & plus) == plus)
		return (ft_strdup("+"));
	if ((conv_specs.flags & space) == space)
		return (ft_strdup(" "));
	return (NULL);
}
