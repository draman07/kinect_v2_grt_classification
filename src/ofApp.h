/*
  This example demonstrates how to use the GRT ANBC algorithm in openFrameworks. See the README file for more info.
 */

#pragma once

#include "ofMain.h"
#include "ofxGrt.h"
//#include "SynapseStreamer.h"
#include "ofxKinectV2OSC.h"
#include <stdio.h>

//State that we want to use the GRT namespace
using namespace GRT;

#define PRE_RECORDING_COUNTDOWN_TIME 2000
#define RECORDING_TIME 5000

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //Create some variables for the demo
    ClassificationData trainingData;      		//This will store our training data
    GestureRecognitionPipeline pipeline;        //This is a wrapper for our classifier and any pre/post processing modules 
    bool recordTrainingData;                                //This is a flag that keeps track of when we should record training data
    bool trainingModeActive;
    bool predictionModeActive;
    bool drawInfo;
    VectorFloat leftHand;
    VectorFloat rightHand;
    UINT trainingClassLabel;                    //This will hold the current label for when we are training the classifier
    UINT predictedClassLabel;
    string infoText;                            //This string will be used to draw some info messages to the main app window
    ofTrueTypeFont largeFont;
    ofTrueTypeFont smallFont;
    ofTrueTypeFont hugeFont;
//    SynapseStreamer synapseStreamer;
    ofxGrtTimeseriesPlot leftHandPlot;
    ofxGrtTimeseriesPlot rightHandPlot;
    ofxGrtTimeseriesPlot predictionPlot;
    Timer trainingTimer;
    
    ofxKinectV2OSC kinect;
    Skeleton* skeleton;
    vector<Skeleton>* skeletons;
    

};
