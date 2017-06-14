#include "line.h"

//--------------------------------------------------------------
myLine::myLine() {
	this->s = ofRandom(360);
	this->p = ofRandom(360);
	this->radius = ofRandom(this->max_radius);
	this->max_radius = 1024;
	this->noise_s = ofRandom(10);
	this->noise_p = ofRandom(10);
	this->noise_increment = 0.005;

	this->line_color.setHsb(ofRandom(255), 255, 255);
}

//--------------------------------------------------------------
myLine::~myLine() {

}

//--------------------------------------------------------------
void myLine::update() {
	this->s = this->s + ofMap(ofNoise(this->noise_s), 0, 1, -15, 15);
	this->p = this->p + ofMap(ofNoise(this->noise_p), 0, 1, -15, 15);

	this->noise_s += this->noise_increment;
	this->noise_p += this->noise_increment;

	float x = this->radius * cos(this->p * DEG_TO_RAD) * sin(this->s * DEG_TO_RAD);
	float y = this->radius * sin(this->p * DEG_TO_RAD) * sin(this->s * DEG_TO_RAD);
	float z = this->radius * cos(this->s * DEG_TO_RAD);

	this->pre_position = this->position;
	this->position = ofVec3f(x, y, z);

	this->radius = (this->radius + 5) % this->max_radius;
}

//--------------------------------------------------------------
void myLine::draw() {
	ofSetColor(this->line_color, 255);
	ofSphere(this->position, 5);
	if (this->position.distance(ofVec3f()) > this->pre_position.distance(ofVec3f())) {
		//ofLine(this->position, this->pre_position);
	}
}