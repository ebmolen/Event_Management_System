/*
* File: searchingStrategy.h
* -------------
* This interface defines the SearchingStrategy class
*/

#ifndef _searchingStrategy_h
#define _searchingStrategy_h

#include <string>
#include <vector>
#include "event.h"

/*
 * Class: SearchingStrategy
 * ------------
 * An abstract class to create a framework and methods for different searching strategies.
 * Each of its subclasses will establish a searching algorithm to search event object pointers in a
 * database by a different criteria.
 */
class SearchingStrategy{

    public:

        // Constructor for SearchingStrategy class
        SearchingStrategy();

        // Pure virtual method that must be overridden in child classes.  
        // Method will return a vector of Event pointers that meet the specified search criteria.
        // This method in each subclass represents a different searching algorithm.
        virtual std::vector<Event*> eventSearch(std::vector<Event*> &events) = 0;

        //Destructor for SearchingStrategy class.
        virtual ~SearchingStrategy(){}
};

/*
 * Class: EventNameSearch
 * ------------
 * Inherits from SearchingStrategy class publically
 * Class to allow searching by eventName.
 */
class EventNameSearch : public SearchingStrategy {

    private:
		// name variable is the eventName to be searched for within the event database.
        std::string name;

    public:

		// Constructor for EventNameSearch class
        EventNameSearch(std::string cname);

		// Returns a vector of event pointers for which the eventName of the object contains name (variable from EventNameSearch class).
        std::vector<Event*> eventSearch(std::vector<Event*> &events) override;

        ~EventNameSearch(){}

};


/*
 * Class: EventLocationSearch
 * ------------
 * Inherits from SearchingStrategy class publically
 * Class to allow searching by location.
 */
class EventLocationSearch: public SearchingStrategy {

    private:
		// The event database will be searched for events with the combination of city and state.
        std::string city;
        std::string state;

    public:
		// Constructor for EventLocationSearch class
        EventLocationSearch(std::string ccity, std::string cstate);

		// Returns a vector of event pointers for which the eventLocationCity and eventLocationState of the
		// object match city AND state (variables from EventLocatoinSearch class).
        std::vector<Event*> eventSearch(std::vector<Event*> &events) override;

		// Destructor for EventLocationSearch
        ~EventLocationSearch(){}


};


/*
 * Class: EventDateSearch
 * ------------
 * Inherits from SearchingStrategy class publicly
 * Class to allow searching by eventDate (start date of event).
 */
class EventDateSearch: public SearchingStrategy {

    private:
		// The event database will be searched for events with the combination of month, day, and year.
        int month;
        int day;
        int year;

    public:

		// Constructor for EventDateSearch class
        EventDateSearch(int cmonth, int cday, int cyear);

		// Returns a vector of event pointers for which the eventDate.tm_mon, eventDate.tm_mday, and eventDate.tm_yar
		// match month, day, and year (variables from EventDateSearch class)
        std::vector<Event*> eventSearch(std::vector<Event*> &events) override;

		// Destructor for EventDateSearch class
        ~EventDateSearch(){}


};


/* Class: TicketsAvailSearch
 * ------------
 * Inherits from SearchingStrategy class publicly
 * Class to allow searching by whether numTicketsAvailable > 0 and the event is in the future.
 */
class TicketsAvailSearch: public SearchingStrategy {
    public:

		// Constructor for TicketsAvialSearch class
        TicketsAvailSearch();

		// Returns a vector of event pointers for which getnumTicketsAvailable() is > 0.
        std::vector<Event*> eventSearch(std::vector<Event*> &events) override;

		// Destructor for TicketsAvailSearch class
        ~TicketsAvailSearch(){}

};

#endif