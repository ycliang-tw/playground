#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// the following can be tested with "gcc -E <file to be preprocessed> -o <output file>"
// <output file> will be the preprocessed file of <file to be preprocessed>, take a peek!
// # is used to stringize: to add ""
// 		with #:
// 			COMMAND(help) will be expanded into {"help", help_command}
// 		w/o #:
// 			COMMAND(help) will be expanded into {help, help_command}
// ## is used to concatenate: to specify the location where string substitution needs to be done
// 		with ##:
// 			COMMAND(help) will be expanded into {"help", help_command}
// 		w/o ##:
// 			COMMAND(help) will be expanded into {"help", NAME_command}

#define COMMAND(NAME) {#NAME, NAME##_command}
#define func(name)\
	void name##_command(){	\
		printf("[function]: %s\n", #name);	\
	}
struct command
{
	char *name;
	void (*function)(void);
};

func(quit);
func(help);
func(version);

struct command commands[] = 
{
	COMMAND(quit),
	COMMAND(help),
	COMMAND(version),
};


/*
struct command commands[] = 
{
	{"quit", quit_command},
	{"help", help_command},
	{"version", vesion_command},
};
*/

int main(int argc, char *argv[])
{
	if(argc != 2){
		fprintf(stderr, "invalid amount of argument\n");
		exit(1);
	}
	struct command a = { .name = argv[1] };
	int ncom = sizeof(commands)/sizeof(struct command);
	for(int i = 0; i < ncom; i++){
		if(strcmp(a.name, commands[i].name) == 0){
			a.function = commands[i].function;
			a.function();
		}
	}
	return 0;
}
