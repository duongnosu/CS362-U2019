/*Test getWinners*/

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
	int players_array[]= {-1,-1};
	struct gameState *gS =  malloc(sizeof(struct gameState));

	int k = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 69, gS);
	printf("-----Testing getWinners----- \n" );
	gS->hand[0][0] = province;
	gS->hand[0][1] = province;
	gS->hand[0][2] = province;
	gS->hand[0][3] = province;
	gS->hand[0][4] = province;

	getWinners(players_array, gS);
	if(players_array[0] != 1){
		printf("getWinners function set winners to 1 FAILED\n" );
	}
	else{
		printf("getWinners PASSED\n" );
	}
return 0;
}
