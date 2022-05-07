#include "BattleMechanics.h"

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "BattleMenu.h"


// for the miss hit chance might not work just an idea

//int hitChance = 0
//bool enemyHit = false;

/* if (enemyAttack == (enemies special attack))
    hitChance = 1 or could be 100 so its easier no decimals

else {

    enemyhitChance = 100 - (rand % 15)
}    */

// This might be brute coding but its and idea as long as we go with the hit chance out of 100

/* if (enemyHitchance == 100){

enemyHit = true;

} 

else if (enemyHitChance % 4 == 1 ) {

    enemyHit = true;
}

else if (enemyHitChance % 4 == 2){

    enemyhit == true;

}

else if (enemyHitChance % 4 == 3){

enemyhit == true;

}

else {

enemyHit = false;

}


if (enemyHit == true)
{

characterHP -= enemyDamage  // can use array instead of bool to locate what exact attack our character took ill edit it more later just on my lunch

}