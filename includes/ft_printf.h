#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	char		*tab;
	int			size_tab;
	int			indice;
	int			minus;
	int			zeros;
	int			nbr_aff;
	int			precision;
}				t_info;

int		ft_printf(const char *text, ...) __attribute__ ((format(printf, 1, 2)));
void	ft_get_tab(const char *text, va_list args, t_info *Info);
void	ft_check_tab(va_list args, t_info *Info);

void	ft_which_conver(va_list args, t_info *Info);
void	ft_check_carac(va_list args, t_info *Info);
void	ft_check_hexa(va_list args, t_info *Info);
void	ft_check_int(va_list args, t_info *Info);
void	ft_check_point(va_list args, t_info *Info);
void	ft_printf_pc(va_list args, t_info *Info);

char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(const char *str);
int		ft_isdigit(char c);
int		ft_isalpha(int c);
char	*ft_reduce_tab(char *nbr);
char	*ft_base_hexa(unsigned int nbr, char *base);

#endif