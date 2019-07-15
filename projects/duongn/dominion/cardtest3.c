/*Test endTurn */

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
	struct gameState *gS1 =  malloc(sizeof(struct gameState));
	struct gameState *gS2 =  malloc(sizeof(struct gameState));

	//copy from gS1 to gS2, use gS2 to check later
	memcpy(gS2, gS1);
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int tstGame = initializeGame(2, k, 69, gS1);

	printf("-----Testing endTurn \n" );

	int eT = endTurn(gS1);
	int currentPlayer = 0;
	int nextPlayer = 1;
	whoseTurn(1);
	printerror((gS1->whoseTurn) == (gS2->whoseTurn +1 ), " whoseTurn function. NextPlayer TURN ");
	printerror((gS1->handCount[currentPlayer]) == (gS2->handCount[currentPlayer]-discard), " handCount different currentPlayer " );

	if (check ==1){
		printf("endTurn PASSED\n" );
	}
	return 0;
}
