//// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com
//  Mover.cpp
//  NOC_1_10_motion101_OF
//
//
//

#include "Mover.h"

Mover::Mover() {
    location.set(400,50);
    velocity.set(1,0);
    acceleration.set(0,0);
    mass = 1;
}

void Mover::init(float m, float x , float y){
	mass = m;
    location.set(x,y);
    velocity.set(1, 0);
    acceleration.set(0, 0);
}

void Mover::applyForce(ofVec2f force) {
    ofVec2f f;
    f.set(force / mass);
    acceleration +=f;
}

void Mover::update() {
	
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
	
}

void Mover::display(){
    ofFill();
    ofSetColor(0, 100);
	ofEnableAlphaBlending();
    ofEllipse(location.x, location.y, mass*25, mass*25);
	ofDisableAlphaBlending();
    
    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(1);
    ofEllipse(location.x, location.y, mass*25, mass*25);
}

void Mover::checkEdges(){
    
    if (location.x > ofGetWidth()) {
	location.x = 0;
    }
    else if (location.x < 0) {
	location.x = ofGetWidth();
    }
    
    if (location.y > ofGetHeight()) {
        velocity.y *= -1;
        location.y = ofGetHeight();
    }
}