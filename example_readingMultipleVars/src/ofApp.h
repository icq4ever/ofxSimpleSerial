#pragma once

#include "ofMain.h"
#include "ofxSimpleSerial.h"
#include <vector>
#include "ofUtils.h"

using namespace std;

class ofApp : public ofBaseApp{
	
	public:
	
		ofxSimpleSerial	serial;
		string		message;
		bool		red;
		bool		green;
		bool		blue;
		bool		requestRead;
	
		void		setup();
		void		update();
		void		draw();
		void		mousePressed(int x, int y, int button);
		void		onNewMessage(string & message);
		
	protected:
		
};	


