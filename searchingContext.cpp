/*
* File: searchingContext.cpp
* ---------------
* This file implements the SearchingContext class.
* Implementation notes are minimal as implementations are straightforward.
*/
#include "searchingContext.h"
#include "searchingStrategy.h"
#include "event.h"
#include <string>
#include <vector>


SearchingContext::SearchingContext(SearchingStrategy* csearchingStrategy){
    searchingStrategy = csearchingStrategy;
}

SearchingStrategy* SearchingContext::getSearchingStrategy(){
    return searchingStrategy;
}

void SearchingContext::setSearchingStrategy(SearchingStrategy* csearchingStrategy){
    searchingStrategy = csearchingStrategy;
}

std::vector<Event*> SearchingContext::performSearch(std::vector<Event*> events){
    return searchingStrategy->eventSearch(events);
}
