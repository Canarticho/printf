#include "printf.h"

char		*ft_plltoa(t_type type, int base)
{
	static char	res[16 * 8 + 2];

	ft_bzero(res, 16 * 8 + 2);
	if (base)
		return (ft_ulltoa(type.unsign.ll, res, base));
	else
		ft_lltoa(type.sign.ll, res, 10);
	return (res);
}

char		*ft_pltoa(t_type type, int base)
{
	static char	res[8 * 8 + 2];

	ft_bzero(res, 8 * 8 + 2);
	if (base)
		return (ft_ultoa(type.unsign.l, res, base));
	else
		ft_ltoa(type.sign.l, res, 10);
	return (res);
}

char		*ft_pitoa(t_type type, int base)
{
	static char	res[4 * 8 + 2];

	ft_bzero(res, 4 * 8 + 2);
	if (base)
		return (ft_uitoa(type.unsign.i, res, base));
	else
		ft_itoa(type.sign.i, res, 10);
	return (res);
}

char		*ft_pstoa(t_type type, int base)
{
	static char	res[2 * 8 + 2];

	ft_bzero(res, 2 * 8 + 2);
	if (base)
		return (ft_ustoa(type.unsign.s, res, base));
	else
		ft_stoa(type.sign.s, res, 10);
	return (res);
}

char		*ft_pctoa(t_type type, int base)
{
	static char	res[1 * 8 + 2];

	ft_bzero(res, 1 * 8 + 2);
	if (base)
		return (ft_uctoa(type.unsign.c, res, base));
	else
		ft_ctoa(type.sign.c, res, 10);
	return (res);
}
