#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hap.h>

int main(int argc, char **argv) {
	int index;
	char *identifiers[argc-1];

	HAPEngine *engine = hap_engine_create();

	if (engine == NULL) return 1;

	(*engine).name = "hap";  // TODO: This should come from build tools
	(*engine).argc = &argc;
	(*engine).argvp = argv;

	if (argc <= 1) {
		printf("No modules to load. Nothing to do.\n");
		return 0;
	}

	for (index = 1; index < argc; ++index) {
		identifiers[index-1] = strdup(argv[index]);
	}

	hap_module_execute(engine, argc - 1, identifiers);
	hap_engine_destroy(engine);

	for (index = 0; index < argc-1; ++index) free(identifiers[index]);

	return 0;
}
