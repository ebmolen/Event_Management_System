/*
* File: searchingStrategy.cpp
* ---------------
* This file implements the SearchingStrategy class.
* Implementations notes are minimal, as implementation is straightforward.
*/

#include "searchingStrategy.h"
#include <string>
#include <vector>
#include "event.h"

// Constructor for SearchingStrategy class
SearchingStrategy::SearchingStrategy(){}

//Constructor for EventNameSearch class
EventNameSearch::EventNameSearch(std::string cname) : SearchingStrategy::SearchingStrategy(){
    name = cname;
}

std::vector<Event*> EventNameSearch::eventSearch(std::vector<Event*> &events) {
    std::vector<Event*> myEvents;
    for (Event * e : events){
        if (e -> getEventName().find(name) != std::string::npos){
            myEvents.push_back(e);
        }
    }
    return myEvents;
}

// Constructor for EventLocationSearch class
EventLocationSearch::EventLocationSearch(std::string ccity, std::string cstate): SearchingStrategy::SearchingStrategy(){
    city  = ccity;
    state = cstate;
}

std::vector<Event*> EventLocationSearch::eventSearch(std::vector<Event*> &events){
    std::vector<Event*> myEvents;
    for (Event * e : events){
        if (e -> getLocationCity() == city && e -> getLocationState() == state){
            myEvents.push_back(e);
        }
    }
    return myEvents;
}

// Constructor for EventDateSearch class

EventDateSearch::EventDateSearch(int cmonth, int cday, int cyear) : SearchingStrategy::SearchingStrategy(){
    year = cyear - 1900;
    month = cmonth -1;
    day = cday;
}

std::vector<Event*> EventDateSearch::eventSearch(std::vector<Event*> &events) {
    std::vector<Event*> myEvents;
    for (Event * e : events){
        if (e -> getEventDate().tm_year == year && e -> getEventDate().tm_mon == month && e -> getEventDate().tm_mday == day){
            myEvents.push_back(e);
        }
    }
    return myEvents;
}

// Constructor for TicketsAvailSearch class
TicketsAvailSearch::TicketsAvailSearch() : SearchingStrategy::SearchingStrategy(){}

std::vector<Event*> TicketsAvailSearch::eventSearch(std::vector<Event*> &events){

    std::vector<Event*> myEvents;
    for (Event * e : events){
        if (e -> getNumTicketsAvailable() > 0 && e->isUpcoming()){
            myEvents.push_back(e);
        }
    }
    return myEvents;
}



