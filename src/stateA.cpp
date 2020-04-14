#include "stateA.h"
using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void stateA::setup(){
    cam.setDeviceID(3);
    cam.listDevices();
    cam.initGrabber(800, 600);
    winScalex = ofGetWidth() / cam.getWidth();
    winScaley = ofGetHeight()/cam.getHeight();
    ofBackground(0);
    tracker.setup();
    
    ofTrueTypeFontSettings settings("abc.ttc",6);
    settings.addRanges(ofAlphabet::Emoji);//絵文字
    settings.addRanges(ofAlphabet::Japanese);//日本語
    settings.addRange(ofUnicode::Space);//スペース
    settings.addRange(ofUnicode::IdeographicSpace);//全角スペース
    settings.addRange(ofUnicode::Latin);//アルファベット等
    settings.addRange(ofUnicode::Latin1Supplement);//記号、アクサン付き文字など
    settings.addRange(ofUnicode::NumberForms);//数字？
    settings.addRange(ofUnicode::Arrows);//矢印
    settings.addRange(ofUnicode::MathOperators);//数式記号
    settings.addRange(ofUnicode::Hiragana);//ひらがな
    settings.addRange(ofUnicode::Katakana);//カタカナ
    settings.addRange(ofUnicode::MiscSymbolsAndPictographs);//絵文字など
    settings.addRange(ofUnicode::Emoticons);//エモーティコン
    text.load(settings); // 設定をロード
    text.setLetterSpacing(1.2);//文字間 デフォルトは1.0 文字間をより開ける場合は1.0を超える値を指定する

}

//--------------------------------------------------------------
void stateA::update(){
    cam.update();
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
        unsigned char * pixels = cam.getPixels().getData();
        cv::Mat faceMat(cv::Size(800,600),CV_8UC3,pixels);
        cv::Rect faceRoi = cv::Rect(315,175,170,250);
        faceMat = faceMat(faceRoi).clone();
        faceImage.setFromPixels(faceMat.data, faceMat.cols, faceMat.rows, OF_IMAGE_COLOR);
        faceImage.mirror(false, true);
        tracker.update(toCv(faceImage));
    }
    
}

//--------------------------------------------------------------
void stateA::draw(){
    ofTranslate(360,-30);
    
    ofScale(5, 4);
    
    ofSetColor(255);
    //faceImage.draw(0,0);
    faceMat.release();
    faceMat=ofxCv::toCv(cam);
    
    
    ofSetColor(255, 255, 255);
    ofSetLineWidth(10);
    ofNoFill();
    ofRect(-10,20,150,190);
    
    ofSetColor(255, 255, 255);
    text.drawString("枠内に顔を入れてください", 20, 200);
    
    


    std::cout << "0番目xは"  << tracker.getImagePoint(0).x << endl;
    std::cout << "0番目yは"  << tracker.getImagePoint(0).y << endl;
    std::cout << "16番目xは"  << tracker.getImagePoint(16).x << endl;
    std::cout << "16番目yは"  << tracker.getImagePoint(16).y << endl;
    std::cout << "8番目xは"  << tracker.getImagePoint(8).x << endl;
    std::cout << "8番目yは"  << tracker.getImagePoint(8).y << endl;

    ofPushStyle();
    ofFill();
    ofSetColor(255,0,0);
    //overlay.draw(tracker);
    if (tracker.getImagePoint(0).x > 10 && tracker.getImagePoint(16).x < 140 && tracker.getImagePoint(8).y < 220){
        changeState("stateB");
        getSharedData().time = ofGetElapsedTimeMillis();
        std::cout << "StateAtime"  << getSharedData().time << endl;
        
    }
    ofPopStyle();
}

string stateA::getName() {
    return "stateA";
}

void stateA::drawFacePoints() {
    tracker.draw();
}


