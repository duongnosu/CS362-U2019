/*initializeGame TEST*/

#include "dominion_helpers.h"
#include "dominion.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "rngs.h"

int check = 0;
void printerror(int conditional, char*text) {
	if (conditional == 0) {
		printf("CHECK:  %s\n", text );
		check = 1;
	}
	return;
}

int main(int argc, char const *argv[]) {
	struct gameState *gS =  malloc(sizeof(struct gameState));

	int k = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int tstGame = initializeGame(2, k, 69, gS);
	printf("-----Testing initializeGame \n" );
	printerror(tstGame == 0, "initialize with nornal conditions FAILED");

	int tstGame =  initializeGame(-1, k, gS);
	printerror(tstGame == -1, "fail check initializeGame with -1 player. PASSED")

	k[2] = 99999999999;
	int tstGame = initializeGame(2, k, 69, gS);
	printerror( tstGame == -1, "fail check initialize game with incrorrect Kingdom. PASSED ");

	free(tstGame);

	if (check ==0) {
		/* code */
		printf("initializeGame PASSED ");
	}
	return 0;
}
