#include <string>
#include "ia.h"
#include "time.h"

#include <algorithm>

//int IA::number_of_objects = 0;

IA::IA(Game * g)
    : Player("Computer" + id)
{
    deck = Deck::getInstance();
    game = g;
   // number_of_objects++;
   //id = number_of_objects;
    opponent = g->getCurrentPlayer();
    //probabilities.push_back(1.00);
    //probableCards.push_back(new Card("Countess",7,"Blaaaah"));
}

int IA::getIndexMostProbableCard(){

    int index;
    vector<double>::iterator findIter = std::find(probabilities.begin(), probabilities.end(), 1);
    if(findIter != probabilities.end())
        index = findIter - probabilities.begin();
    else
        index = -1;
    return index;
}


int IA::chooseCard(){
    int res;
    int indexCard;

    //if IA has the Princess, return the other card
    if((res = hasCard("Princess")) != -1 ){
        return (res+1)%2;
    }

    //if IA has a pair of the same card, then return whatever
    if(getCard(0) && getCard(1) && getCard(0)->isTheSameCardAs(getCard(1)->getName())){
       return 0;
    }

    //if we know the card of the other player with a 100% certainty
    if((indexCard = getIndexMostProbableCard())!= -1){
        Card * card = probableCards.at(indexCard);
        if((res = hasCard("Guard")) != -1){
            //set GuessCard = the card that we know
            return res;
        }
        //if last turn
        if(deck->count() == 0){
            if((res = hasCard("King")) != -1 && card->getValue() > getCard((res+1)%2)->getValue()){
                return res;
            }

            if((res = hasCard("Baron")) != -1 && card->getValue() > getCard((res+1)%2)->getValue()){
                return (res+1)%2;
            }

            return getCard(0)->getValue() < getCard(1)->getValue() ? 0 : 1;
        }
        //if that card is the princess
        if(card->getName() == "Princess"){
            if((res = hasCard("Prince")) != -1 ){
              return res;
            }
            if((res = hasCard("Baron")) != -1){
                return (res+1)%2;
            }
        }
        else{
            if((res=hasCard("Baron")) != -1){

                if(card->getValue() < getCard((res+1)%2)->getValue()){
                    return res;
                }
            }
        }
    }

    if(deck->count() == 0){
        return getCard(0)->getValue() < getCard(1)->getValue() ? 0 : 1;
    }

    //play Baron if the other card is a King, Countess or a Princess
    if((res = hasCard("Baron")) != -1 && getCard((res+1)%2)->getValue() >= 6 ){
        return res;
    }

    //always play Priest
    if((res=hasCard("Priest")) != -1){
        return res;
    }

    //always play Handmaid
    if((res=hasCard("Handmaid")) != -1){
        return res;
    }

    //if I have a Prince and a King, play the Prince
    if((res = hasCard("Prince")) != -1 && hasCard("King") != -1 ){
        return res;
    }

    srand( time(NULL) );
    res = rand() % 2;
    return res;

}








