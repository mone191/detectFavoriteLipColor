#include "stateB.h"
using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void stateB::setup(){
    cam.setDeviceID(3);
    cam.initGrabber(800, 600);

    winScale = ofGetWidth() / cam.getWidth();
    ofBackground(0);
    
    tracker.setup();
    tracker2.setup();
    contourFinder.setMinAreaRadius(0.2);
    contourFinder.setMaxAreaRadius(3);
    contourFinder.setTargetColor((102,82,86));
    contourFinder.setThreshold(30);
    
//    ofTrueTypeFontSettings settings("abc.ttc",6);
//    settings.addRanges(ofAlphabet::Emoji);//絵文字
//    settings.addRanges(ofAlphabet::Japanese);//日本語
//    settings.addRange(ofUnicode::Space);//スペース
//    settings.addRange(ofUnicode::IdeographicSpace);//全角スペース
//    settings.addRange(ofUnicode::Latin);//アルファベット等
//    settings.addRange(ofUnicode::Latin1Supplement);//記号、アクサン付き文字など
//    settings.addRange(ofUnicode::NumberForms);//数字？
//    settings.addRange(ofUnicode::Arrows);//矢印
//    settings.addRange(ofUnicode::MathOperators);//数式記号
//    settings.addRange(ofUnicode::Hiragana);//ひらがな
//    settings.addRange(ofUnicode::Katakana);//カタカナ
//    settings.addRange(ofUnicode::MiscSymbolsAndPictographs);//絵文字など
//    settings.addRange(ofUnicode::Emoticons);//エモーティコン
//    text.load(settings); // 設定をロード
//    text.setLetterSpacing(1.2);//文字間 デフォルトは1.0 文字間をより開ける場合は1.0を超える値を指定する

    heartimage1.load("heart1.png");
    heartimage2.load("heart2.png");
    
}

//--------------------------------------------------------------
void stateB::update(){
    cam.update();
    
    if(cam.isFrameNew()) {
        unsigned char * pixels = cam.getPixels().getData();
        
        cv::Mat faceMat(cv::Size(800,600),CV_8UC3,pixels);
        cv::Rect faceRoi = cv::Rect(315,175,170,250);
        faceMat = faceMat(faceRoi).clone();
        faceImage.setFromPixels(faceMat.data, faceMat.cols, faceMat.rows, OF_IMAGE_COLOR);
        faceImage.mirror(false, true);
        tracker.update(toCv(faceImage));
        tracker2.update(toCv(cam));
        
        x = tracker2.getImagePoint(36).x;
        y = tracker2.getImagePoint(37).y;
        w = tracker2.getImagePoint(39).x - tracker2.getImagePoint(36).x;
        h = tracker2.getImagePoint(41).y - tracker2.getImagePoint(37).y;
        x = x-w*0.5;
        y = y-h*0.5;
        w = w*2;
        h = h*2;
        std::cout << "x; " <<  x << endl;
        std::cout << "y; " <<  y << endl;
        std::cout << "w; " <<  w << endl;
        std::cout << "h; " <<  h << endl;
        if (x <= 0 || y<= 0 || w <= 0 || h<= 0){
        }else{
            
            cv::Mat camMat(cv::Size(800,600),CV_8UC3,pixels);
            cv::Rect roi = cv::Rect(x,y,w,h);
            camMat = camMat(roi).clone();
            dstImage.setFromPixels(camMat.data, camMat.cols, camMat.rows, OF_IMAGE_COLOR);
            contourFinder.findContours(dstImage);
        }
       
    }
    
}

