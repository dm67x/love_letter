#include <string>
#include "ia_intel.h"
#include "time.h"

#include <algorithm>

namespace IA {

int IA_intel::number_of_objects = 0;

IA_intel::IA_intel(Core::Game * g)
{
    number_of_objects++;
    id = number_of_objects;

    deck = g->getDeck();
    game = g;
    ai = g->getPlayers().at(1);
    opponent = g->getPlayers().at(0);

    probableCards.push_back(new Core::Guard());
    probableCards.push_back(new Core::Priest());
    probableCards.push_back(new Core::Baron());
    probableCards.push_back(new Core::Handmaid());
    probableCards.push_back(new Core::Prince());
    probableCards.push_back(new Core::King());
    probableCards.push_back(new Core::Countess());
    probableCards.push_back(new Core::Princess());

    for(int i=0;i<8;i++)
        probabilities.push_back(0);

}

void IA_intel::updateProbabilities()
{
    int index = -1;
    // if opponent played  a King
    if(opponent->getPlayedCards().back()->isTheSameCardAs("King")){
        index =  opponent->getCard(0)->getValue() - 1;
        probabilities[index] = 1;
    }

    for(int i=0;i<8 && index != i;i++){

        /*if opponent didn't throw the card that we knew,
        we don't update its probability*/
        if(probabilities[i] == 1 &&
           !probableCards.at(i)->
              isTheSameCardAs(opponent->getPlayedCards().back()->getName()));
        else
            probabilities[i] = calculateProbability(probableCards[i]);
    }
}

int IA_intel::getIndexMostProbableCard()
{
    int index;
    vector<double>::iterator result;

    result = std::max_element(probabilities.begin(), probabilities.end());
    index = std::distance(probabilities.begin(), result);

    return index;
}

int IA_intel::getIndexSecondMostProbableCard(int max)
{
    double second_max = probabilities[0];
    for(int i=1; i< 8 && i!= max ;i++){
        if(probabilities[i] > second_max)
            second_max = probabilities[i];
    }

    return second_max;
}

double IA_intel::calculateProbability(Core::Card *c)
{
    int count1 = ai->getPlayedCards().size();
    int count2 = opponent->getPlayedCards().size();
    double d = ((double)c->getNbCopies()-((double)count1+(double)count2)) /
            ((double)deck->getCards().size() + (double)deck->getRemovedCards().size());
    return d;
}


int IA_intel::chooseCard(){
    int res;
    int indexCard;
    int cardToPlay;
    Core::Card * card;

    if(!this->opponent->getPlayedCards().empty())
        updateProbabilities();

    indexCard = getIndexMostProbableCard();
    card = probableCards.at(indexCard);


    //if IA has the Princess, return the other card
    if((res = ai->hasCard("Princess")) != -1 ){
        cardToPlay = (res+1)%2;
    }

    //if IA has a pair of the same card, then return whatever
    else if(ai->getCard(0) &&
            ai->getCard(1) &&
            ai->getCard(0)->isTheSameCardAs(ai->getCard(1)->getName())){
       cardToPlay = 0;
    }

    //if we know the card of the other player with a 100% certainty
    else if(probabilities[indexCard] == 1){
        if((res = ai->hasCard("Guard")) != -1 &&
                !card->isTheSameCardAs("Guard") &&
                !opponent->hasShield()){
            cardToPlay = res;
        }

        else if(card->isTheSameCardAs("Princess") &&
                (res = ai->hasCard("Prince")) != -1 ){
            cardToPlay = res;
        }

        else if((res = ai->hasCard("Baron")) != -1){
            if(ai->getCard((res+1)%2)->getValue() > card->getValue())
                cardToPlay = res;
            else cardToPlay = (res+1)%2;
        }
        //if last turn
        else if(deck->getCards().empty()){
            if((res = ai->hasCard("King")) != -1 &&
                    card->getValue() > ai->getCard((res+1)%2)->getValue()){
                cardToPlay = res;
            }

            else cardToPlay =
                    ai->getCard(0)->getValue() < ai->getCard(1)->getValue() ? 0 : 1;
        }
        else {
            srand( time(NULL) );
            cardToPlay = rand() % 2;
        }
    }

    // if last turn and we dont know the opponnents card
    else if(deck->getCards().empty()){
        cardToPlay = ai->getCard(0)->getValue() < ai->getCard(1)->getValue() ? 0 : 1;
    }

    //play Baron if the other card is a King, Countess or a Princess
    else if((res = ai->hasCard("Baron")) != -1 &&
            ai->getCard((res+1)%2)->getValue() >= 6 ){
        cardToPlay = res;
    }

    //always play Priest
    else if((res=ai->hasCard("Priest")) != -1){
        cardToPlay = res;
    }

    //always play Handmaid
    else if((res=ai->hasCard("Handmaid")) != -1){
        cardToPlay = res;
    }

    //if I have a Prince and a King, play the Prince
    else if((res = ai->hasCard("Prince")) != -1 && ai->hasCard("King") != -1 ){
        cardToPlay = res;
    }

    else {
        srand( time(NULL) );
        cardToPlay = rand() % 2;
    }

    // if priest chosen to play
    if(ai->getCard(cardToPlay)->isTheSameCardAs("Priest")){
        res =  opponent->getCard(0)->getValue() - 1;
        probabilities[res] = 1;
    }

    if(ai->getCard(cardToPlay)->isTheSameCardAs("King")){
        res =  opponent->getCard(0)->getValue() - 1;
        probabilities[res] = 1;
    }

    if(ai->getCard(cardToPlay)->isTheSameCardAs("Guard") &&
            card->isTheSameCardAs("Guard")){
        //search for the second most probable card
        indexCard = getIndexSecondMostProbableCard(indexCard);
        card = probableCards.at(indexCard);

    }

    // set guess and pickTarget
    game->pickTarget(0);
    game->guessCard(card->getName());

    return cardToPlay;
}

}










