

static size_t	ft_countwords(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while(*s)
	{
		while(*s == c)
			s++;
		if(*s)
			count++;
		while(*s != c && *s)
			s++;
	}
	return (count);
}

static char *dup_word(const char *str, int start, int end)
{
	char	*word;
	int	i;
	
	word = (char *)malloc((end - start + 1) * sizeof(char));
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);

}
char **ft_split(char const *s, char c)
{
	char	**lst;
	size_t	len1;
	size_t	len2;
	int	index;

	lst = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	index = -1;
	len1 = 0;
	len2 = 0;
	while (i <= ft_strlen(s))
	{
		if (s[len1] != c && index < 0)
			index = len1;
		else if((s[len1] == c || len1 == ft_strlen(s)) && index >= 0)
		{
			lst[len2++] = dup_word(s, index, len1);
			index = -1;
		}
		len1++;
	}
	lst[len2] = '\0';
	return (lst);
}
/*
int main() {
    char str[] = "Hola,mundo,ejemplo";
    char **token;
    int i;
    
    // El primer llamado usa la cadena
    token = ft_split(str, ',');
    
    i = -1;
    while(token[++i])
    printf("%s\n", token[i]);
    
    return 0;
}*/
