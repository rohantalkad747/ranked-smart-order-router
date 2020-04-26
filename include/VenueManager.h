//
// Created by Rohan on 4/4/2020.
//

#ifndef UNTITLED1_VENUEMANAGER_H
#define UNTITLED1_VENUEMANAGER_H


#include <vector>
#include "Venue.h"
#include "Logger.h"
#include "Order.h"
#include "Execution.h"

class VenueManager
{
public:
    explicit VenueManager(std::vector<Venue> &venues) : Venues(venues), Log("VenueManager")
    { init(); }

    void add_venue(const Venue &venue);

    void remove_venue(Venue &venue);

    std::vector<Venue> venues(const std::string &symbol);

    void sendOrder(Venue &venue,Order &order);

    void sendOrder(std::string &venueName, Order &order);

    void process_exec(const Execution &exec);

private:
    std::vector<Venue> Venues;
    std::map<std::string, std::vector<Venue>> SymbolVenues;
    Logger Log;

    void init();

    void iterateAndRemove(const std::string &name);
};

#endif //UNTITLED1_VENUEMANAGER_H
