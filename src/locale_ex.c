/* Example using setlocale by TechOnTheNet.com */

#include <stdio.h>
#include <locale.h>

int main(int argc, const char * argv[])
{
    /* Define a temporary variable */
    struct lconv *loc;
	char tmp[] = "英语";
	char tmp1[] = "\x6E29\x5EA6";

    /* Set the locale to the POSIX C environment */
//    setlocale (LC_ALL, " ");

    /* Retrieve a pointer to the current locale */
//    loc = localeconv();

    /* Display some of the locale settings */
  //  printf("Thousands Separator: %s\n", loc->thousands_sep);
  //  printf("Currency Symbol: %s\n", loc->currency_symbol);

    /* Set the locale to the environment default */
   // setlocale (LC_ALL, "");

    /* Retrieve a pointer to the current locale */
  //  loc = localeconv();

    /* Display some of the locale settings */
    //printf("Thousands Separator: %s\n", loc->thousands_sep);
    //printf("Currency Symbol: %s\n", loc->currency_symbol);

	printf("%s\n", tmp);
	printf("%s\n", tmp1);

    return 0;
}
