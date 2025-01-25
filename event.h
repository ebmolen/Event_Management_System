/*
* File: event.h
* -------------
* This interface defines the Event class.
* Functions/variables without explanation should be self-explanatory based upon name.
*/

#ifndef _event_h
#define _event_h

#include <string>
#include <chrono>
#include <vector>
#include <ctime>
#include <set>
#include <compare>

/*
 * Class: Event
 * ------------
 * An abstract class for events.
 * Child classes will be for events of varying types.
 */
class Event {

    //Member Variables for the Event class.
    private:
        std::string eventName;

        std::tm eventDate;

        std::string venue;

        std::string locationCity;

        std::string locationState;

		int numTicketsAvailable;

        int numTicketsSold;

        float ticketPrice;

        // Pair of two string variables: attendee name, attendee e-mail address
        std::vector <std::pair <std::string, std::string> > attendees;

    public:

        //Constructor for Event class
        Event(std::string ceventName, std::string cvenue, std::string clocationCity, std::string clocationState, int year, int month, int day, int startHour, int startMin, int cnumTicketsAvailable, float cticketPrice);

        // Returns true if event is in the future and false if it is not.
        bool isUpcoming();

        // pure virtual function that must be overriden in child classes.
        // Purpose of function will be to display details about an event
        virtual std::string getDetails() = 0;

        // getters for the member variables.
        // No standard setters created because the application functionality does not change events after they are created.
        // A few functions have been created to change events in very specific ways.
        std::string getEventName();

        std::tm &getEventDate();

        std::string getVenue();

        std::string getLocationCity();

        std::string getLocationState();

        int getNumTicketsAvailable();

        int getNumTicketsSold();

        float getTicketPrice();

        std::vector < std::pair <std::string, std::string> > getAttendees();

        // Method that will increase numTicketsSold by one and decrease numTicketsAvailable by one.
        void sellTicket();

        // Method that will add attendee to attendeeList and call sellTicket()
        void addAttendee(std::string aname, std::string aemail);

        // Destructor for Event class.
        virtual ~Event(){}


};

/*
 * Class: Concert
 * ------------
 * Inherits publicly from Event
 */

class Concert : public Event {


    //New member Variables for the Concert class.
    private:
        std::string artist;

        std::string genre;

        std::string opener;

    public:
        //Contructor for the Concert class.
    	Concert(std::string ceventName, std::string cvenue, std::string clocationCity, std::string clocationState, int year, int month, int day, int startHour, int startMin,int cnumTicketsAvailable, float cticketPrice,
    	std::string cartist, std::string cgenre, std::string copener);

        //overrides the pure virtual function.  Returns a string with the details of the event.
        std::string getDetails () override;

        // getters for the Concert's new member variables
        std::string getArtist();

        std::string getGenre();

        std::string getOpener();

        // Desctructor for Concert class
        ~Concert(){}

};

/*
 * Class: Conference
 * ------------
 * Inherits publicly from Event
 */
class Conference: public Event {
        

    //New member Variables for the Conference class.
    private:

        std::string industry;

        // Session struct allows adding sessions to the Conference.
        struct Session {
            std::string speaker;
            std::string topic;
            std::string location;
            std::tm startTime;
            std::tm endTime;

            // Constructor for a Session
            Session(std::string cspeaker, std::string ctopic, std::string clocation, int startYear, int startMonth, int startDay, int startHour, int startMin, int endHour, int endMin);

            //int getEndTimeH();
        };

        // Overloading comarator operators for Sessions as friend functions.
        // Functions ultimately not used in this project but could be useful in organizing a session schedule.
        // A session is "less than" another session if its start time is before the other sesssion.
        // A session is "equal to" another session if its start time is the same as another session.
        friend bool operator< (Session lhs, Session rhs);
        friend bool operator== (Session lhs, Session rhs);

        // vector that holds Session pointers.
        std::vector <Session*> sessionList;

        std::string eventSponsor;

        std::tm endDate;



    public:
        // Constructor for Conference class
        Conference(std::string ceventName, std::string cvenue, std::string clocationCity, std::string clocationState, int year, int month, int day, int startHour, int startMin, int cnumTicketsAvailable, float cticketPrice,
        std::string cindustry, std::string ceventSponsor, int endYear, int endMonth, int endDay, int endHour, int endMin);

        // getters for the Conference class.
        std::string getIndustry();

        // Overriden pure virtula function from parent class.  Displays Conference event details, including a list of sessions.
        std::string getDetails() override;

        std::vector <Session*> getSessionList();

        std::string getEventSponsor();

        std::tm &getEndDate();

        //Method that creates a new Session pointer and adds to sessionList.
        void addSession(std::string cspeaker, std::string ctopic, std::string clocation, int startYear, int startMonth, int startDay, int startHour, int startMin, int endHour, int endMin);

        //Destructor for Conference class.
        ~Conference();

};



#endif