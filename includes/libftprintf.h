char				*flag_string(va_list valist);
char				*flag_int(va_list valist);
int					conversion_launcher(char flag);
static char			*parse(const char *format, va_list valist);
void				ft_printf(const char *format, ...);
