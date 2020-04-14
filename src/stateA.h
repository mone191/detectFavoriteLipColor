#pragma once
#include "ofxState.h"
#include "sharedData.h"

#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"
#include "FaceOverlay.h"

class stateA : public itg::ofxState<sharedData>{ //ofxStateを継承
    
    void setup();
    void update();
    void draw();
    
    float winScalex;
    float winScaley;
    
    
    ofVideoGrabber cam;
    cv::Mat faceMat;
    cv::Rect faceRoi;
    ofImage faceImage;
    ofxFaceTracker tracker;
    FaceOverlay overlay;
    
    string getName(); //状態の名前を返す関数
    
    void drawFacePoints();
    
    ofTrueTypeFont text;
    
};

