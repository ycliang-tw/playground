#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void showid()
{
        printf("real user id: %d\n", getuid());
        printf("effective user id: %d\n", geteuid());
}

int main(int argc, char *argv[]){
        showid();
		unlink(argv[1]);
        return 0;
}

