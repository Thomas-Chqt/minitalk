/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv_specs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:10:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int				parse_next(const char *str, size_t *i, t_arg_list *args,
							t_conv_specs *parsed_conv_specs);
static int				parse_next_two(const char *str, size_t *i,
							t_arg_list *args, t_conv_specs *parsed_conv_specs);
static t_length_comp	final_length_mod(t_conv_specs *conv_specs);
static void				simplify_conv_spec(t_conv_specs *conv_specs);

int	parse_conv_specs(const char *str, size_t *i, t_arg_list *args,
						t_conv_specs *parsed_conv_specs)
{
	(*parsed_conv_specs) = empty_conv_specs();
	while (str[*i]
		&& parse_type_comp(str, i, &(parsed_conv_specs->conversion_type)) != 0)
	{
		if (parse_next(str, i, args, parsed_conv_specs) != 0)
			return (free_conv_specs(*parsed_conv_specs));
		(*i)++;
	}
	if (str[*i] == '\0')
		return (free_conv_specs(*parsed_conv_specs));
	(*i)++;
	parsed_conv_specs->length_mod = final_length_mod(parsed_conv_specs);
	simplify_conv_spec(parsed_conv_specs);
	return (0);
}

static int	parse_next(const char *str, size_t *i,
				t_arg_list *args, t_conv_specs *parsed_conv_specs)
{
	t_flag				new_flag;

	if (ft_strchr(",;:_", str[*i]) != NULL)
		return (0);
	if (parse_arg_index_comp(str, i, &(parsed_conv_specs->arg_index)) == 0)
		return (0);
	if (parse_flag(str, i, &new_flag) == 0)
	{
		parsed_conv_specs->flags
			= (parsed_conv_specs->flags | (t_flags_comp)new_flag);
		return (0);
	}
	if (parse_width_comp(str, i, args, &(parsed_conv_specs->width)) == 0)
		return (0);
	return (parse_next_two(str, i, args, parsed_conv_specs));
}

static int	parse_next_two(const char *str, size_t *i,
				t_arg_list *args, t_conv_specs *parsed_conv_specs)
{
	t_length_comp		new_length_comp;
	t_precision_comp	new_precision_comp;

	if (parse_precision_comp(str, i, args, &new_precision_comp) == 0)
	{
		if (parsed_conv_specs->precision == NULL)
			parsed_conv_specs->precision = malloc(sizeof(t_precision_comp));
		if (parsed_conv_specs->precision == NULL)
			return (-1);
		*(parsed_conv_specs->precision) = new_precision_comp;
		return (0);
	}
	if (parse_length_comp(str, i, &new_length_comp) == 0)
	{
		parsed_conv_specs->length_mod
			= (parsed_conv_specs->length_mod | (t_length_comp)new_length_comp);
		return (0);
	}
	return (-1);
}

static t_length_comp	final_length_mod(t_conv_specs *conv_specs)
{
	short	i;

	if (ft_strchr("cs", conv_specs->conversion_type) != NULL)
		return (conv_specs->length_mod & (t_length_comp)l);
	else
	{
		i = 8;
		while (i >= 0)
		{
			if ((conv_specs->length_mod & (1 << i)) != 0)
				return (conv_specs->length_mod & (1 << i));
			i--;
		}
		return (0);
	}
}

static void	simplify_conv_spec(t_conv_specs *conv_specs)
{
	if (conv_specs->conversion_type == p)
		conv_specs->length_mod = l;
	if ((conv_specs->conversion_type != c
			&& conv_specs->conversion_type != s
			&& conv_specs->precision != NULL)
		|| (conv_specs->flags & minus) == minus)
		conv_specs->flags = (conv_specs->flags & 0b11111101);
}
