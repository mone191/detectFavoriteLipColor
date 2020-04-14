#pragma once
#include "ofxState.h"
#include "sharedData.h"

#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"
#include "FaceOverlay.h"

class stateB : public itg::ofxState<sharedData>{ //ofxStateを継承
    
    void setup();
    void update();
    void draw();
    
    float winScale;
    float threshold;
    int time;
    int x,y,w,h;
    
    ofVideoGrabber cam;
    cv::Mat camMat;
    cv::Mat faceMat;
    cv::Rect roi;
    cv::Rect faceRoi;
    ofImage dstImage;
    ofImage faceImage;
    ofxCv::ContourFinder contourFinder;
    ofColor targetColor;
    ofxFaceTracker tracker;
    ofxFaceTracker tracker2;
    FaceOverlay overlay;
    
    string getName(); //状態の名前を返す関数
//    ofTrueTypeFont text;
    ofImage heartimage1;
    ofImage heartimage2;
};
