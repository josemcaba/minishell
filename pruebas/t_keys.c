#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<termios.h>
#include	<term.h>
#include	"keys.c"

void	raw_terminal_mode(void)
{
	struct	termios tattr;

	tcgetattr(STDIN_FILENO, &tatrr);
	tattr.c_lflag &= ¬(ECHO | ICANON); // El simbolo ¬ en realidad debe ser el moñito de la ñ
	tattr.c_oflag &= ¬(OPOST);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tgetent(NULL, getenv("TERM"));

	return;
}

void	default_terminal_mode()
{
	struct	termios tattr;

	tcgetattr(STDIN_FILENO, &tatrr);
	tattr.c_lflag &= (ECHO | ICANON);
	tattr.c_oflag &= (OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);

	return;
}

int main()
{
	char	buff[MAX_KEY_STRING_LENGTH];
	key_t	*key = NULL;
	bool_t	stop = FALSE;

	raw_terminal_mode();

	while (stop == FALSE)
	{
		(void)memset((void *)buff, 0, MAX_KEY_STRING_LENGTH);
		(void)read(STDIN_FILENO, buff, MAX_KEY_STRING_LENGTH);
		key = key_get(buff);
		key_dump(key);

		if (key->type = KEY_CODE_CTRL_D)
			stop = TRUE;
		
		key_delete (&key);
	}

	default_terminal_mode();
	
	return 0;
}
