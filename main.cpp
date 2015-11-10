#include <iostream>
#include "CardPool.h"

int main(){
	/*GameCard start;
	start.show();
	std::cout<<std::endl<<"================"<<std::endl;
	start.shuffle();
	start.show();
	std::cout<<std::endl;*/
	CardPool cardpool;
	int all = cardpool.full_allcards();
	std::cout<<"all count : "<<all<<std::endl;
	for(int i = 0; i < MAX_ALL_CARDS; i++){
		cardpool.ALLCARDS[i]->show();
		if(i%10 == 0)
			std::cout<<std::endl;
	}


}
