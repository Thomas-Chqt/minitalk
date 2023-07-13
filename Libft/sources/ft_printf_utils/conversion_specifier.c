/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:50:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

t_conv_specs	empty_conv_specs(void)
{
	t_conv_specs	specs;

	specs.arg_index = 0;
	specs.flags = 0;
	specs.width = 0;
	specs.precision = NULL;
	specs.length_mod = 0;
	specs.conversion_type = 0;
	return (specs);
}

int	free_conv_specs(t_conv_specs conv_specs)
{
	if (conv_specs.precision != NULL)
		free(conv_specs.precision);
	return (-1);
}
