#include <execinfo.h>
#include <stdio.h>
#define BACKTRACE_MAX 128
static void backtrace_print(void)
{
	int nfuncs = 0;
	void *buf[BACKTRACE_MAX];
	char **symbols;
	int i;

	nfuncs = backtrace(buf, BACKTRACE_MAX);

	symbols = backtrace_symbols(buf, nfuncs);
	if (symbols == NULL) {
		fprintf(stderr, "backtrace_print failed to get symbols");
		return;
	}

	fprintf(stderr, "Backtrace ...\n");
	for (i = 0; i < nfuncs; i++)
		fprintf(stderr, "%s\n", symbols[i]);

	free(symbols);
}
