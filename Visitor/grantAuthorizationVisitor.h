#pragma once
#ifndef _Grant_authorization_Visitor_H
#define _Grant_authorization_Visitor_H
#include "visitor.h"
#include "permit.h"
class Grant_authorization_Visitor : public Visitor {
public:
    void Visit(Customer_ticket* element) override {
        std::cout << "Grant_authorization_Visitor:" << element->Method_Customer_ticket() << " 授予\n";
    }

    void Visit(Athlete_pass* element) override {
        std::cout << "Grant_authorization_Visitor:" << element->Method_Athlete_pass() << " 授予\n";
    }

    void Visit(Referee_evidence* element) override {
        std::cout << "Grant_authorization_Visitor:" << element->Method_Referee_evidence() << " 授予\n";
    }
};
#endif