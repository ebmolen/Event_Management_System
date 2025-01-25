/*
* File: event.cpp
* ---------------
* This file implements the Event class
*
* Implementation notes are minimal, as method implementations are fairly straightforward.
* See event.h for explanations of method purposes and variables.
*/

#include "event.h"
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <iostream>
#include <set>
#include <compare>

// Implementation of Event Constructor
Event::Event(std::string ceventName, std::string cvenue, std::string clocationCity, std::string clocationState, int year, int month, int day, int startHour, int startMin, int cnumTicketsAvailable, float cticketPrice){
    eventName = ceventName;
    venue = cvenue;
    locationCity = clocationCity;
    locationState = clocationState;
    numTicketsAvailable = cnumTicketsAvailable;
    ticketPrice = cticketPrice;
    numTicketsSold = 0;
    eventDate.tm_year = year - 1900;
    eventDate.tm_mon = month - 1;
    eventDate.tm_mday = day;
    eventDate.tm_hour = startHour;
    eventDate.tm_min = startMin;
    eventDate.tm_sec = 0;
}

/*
* Function: isUpcoming
* ----------------------
* Implementation Notes: Function takes the time since epoch and converts it to a std::tm struct pointer,
* so it can be compared to the start date/time (eventDate variable).
*/
bool Event::isUpcoming(){   // https://en.cppreference.com/w/cpp/chrono/c/time
    std::time_t now = std::time (nullptr);
    //std::time(now);
    std::tm *today = std::localtime(&now);
    //std::string date = "Date: " + std::to_string(today -> tm_mon + 1) + "/"  + std::to_string(today -> tm_mday) + "/" + std::to_string(1900 + today->tm_year);
    //std::cout << date << std::endl;
    if (eventDate.tm_year > today->tm_year){
        return true;
    } else if (eventDate.tm_year < today -> tm_year){
        //std::cout << "year" << std::endl;
        return false;
    } else if (eventDate.tm_mon > today -> tm_mon){
        //std::cout << "month" << std::endl;
        return true;
    } else if (eventDate.tm_mon < today -> tm_mon){
        //std::cout << "month" << std::endl;
        return false;
    } else if (eventDate.tm_mday < today -> tm_mday){
        //std::cout << "day" << std::endl;
        return false;
    } else if (eventDate.tm_mday > today -> tm_mday){
        return true;
    } else if (eventDate.tm_hour < today -> tm_hour){
        //std::cout << "hour" << std::endl;
        return false;
    } else if (eventDate.tm_hour > today -> tm_hour){
        return true;
    } else if (eventDate.tm_min < today -> tm_min){
        //std::cout << "min" << std::endl;
        return false;
    }

    return true;
}

std::string Event::getEventName(){
    return eventName;
}

std::tm &Event::getEventDate(){
    return eventDate;
}

std::string Event::getVenue(){
    return venue;
}

std::string Event::getLocationCity(){
    return locationCity;
}

std::string Event::getLocationState(){
    return locationState;
}

int Event::getNumTicketsAvailable(){
    return numTicketsAvailable;
}

int Event::getNumTicketsSold(){
    return numTicketsSold;
}

float Event::getTicketPrice(){
    return ticketPrice;
}

void Event::sellTicket(){
    numTicketsAvailable--;
    numTicketsSold++;
}

std::vector < std::pair <std::string, std::string> > Event::getAttendees(){
    return attendees;
}

void Event::addAttendee(std::string aname, std::string aemail){
    attendees.push_back(std::make_pair(aname, aemail));
    sellTicket();
}

// Constructor for Concert class.
Concert::Concert(std::string ceventName, std::string cvenue, std::string clocationCity, std::string clocationState, int year, int month, int day, int startHour, int startMin,int cnumTicketsAvailable, float cticketPrice,
std::string cartist, std::string cgenre, std::string copener) :
Event::Event(ceventName, cvenue, clocationCity, clocationState, year, month, day, startHour, startMin, cnumTicketsAvailable, cticketPrice) {
    artist = cartist;
    genre = cgenre;
    opener = copener;

}

