#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{	 
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	
	serial.setup("/dev/ttyUSB0", 9600);
	serial.startContinuousRead();
	ofAddListener(serial.NEW_MESSAGE,this,&ofApp::onNewMessage);
	
	message = "";
}

void ofApp::onNewMessage(string & message)
{
	cout << "onNewMessage, message: " << message << "\n";
	
	vector<string> input = ofSplitString(message, ",");
	
	// if(input.size() >= 3)
	// {
	//    red =	input.at(0) == "r";
	//    green =	input.at(1) == "g";
	//    blue =	input.at(2) == "b";
	// }
	for(int i=0; i<input.size(); i++){
		cout << input.at(i) << ", ";
	}
	cout << endl;
}

void ofApp::update()
{
	if(requestRead)
	 {
		cout << "sendRequest\n";
		serial.sendRequest();
		requestRead = false;
	 }
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if(red)
	 {
		ofSetColor(255, 0, 0);
		ofRect(0, 0, 33, 100);
	 }
	if(green)
	 {
		ofSetColor(0, 255, 0);
		ofRect(33, 0, 33, 100);
	 }
	if(blue)
	 {
		ofSetColor(0, 0, 255);
		ofRect(66, 0, 33, 100);
	 }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	requestRead = true;
}
