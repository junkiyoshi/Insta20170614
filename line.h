#pragma once

#include "ofMain.h"

class myLine
{
	public:
		myLine();
		~myLine();
		void update();
		void draw();
	private:
		ofVec3f position, pre_position;
		int radius, max_radius;
		float s, p;
		float noise_s, noise_p;
		float noise_increment;
		ofColor line_color;

};