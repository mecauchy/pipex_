#include "../includes/pipex.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] && s2[i]) && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_is_sep(char *str, char charset)
{
	if (*str == charset)
		return (1);
	return (0);
}

static int	ft_ltrcnt(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(ft_is_sep(str + i, charset)))
		i++;
	return (i);
}

static int	ft_wrdcnt(char *str, char charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		if (*str && ft_is_sep(str, charset))
			str++;
		i = ft_ltrcnt(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*ft_wdcpy(char *str, int size)
{
	char	*dest;

	dest = malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	dest[size] = '\0';
	while (size--)
		dest[size] = str[size];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;
	int		i;
	int		j;

	i = 0;
	size = ft_wrdcnt((char *)s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		while (*s && ft_is_sep((char *)s, c))
			s++;
		j = ft_ltrcnt((char *)s, c);
		str[i] = ft_wdcpy((char *)s, j);
		if (str[i] == NULL)
			return (NULL);
		s += j;
		i++;
	}
	str[size] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1)
		return ((char *)s2);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
		res[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		res[j++] = s2[i++];
	res[j] = 0;
	return (res);
}
