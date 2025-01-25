/*
* File: eventFactory.h
* -------------
* This interface defines the EventFactory class
*/

#ifndef _eventFactory_h
#define _eventFactory_h

#include "event.h"
#include <vector>
#include <ctime>
#include <string>
#include <iostream>


/*
 * Class: EventFactory
 * ------------
 * An abstract class for creating event object.
 * Child classes will be "factories" for creating events of varying types.
 */
class EventFactory{

    public:

        // Constructor for EventFactory class
        EventFactory();

        // Pure virtual fucntion createEvent() that must be overridden in the child classes.
        // The purpose of this function will be to call a Constructor to create and store a new object on the heap.
        virtual Event* createEvent() = 0;

        //Destructor for EventFactory class.
        ~EventFactory(){}

};

/*
 * Class: ConcertFactory
 * ------------
 * Inherits publicly from EventFactory
 */
class ConcertFactory : public EventFactory{

    public:
        // Constructor for ConcertFactory class
        ConcertFactory();

        Concert* createEvent() override;

        // Destructor for ConcertFactory class
        ~ConcertFactory(){}

};

/*
 * Class: ConferenceFactory
 * ------------
 * Inherits publicly from EventFactory
 */
class ConferenceFactory : public EventFactory {

    public:
        //Constructor ConferenceFactory class
        ConferenceFactory();

        Conference* createEvent() override;

        //method to add a session to a Conference object using the ConferenceFactory class.
        void addToConferenceSchedule(Conference* conf);

        // Destructor for ConferenceFactory class
        ~ConferenceFactory(){}

};

#endif