//
//  Mover.h
//  NOC_1_10_motion101_OF
//
//
//

#pragma once
#include <iostream>
#include "ofMain.h"

class Mover {
    public:
    
    Mover();
    void init();
    void update();
    void display();
    void checkEdges(); 
    
    // The Mover tracks location, velocity, and acceleration 
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    
    // The Mover's maximum speed
    float topspeed;
    
};