std::string Concert::getDetails () {
    std::string event = "Concert Name: " + getEventName();
    std::string date = "Date: " + std::to_string(getEventDate().tm_mon + 1) + "/"  + std::to_string(getEventDate().tm_mday) + "/" + std::to_string(1900 + getEventDate().tm_year);
    std::string ampm = "";
    if (getEventDate().tm_hour > 11){
        ampm = "p.m.";
    } else {
        ampm ="a.m.";
    }
    std::string hour = std::to_string(getEventDate().tm_hour % 12);
    if (hour == "0"){
        hour = "12";
    }

    std::string mins1;
    int min1 = getEventDate().tm_min;
    if (min1 < 10){
        mins1 = "0" + std::to_string(min1);
    } else {
        mins1 = std::to_string(min1);
    }
    std::string time = "Time: " + hour + ":" + mins1 + " " + ampm;
    std::string musician = "Artist: " + getArtist();
    std::string gnr = "Genre: " + getGenre();
    std::string opnr = "Opener: " + getOpener();
    std::string ven = "Venue: " + getVenue();
    std::string loc = "Location: " + getLocationCity() + ", " + getLocationState();
    std::string printTicP = std::to_string(getTicketPrice());
    for (int i = 0; i < 4; i++){
        printTicP.pop_back();
    }
    std::string cost = "Price: $" + printTicP;
    std::string avail = "Tickets Left: " + std::to_string(getNumTicketsAvailable());
    return event + "\n" + date + "\n" + time + "\n" +  musician + "\n" + gnr + "\n" + opnr + "\n" + ven + "\n" + loc + "\n" + cost + "\n" + avail + "\n";

}

std::string Concert::getArtist(){
    return artist;
}

std::string Concert::getGenre(){
    return genre;
}


std::string Concert::getOpener(){
    return opener;
}

// Constructor for Conference class
Conference::Conference(std::string ceventName, std::string cvenue, std::string clocationCity, std::string clocationState, int year, int month, int day, int startHour, int startMin, int cnumTicketsAvailable, float cticketPrice,
    std::string cindustry, std::string ceventSponsor, int endYear, int endMonth, int endDay, int endHour, int endMin) : Event::Event(ceventName, cvenue, clocationCity, clocationState, year, month, day, startHour, startMin, cnumTicketsAvailable, cticketPrice) {
        industry = cindustry;
        eventSponsor = ceventSponsor;
        endDate.tm_year = endYear - 1900;
        endDate.tm_mon = endMonth - 1;
        endDate.tm_mday = endDay;
        endDate.tm_hour = endHour;
        endDate.tm_min = endMin;
        endDate.tm_sec = 0;
}

std::string Conference::getIndustry(){
    return industry;
}

//Conference::Session constructor
Conference::Session::Session(std::string cspeaker, std::string ctopic, std::string clocation, int startYear,
int startMonth, int startDay, int startHour, int startMin, int endHour, int endMin){
    speaker = cspeaker;
    topic = ctopic;
    location = clocation;
    startTime.tm_year = startYear - 1900;
    startTime.tm_mon = startMonth - 1;
    startTime.tm_mday = startDay;
    startTime.tm_hour = startHour;
    startTime.tm_min = startMin;
    endTime.tm_year = startYear - 1900;
    endTime.tm_mon = startMonth - 1;
    endTime.tm_mday = startDay;
    endTime.tm_hour = endHour;
    endTime.tm_min = endMin;
}


bool operator< (Conference::Session lhs, Conference::Session rhs){
    if (lhs.startTime.tm_year < rhs.startTime.tm_year){
        return true;
    } else if (lhs.startTime.tm_year > rhs.startTime.tm_year){
        return false;
    } else if (lhs.startTime.tm_mon < rhs.startTime.tm_mon){
        return true;
    } else if (lhs.startTime.tm_mon > rhs.startTime.tm_mon){
        return false;
    } else if (lhs.startTime.tm_mon < rhs.startTime.tm_mon){
        return true;
    } else if (lhs.startTime.tm_mon > rhs.startTime.tm_mon){
        return false;
    } else if (lhs.startTime.tm_mday < rhs.startTime.tm_mday){
        return true;
    } else if (lhs.startTime.tm_mday > rhs.startTime.tm_mday){
        return false;
    } else if (lhs.startTime.tm_hour < rhs.startTime.tm_hour){
        return true;
    } else if (lhs.startTime.tm_hour > rhs.startTime.tm_hour){
        return false;
    } else if (lhs.startTime.tm_min < rhs.startTime.tm_min) {
        return true;
    } else if (lhs.startTime.tm_min > rhs.startTime.tm_min){
        return false;
    }
    return false;
}

