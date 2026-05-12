/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:43:09 by prosas-p          #+#    #+#             */
/*   Updated: 2024/01/02 13:25:19 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

void	ft_marcas_bonus(char *format, va_list args, int *pos, int *nchars);
void	ft_printvar(char *format, va_list args, int *pos, int *nchars);
int		ft_printf(char const *format, ...);

#endif