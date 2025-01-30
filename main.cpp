/*
* File: main.cpp
* --------------
* main file to run Event Management System project
* To Compile: make
* To Run: make run
*/

#include <iostream>
#include <string>
#include <vector>
#include "event.h"
#include "eventFactory.h"
#include "searchingStrategy.h"
#include "searchingContext.h"

int main(){

    std::vector< Event*> eventDB;

    // Pre-loading a few events here, so the program is functional from start-up.
    Conference* myConf = new Conference("UAB Computer Science Conference", "Unviersity Hall", "Birmingham", "AL", 2025, 6, 13, 0, 0, 0, 200, "Technology", "UAB CS Department", 2025, 6, 15, 18, 0);

    myConf->addSession("Dr. Amber Wagner", "Computer Science Education", "UH 1009", 2025, 6, 13, 18, 15, 20, 30);

    myConf->addSession("Dr. John Johnstone", "Computer Vision", "UH 1011", 2025, 6, 14, 17, 00, 19, 30);

    myConf->addSession("Dr. Mahmut Unan", "Medical Imaging", "UH 2100", 2025, 6, 15, 8, 30, 10, 30);

    Conference* myConf2 = new Conference("51st ACM SIGPLAN Symposium on Principles of Programming Languages (POPL 2024)", "Institution of Engineering & Technology", "London (UK)", "NA", 2024, 1, 14, 10, 0, 2000, 400, "Computer Science Research", "ACM", 2024, 1, 20, 10, 00);

    myConf2->addSession("Dr. Will Crichton, Dr. Shriram Krishnamurthi", "A Core Calculus for Documents: Or, Lambda: The Ultimate Document", "Turing Lecture", 2024, 1, 17, 17, 10, 17, 30);

    myConf2->addSession("Dr. John Cyphert, Dr. Zachary Kincaid", "Solvable Polynomial Ideals: The Ideal Reflection for Program Analysis", "Kelvin Lecture", 2024, 1, 19, 10, 30, 10, 50);

    Concert* myConc = new Concert ("James Taylor Carolina On My Mind Tour", "Dean Dome", "Chapel Hill", "NC", 2024, 11, 18, 20, 05, 1000, 150.50, "James Taylor", "folk", "Joni Mitchell");

    Conference* myConf3 = new Conference("52nd ACM SIGPLAN Symposium on Principles of Programming Languages (POPL 2025)", "Curtis Hotel", "Denver", "CO", 2025, 1, 19, 0, 0, 2000, 400, "Computer Science Research", "ACM", 2025, 1, 24, 0, 0);

    Concert* myConc2 = new Concert("Billy Joel Welcome Back Tour", "Madison Square Garden", "New York", "NY", 2025, 3, 15, 20, 30, 5000, 200, "Billy Joel", "Rock", "NA");

    Concert* myConc3 = new Concert("The Saviors Tour", "Oracle Park", "San Francisco", "CA", 2024, 9, 20, 20, 0, 10000, 200, "Green Day", "Punk", "The Smashing Pumpkins");

    eventDB.push_back(myConf);
    eventDB.push_back(myConc);
    eventDB.push_back(myConf2);
    eventDB.push_back(myConf3);
    eventDB.push_back(myConc2);
    eventDB.push_back(myConc3);

    ConcertFactory concerts;

    ConferenceFactory conferences;

    int option;


    // User menu to select options
    std::cout << "***************************************************************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome to the Event Management System!" << "\n" << std::endl;

    std::cout << "Please type the corresponding number to select from the options below: " << std::endl;
    std::cout << "1) Create a new event" << std::endl;
    std::cout << "2) Search for events and Buy Ticket/RSVP" << std::endl;
    std::cout << "3) Display all upcoming events" << std::endl;
    std::cout << "4) Exit the System" << std::endl;
    std::cout << std::endl;
    std::cout << "***************************************************************************************************\n" << std::endl;

    std::cout << "Make your selection: ";
    std::cin >> option;
    //std::cout << option << std::endl;

    while(option != 1 && option != 2 && option != 3 && option != 4 && option != 0){
        std::cout << "Please select a valid option: ";
        std::cin >> option;
    }

    std::cout << std::endl;
    while(option != 4){
        if (option == 0){
            // Trying to prevent the program from entering an infinite loop if something other than an integer value is entered.
            // Having the program end is preferable over the infinite loop.
            // According to our lecture on Streams, option value would be set to 0 if there is an error detected.
            // And input will no longer be accepted.
            std::cout << "Inavlid entry, an integer value was expcted.  Please restart program." << std::endl;
            break;
        }
        switch (option){
            //Adding events to database    
            case 1:
				int type;
				std::cout << "***************************************************************************************************" << std::endl;
				std::cout << "To select an event type, please type the corresponding number: " << std::endl;
				std::cout << "1) Concert " << std::endl;
				std::cout << "2) Conference " << std::endl;
				std::cout << "***************************************************************************************************" << std::endl;
                std::cout << std::endl;
				std::cout << "Make your selection: ";

				std::cin >> type;
                while (type != 1 && type != 2){
                    std::cout << "Please provide a valid selection: " ;
                    std::cin >> type;
                }
                std::cout << std::endl;
                std::cout << "***************************************************************************************************" << std::endl;

                // Add a concert
				if (type == 1){
                    std::cout << std::endl;
                    Event* myConcert = concerts.createEvent();
					eventDB.push_back(myConcert);
                // Add a conference
				} else if (type == 2){
                    char opt;
                    Conference* myConference = conferences.createEvent();
                    std::cout << "Do you want to add any sessions to the conference (y/n).  Please note all sessions must start and end on the same day? ";
                    std::cin >> opt;
                    while(opt != 'y' && opt != 'n'){
                        std::cout << "Please provide a valid response? " ;
                        std::cin >>opt;
                    }
					if (opt == 'y') {
                    	int numSessions;
                    	std::cout << "How many sessions would you like to add? ";
                    	std::cin >> numSessions;
                    	while (numSessions <= 0){
                        	std::cout << "Please provide a valid number of sessions (greater than 0): ";
                        	std::cin >>numSessions;
                    	}
                    	//std::cin.ignore();
                    	for (int i = 0; i < numSessions; i++){
                        	std::cin.ignore();
                        	std::cout << "*** Session " << i + 1 << " Information ***" << std::endl;
                        	conferences.addToConferenceSchedule(myConference);
                    	}
					}
                    std::cin.ignore();
                    eventDB.push_back(myConference);
                }

                break;
            // Searching for Events
            case 2: {   // https://stackoverflow.com/questions/61708267/jump-bypasses-variable-initialization-in-switch-statement
                std::cout << "***************************************************************************************************" << std::endl;
				std::cout << "SEARCH & BUY TICKET/RSVP SYSTEM" << std::endl;
                std::cout << "To select a search criteria, please type the corresponding number: " << std::endl;
				std::cout << "1) Event Name " << std::endl;
				std::cout << "2) Event Location " << std::endl;
                std::cout << "3) Event Start Date " << std::endl;
                std::cout << "4) Tickets Available for Future Event" << std::endl;
				std::cout << "***************************************************************************************************\n" << std::endl;
                std::cout << std::endl;
                int searchType;
                std::cout << "Make your selection: ";
                std::cin >> searchType;

                while (searchType != 1 && searchType != 2 && searchType != 3 && searchType != 4){
                    std::cout << "Please provide a valid selection: " ;
                    std::cin >> searchType;
                }
                std::cout << "***************************************************************************************************" << std::endl;
                
                std::vector <Event*> result;
                if (searchType == 1){
                    std::cout << "**** EVENT NAME SEARCH ****" << std::endl;
                    std::cout << std::endl;
                    std::cout << "Please provide an event name to search: ";
                    std::cin.ignore();
                    std::string pName;
                    std::getline(std::cin, pName);
                    SearchingContext nameSearch(new EventNameSearch(pName));
                    result = nameSearch.performSearch(eventDB);
                    delete nameSearch.getSearchingStrategy();

                } else if (searchType == 2){
                    std::cout << "**** LOCATION SEARCH ****" << std::endl;
                    std::cin.ignore();
                    std::string locCity;
                    std::string locState;
                    std::cout << "Please provide an event location city to search: ";
                    std::getline(std::cin, locCity);
                    std::cout << "Please provide an event state city to search (e.g., AL): ";
                    std::getline(std::cin, locState);
                    SearchingContext locationSearch(new EventLocationSearch(locCity, locState));
                    result = locationSearch.performSearch(eventDB);
                    delete locationSearch.getSearchingStrategy();


                } else if (searchType == 3){
                    std::cout << "**** DATE SEARCH ****" << std::endl;
                    int searchMonth;
                    int searchDay;
                    int searchYear;
                    std::cout << "Please provide an event start month to search (1 - 12): ";
                    std::cin >> searchMonth;
                    std::cout << "Please provide an event start day city to search (1 - 31): ";
                    std::cin >> searchDay;
                    std::cout << "Please provide an event start year to search: ";
                    std::cin >> searchYear;
                    SearchingContext eventDateSearch(new EventDateSearch(searchMonth, searchDay, searchYear));

                    result = eventDateSearch.performSearch(eventDB);
                    delete eventDateSearch.getSearchingStrategy();

                } else if (searchType == 4){
                    std::cout << "**** TICKETS REMAINING SEARCH ****" << std::endl;
                    SearchingContext ticsSearch(new TicketsAvailSearch());
                    result = ticsSearch.performSearch(eventDB);
                    delete ticsSearch.getSearchingStrategy();
                }
                int canPurchase = 0; // initialize the ability to purchase tickets for any event in this search criteria to 0.
                std::cout << std::endl;
                std::cout << "**** SEARCH RESULTS ****\n" << std::endl;
                if (result.size() == 0){
                    std::cout << "No events found." << std::endl;
                } else {
                    for (int i = 0; i < result.size(); i++){
                        std::cout << "Event " << i + 1 << ": " << std::endl;
                        std::cout << result[i] -> getDetails() << std::endl;
                        if (result[i]->isUpcoming() != 0 && result[i] -> getNumTicketsAvailable() != 0){
                            canPurchase = 1; //set to 1 once find at least one event for which tickets are available and the event is in the future.
                        }
                    }

                    if (canPurchase == 0){
                        std::cout << "No events meeting your search criteria are in the future and have tickets available for purchase. " << std::endl;
                        std::cout << "Please try another search." << std::endl;
                    }

                    // If there are upcoming events with tickets available that also meet the search critera,
                    // the option to purchase tickets is available.
                    std::cout << std::endl;
                    if (canPurchase == 1){
                        std::cout << "***************************************************************************************************" << std::endl;
                        std::cout << std::endl;
                        std::cout << "Would you like to purchase a ticket and RSVP (y/n)? ";
                        std::string purchasing;
                        std::cin >> purchasing;
                        while(purchasing != "y" && purchasing != "n"){
                            std::cout << "Please provide a valid option: ";
                            std::cin >> option;
                        }
                        std::cin.ignore();

                        if (purchasing == "y"){
                            int eventNum;
                            std::cout << std::endl;
                            std::cout << "Enter the number of the event you would like to attend. Remember to select upcoming events only."<< std::endl;
                            std::cout << "Make your selection: ";
                            std::cin >> eventNum;

                            while (eventNum < 1 || eventNum > result.size()){
                                std::cout << "Please select a valid event number: ";
                                std::cin >> eventNum;
                            }

                            while (result[eventNum -1]->isUpcoming() == 0 || result[eventNum - 1] -> getNumTicketsAvailable() == 0){
                                std::cout << "Please select an upcoming event with tickets available: ";
                                std::cin >> eventNum;
                            }
                            std::cout << std::endl;
                            std::cout << "A ticket for " << result[eventNum - 1]->getEventName() << " costs $" << result[eventNum - 1]->getTicketPrice() << std::endl;
                            std::cout << "Would you like to continue with your purchase (y/n)? " ;
                            std::string contPurchase;
                            std::cin >> contPurchase;

                            while(contPurchase != "y" && contPurchase != "n"){
                                std::cout << "Please provide a valid option: ";
                                std::cin >> option;
                            }
                            if (contPurchase == "y"){

                                std::string rsvpName;
                                std::string rsvpEmail;
                                std::cin.ignore();
                                std::cout << "What name should go with the ticket purchase? ";
                                std::getline(std::cin, rsvpName);
                                std::cout << "What email address should we send the digital ticket to? ";
                                std::getline(std::cin, rsvpEmail);
                                result[eventNum -1]->addAttendee(rsvpName, rsvpEmail);
                                std::cout << std::endl;
                                std::cout << "Congratulations on your purchase! " << rsvpName <<  " has been added to the RSVP list." << std::endl;
                                std::cout << "Your digital ticket has been sent to " << rsvpEmail << std::endl;
                                std::cout << std::endl;
                                std::cout << "There are now " << result[eventNum -1]->getNumTicketsAvailable() << " tickets to " << result[eventNum -1]->getEventName() << std::endl;
                                std::cout << std::endl;
                            }

                        }
                    }
                }


                break; }
            // Prints the details for all upcoming events
            case 3:
                std::cout << "***************************************************************************************************" << std::endl;
                std::cout << "UPCOMING EVENTS" << "\n" << std::endl;
                for (Event* event : eventDB){
                    if (event->isUpcoming()){
                        std::cout << event->getDetails() << std::endl;
                    }
                }
                std::cout << "***************************************************************************************************" << std::endl;

                break;

        }

        std::cout << "***************************************************************************************************" << std::endl;
        std::cout << std::endl;

        std::cout << "Please type the corresponding number to select from the options below: " << std::endl;
        std::cout << "1) Create a new event" << std::endl;
        std::cout << "2) Search for events and Buy Ticket/RSVP" << std::endl;
        std::cout << "3) Display all upcoming events" << std::endl;
        std::cout << "4) Exit the System" << std::endl;
        std::cout << std::endl;

        std::cout << "***************************************************************************************************\n" << std::endl;

        std::cout << "Make your selection: " ;
        std::cin >> option;

        while(option != 1 && option != 2 && option != 3 && option != 4 && option != 0){
            std::cout << "Please select a valid option: ";
            std::cin >> option;
        }
        std::cout << std::endl;


    }

    // Need to free memory from heap
    if (eventDB.size() > 0){
        for (Event * dispose : eventDB){
            delete dispose;
        }
    }

    return 0;

}