bool operator== (Conference::Session lhs, Conference::Session rhs){
    return lhs.startTime.tm_year == rhs.startTime.tm_year && lhs.startTime.tm_mon == rhs.startTime.tm_mon && lhs.startTime.tm_mday == rhs.startTime.tm_mday && lhs.startTime.tm_hour == rhs.startTime.tm_hour && lhs.startTime.tm_hour == rhs.startTime.tm_hour;
}

std::string Conference::getDetails() {
    std::string event = "Conference Name: " + getEventName();
    std::string date = "Dates: " + std::to_string(getEventDate().tm_mon + 1) + "/"  + std::to_string(getEventDate().tm_mday) + "/" + std::to_string(1900 + getEventDate().tm_year)
    + " to " + std::to_string(getEndDate().tm_mon + 1) + "/"  + std::to_string(getEndDate().tm_mday) + "/" + std::to_string(1900 + getEndDate().tm_year) ;
    std::string spons = "Sponsor: " + getEventSponsor();
    std::string ind = "Industry: " + getIndustry();
    std::string ven = "Venue: " + getVenue();
    std::string loc = "Location: " + getLocationCity() + ", " + getLocationState();
    std::string printTicP = std::to_string(getTicketPrice());
        for (int i = 0; i < 4; i++){
            printTicP.pop_back();
        }
    std::string cost = "Cost: $" + printTicP;
    std::string avail = "Spots Left: " + std::to_string(getNumTicketsAvailable());

    event += "\n" + date + "\n" + spons + "\n" +  ind + "\n"  + ven + "\n" + loc + "\n" + cost + "\n" + avail + "\n";

    std::string sessionStuff;
    sessionStuff += std::string("\n\t*** Session Information ***\n");
    if (sessionList.size() == 0){
        sessionStuff += "\tNo sessions currently scheduled.  Please check back later.\n";

    } else{
        for (Session* s : sessionList){
            //std::cout << "endTime Hour, Min " << s->endTime.tm_hour << " " << s->endTime.tm_min<< std::endl;

            std::string speak = "\tSpeaker: " + s->speaker;
            std::string area = "\tTopic: " + s->topic;
            std::string loc = "\tLocation: " + s->location;
            std::string ampm1 = "";
            std::string ampm2 = "";

            if (s->startTime.tm_hour > 11){
                ampm1 = "p.m.";
            } else {
                ampm1 ="a.m.";
            }

            if (s->endTime.tm_hour > 11){
                ampm2 = "p.m.";
            } else {
                ampm2 ="a.m.";
            }

            std::string hour1 = std::to_string(s->startTime.tm_hour % 12);
            if (hour1 == "0"){
                hour1 = "12";
            }

            std::string hour2 = std::to_string(s->endTime.tm_hour % 12);
            if (hour2 == "0"){
                hour2 = "12";
            }

            //std::cout << "hour2 " << hour2 << std::endl;

            std::string mins1;
            int min1 = s->startTime.tm_min;
            if (min1 < 10){
                mins1 = "0" + std::to_string(min1);
            } else {
                mins1 = std::to_string(min1);
            }

            std::string mins2;
            int min2 = s->endTime.tm_min;
            //std::cout << "Ending minutes " << min2 << std::endl;
            if (min2 < 10){
                mins2 = "0" + std::to_string(min2);
            } else {
                mins2 = std::to_string(min2);
            }

            std::string time1 = hour1 + ":" + mins1 + " " + ampm1 + " to " + hour2 + ":" + mins2 + " " + ampm2;
            std::string time = "\tTime: " + std::to_string(s->startTime.tm_mon + 1) +"/" + std::to_string(s -> startTime.tm_mday) + "/" + std::to_string(1900 + s->startTime.tm_year) +
                               " " + time1;

           sessionStuff += speak + "\n" + area + "\n" + loc + "\n" + time + "\n\n";


        }
    }
    return event + sessionStuff;
}

void Conference::addSession(std::string cspeaker, std::string ctopic, std::string clocation, int startYear, int startMonth,
                                int startDay, int startHour, int startMin, int endHour, int endMin){
    sessionList.push_back(new Session(cspeaker, ctopic, clocation, startYear, startMonth, startDay, startHour, startMin, endHour, endMin));
}

std::vector<Conference::Session*> Conference::getSessionList(){
    return sessionList;
}

std::string Conference::getEventSponsor(){
    return eventSponsor;
}

std::tm &Conference::getEndDate(){
    return endDate;
}

// Need to remove session pointers from heap.
Conference::~Conference(){
    for (Conference::Session* sesh : sessionList){
        delete sesh;
    }
}





        

    