//--------------------------------------------------------------
void stateB::draw(){
    
    
    int time2 = ofGetElapsedTimeMillis() - getSharedData().time;
    time2 = time2/1000;
    time2 = time2/2;
    ofColor c;
    
    
    
    ofTranslate(360,-30);
    ofScale(5, 4);
    ofSetColor(255);
    //faceImage.draw(0, 0);
    faceMat.release();
    faceMat=ofxCv::toCv(cam);
    
    ofSetColor(255, 255, 255);
    ofSetLineWidth(10);
    ofNoFill();
    ofRect(-10,20,150,190);
    
    
    ofSetColor(255);
    //dstImage.draw(0,0);
    camMat.release();
    camMat=ofxCv::toCv(cam);
    
    ofSetLineWidth(2);
    ofNoFill();
    int n = contourFinder.size();
    if (n == 1) {
        for(int i = 0; i < n; i++) {
            // ellipse that best fits the contour
            ofSetColor(magentaPrint);
            cv::RotatedRect ellipse = contourFinder.getFitEllipse(i);
            ofPushMatrix();
            ofVec2f ellipseCenter = toOf(ellipse.center);
            ofVec2f ellipseSize = toOf(ellipse.size);
            ofTranslate(ellipseCenter.x, ellipseCenter.y);
            ofRotate(ellipse.angle);
            //ofDrawEllipse(0, 0, ellipseSize.x, ellipseSize.y);
            //            char sizeStr[255];
            //            sprintf(sizeStr, "%f", ellipseSize.y);
            //            text.drawString("pupil size:", 130, 200);
            //            text.drawString(sizeStr, 150,200);
            std::cout << "ellipseSize.x; " <<  ellipseSize.x << endl;
            std::cout << "ellipseSize.y; " <<  ellipseSize.y << endl;
            std::cout << "ellipseCenter.x; " <<  ellipseCenter.x << endl;
            std::cout << "ellipseCenter.y; " <<  ellipseCenter.y << endl;
            if(ellipseSize.y >= 10){
                std::cout << "pupilDetect!!!!! " << endl;
//                std::cout << "heartwidth; " <<  heartimage1.getWidth() << endl;
//                std::cout << "heartheight; " <<  heartimage1.getHeight() << endl;
//                ofRotate(-ellipse.angle);
//                ofTranslate(-ellipseSize.x, -ellipseSize.y);
//                ofSetColor(255, 255, 255);
//                heartimage1.draw(700, 100);
//                heartimage2.draw(-400,400);
                if (getSharedData().timeNumber != 0){
                    if (getSharedData().pupilTime[(getSharedData().timeNumber)-1] != time2){
                        getSharedData().pupilTime[getSharedData().timeNumber] = time2;
                        getSharedData().timeNumber = getSharedData().timeNumber + 1;
                    }
                }else if (getSharedData().timeNumber == 0) {
                    getSharedData().pupilTime[0] = time2;
                    getSharedData().timeNumber = getSharedData().timeNumber + 1;
                }
            }
            ofPopMatrix();
        }
        
        
    }
    
    
    
    
    
    
    ofPushStyle();
    
    c.setHsb(210+5*time2, 255, 255);
    ofSetColor(c);
    ofSetLineWidth(100);
    ofFill();
    overlay.draw(tracker);
    std::cout << "time2: " << time2 << endl;
    std::cout << "hsv: " << c.getHue() << endl;
    
    
    
    
   
    ofPopStyle();
    if (time2 > 13){
        if (getSharedData().timeNumber >=15){
            getSharedData().timeNumber = 14;
        }
        for (int i=0;i<getSharedData().timeNumber;i++){
            if (getSharedData().pupilTime[i] > 13){
                getSharedData().timeNumber = i-1;
                break;
            }
        }
        if (getSharedData().timeNumber ==0){
            getSharedData().timeNumber = 2;
            getSharedData().pupilTime[0] = 2;
            getSharedData().pupilTime[1] = 3;
        }
        //getSharedData().timeNumber = 14;
        changeState("stateC");
        std::cout << "pupilTime; " <<  getSharedData().pupilTime[5] << endl;
        std::cout << "timeNumber; " <<  getSharedData().timeNumber << endl;
        
    }
}

string stateB::getName() {
    return "stateB";
}

