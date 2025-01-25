/*
* File: eventFactory.cpp
* ---------------
* This file implements the EventFactory class
*
* Implementation Notes:
* Several functions take user input via the istream, which I know is not best practice in real world applications.
* However, advised by Dr. Wagner that it was good to leave my function this way, as it simplifies my main()
* and does not require an additional "utility" class to collect information from the user.
* Remaining implementations notes are minimal, as implementation is straightforward.
*/

#include "event.h"
#include "eventFactory.h"
#include <vector>
#include <ctime>
#include <string>
#include <iostream>

EventFactory::EventFactory(){}


ConcertFactory::ConcertFactory(){}

// Function asks user the necessary questions, taking input via istream, to build a Concert object.
// Once information is gathered, calls the Concert constructor and returns a pointer to a Concert object.
Concert* ConcertFactory::createEvent(){
    std::cin.ignore();
    std::string name;
    std::string venue;
    std::string city;
    std::string state;
    std::string artist;
    std::string genre;
    std::string opener;
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    float price;
    int tickets;

    std::string buffer;

    std::cout << "What is the concert name? ";
    std::getline(std::cin, name);
    std::cout << "What is the artist? ";
    std::getline(std::cin, artist);
    std::cout << "What is the music genre? ";
    std::getline(std::cin, genre);
    std::cout << "Who is the opener? ";
    std::getline(std::cin, opener);
    std::cout << "What is the event date month? ";

    std::cin >> month;
    std::cout << "What is the event date day? ";
    std::cin >> day;
    std::cout << "What is the event date year? ";
    std::cin >> year;

    std::cout << "What is the start time hour (0 -23)? ";
    std::cin >> hour;
    std::cout << "What is the start time minute (0 - 59)? ";
    std::cin >> minutes;

    std::cin.ignore();
    std::cout << "What is the event venue? " ;
    std::getline(std::cin, venue);
    std::cout << "What is the even location city? " ;
    std::getline(std::cin, city);
    std::cout << "What is the event location state (e.g., AL)? " ;
    std::cin >> state;
    std::cout << "What is the ticket price? ";
    std::cin >> price;
    std::cout << "How many tickets are available? ";
    std::cin >> tickets;
    return new Concert(name, venue, city, state, year, month, day, hour, minutes, tickets, price, artist, genre, opener);
}

// ConferenceFactory constructor.
ConferenceFactory::ConferenceFactory(){}

// Function asks user the necessary questions, taking input via istream, to build a Conference object.
// Once information is gathered, calls the Conference constructor and returns a pointer to a Conferenece object.
Conference* ConferenceFactory::createEvent(){
    std::cin.ignore();
    std::string name;
    std::string industry;
    std::string sponsor;
    std::string venue;
    std::string city;
    std::string state;
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int endYear;
    int endMonth;
    int endDay;
    int endHour;
    int endMinutes;
    float price;
    int tickets;

    std::string buffer;

    std::cout << "What is the conference name? ";
    std::getline(std::cin, name);
    std::cout << "What industry is represented? ";
    std::getline(std::cin, industry);
    std::cout << "Who is the event sponsor? ";
    std::getline(std::cin, sponsor);

    std::cout << "What is the event start date month? ";

    std::cin >> month;
    std::cout << "What is the event start date day? ";
    std::cin >> day;
    std::cout << "What is the event start date year? ";
    std::cin >> year;

    std::cout << "What is the start time hour (0 -23)? ";
    std::cin >> hour;
    std::cout << "What is the start time minute (0 - 59)? ";
    std::cin >> minutes;
    std::cout << "What is the event end date month? ";

    std::cin >> endMonth;
    std::cout << "What is the event end date day? ";
    std::cin >> endDay;
    std::cout << "What is the event end date year? ";
    std::cin >> endYear;
    std::cout << "What is the end time hour (0 -23)? ";
    std::cin >> hour;
    std::cout << "What is the end time minute (0 - 59)? ";
    std::cin >> minutes;
    std::cin.ignore();
    std::cout << "What is the event venue? " ;
    std::getline(std::cin, venue);
    std::cout << "What is the even location city? " ;
    std::getline(std::cin, city);
    std::cout << "What is the event location state (e.g., AL)? " ;
    std::cin >> state;
    std::cout << "What is the ticket price? ";
    std::cin >> price;
    std::cout << "How many tickets are available? ";
    std::cin >> tickets;
    return new Conference(name, venue, city, state, year, month, day, hour, minutes, tickets, price, industry, sponsor, endYear, endMonth, endDay, endHour, endMinutes);
}

// Function asks user the necessary questions, taking input via istream, to build a Session struct.
// Once information is gathered, calls addSession() method to add a session to a the sessionList variable of a Conference object.
void ConferenceFactory::addToConferenceSchedule(Conference* conf){
    std::string spea1;
    std::string top1;
    std::string loc1;
    int sYear;
    int sMonth;
    int sDay;
    int sHour;
    int sMin;
    int eHour;
    int eMin;
    std::cout << "What is the session topic? " ;
    std::getline(std::cin, top1);
    std::cout << "Who is the session speaker? ";
    std::getline(std::cin, spea1);
    std::cout << "What is the session location? ";
    std::getline(std::cin, loc1);
    std::cout << "What is the session year? ";
    std::cin >> sYear;
    std::cout << "What is the session month (1 - 12)? ";
    std::cin >> sMonth;
    std::cout << "What is the session day (1 - 31)? ";
    std::cin >> sDay;
    std::cout << "What is the session start hour (0 - 23)? ";
    std::cin >> sHour;
    std::cout << "What is the session start min (0 - 59)? " ;
    std::cin >> sMin;
    std::cout << "What is the session end hour (0 - 23)? ";
    std::cin >> eHour;
    std::cout << "What is the session end min (0 - 59)? " ;
    std::cin >> eMin;
    conf->Conference::addSession(spea1, top1, loc1, sYear, sMonth, sDay, sHour, sMin, eHour, eMin);
}

