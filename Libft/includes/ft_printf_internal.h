/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:52:02 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/18 17:00:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include "libft_internal.h"

typedef unsigned int	t_arg_index_comp;
typedef unsigned char	t_flags_comp;
typedef unsigned int	t_width_comp;
typedef unsigned int	t_precision_comp;
typedef struct s_arg_list
{
	va_list	ap_start;
	va_list	ap_current;
}	t_arg_list;

typedef enum flag
{
	hash	= 0b00000001,
	zero	= 0b00000010,
	minus	= 0b00000100,
	space	= 0b00001000,
	plus	= 0b00010000,
	apos	= 0b00100000,
}	t_flag;

typedef enum length_comp
{
	hh		= 0b00000001,
	h		= 0b00000010,
	l		= 0b00000100,
	j		= 0b00001000,
	t		= 0b00010000,
	z		= 0b00100000,
	q		= 0b01000000,
	ll		= 0b10000000
}	t_length_comp;

typedef enum conv_type
{
	c		= 'c',
	s		= 's',
	p		= 'p',
	d		= 'd',
	i		= 'i',
	u		= 'u',
	x		= 'x',
	upx		= 'X',
	perc	= '%'
}	t_type_comp;

typedef struct s_conv_specs
{
	t_arg_index_comp	arg_index;
	t_flags_comp		flags;
	t_width_comp		width;
	t_precision_comp	*precision;
	t_length_comp		length_mod;
	t_type_comp			conversion_type;
}	t_conv_specs;

void			arg_list_start(t_arg_list *list);
void			move_ap(unsigned int n, t_arg_list *list);
long long		get_arg(unsigned int n, t_arg_list *list);
unsigned int	get_arg_no_move(unsigned int n, t_arg_list *list);
void			arg_list_end(t_arg_list *list);
unsigned int	ft_atoi_uint(const char *str);
size_t			put_n_c(size_t n, size_t minus, char c);
char			*itoa_base(unsigned long long nbr, char *base);
char			*itoa_base_no_minus(long long nbr, char *base);
size_t			unbr_base_len(unsigned long long nbr, char *base);
size_t			nbr_base_len(long long nbr, char *base);
char			*strjoinf(char *s1, char *s2);
char			*create_str(char c, long n);
int				parse_flag(const char *str, size_t *i, t_flag *parsed_flag);
int				parse_length_comp(const char *str, size_t *i,
					t_length_comp *parsed_length_comp);
int				parse_type_comp(const char *str, size_t *i,
					t_type_comp *parsed_type_comp);
t_conv_specs	empty_conv_specs(void);
int				free_conv_specs(t_conv_specs conv_specs);
int				parse_arg_index_comp(const char *str, size_t *i,
					t_arg_index_comp *parsed_arg_index_comp);
int				parse_width_comp(const char *str, size_t *i, t_arg_list *args,
					t_width_comp *parsed_width_comp);
int				parse_precision_comp(const char *str, size_t *i,
					t_arg_list *args,
					t_precision_comp *parsed_precision_comp);
int				parse_conv_specs(const char *str, size_t *i, t_arg_list *args,
					t_conv_specs *parsed_conv_specs);
int				put_c(t_conv_specs conv_specs, t_arg_list *args);
int				put_s(t_conv_specs conv_specs, t_arg_list *args);
int				put_di(t_conv_specs conv_specs, t_arg_list *args);
int				put_u(t_conv_specs conv_specs, t_arg_list *args);
int				put_x(t_conv_specs conv_specs, t_arg_list *args);
int				put_upx(t_conv_specs conv_specs, t_arg_list *args);
int				put_per(t_conv_specs conv_specs, t_arg_list *args);
int				print_converted(const char *str, size_t *i, t_arg_list *args,
					size_t *print_count);

#endif // FT_PRINTF_INTERNAL