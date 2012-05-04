/* 
 * This is a trivial program to background things, but if you care, it's
 * available under the terms of the MIT license.
 */

#include <err.h>
#include <stdbool.h>
#include <sysexits.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
	int rc;

	rc = daemon(true/*nochdir*/, true/*noredirect*/);
	if (rc == -1)
		err(EX_OSERR, "daemon(2)");

	execvp(argv[1], argv+1);
	err(EX_OSERR, "execvp(3)");
}
