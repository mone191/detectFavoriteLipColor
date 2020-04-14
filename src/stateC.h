#pragma once
#include "ofxState.h"
#include "sharedData.h"

class stateC : public itg::ofxState<sharedData>{ //ofxStateを継承
    
    void setup();
    void update();
    void draw();
    
    
    ofImage qr(int a);
    
    string getName(); //状態の名前を返す関数
    ofImage QR_a;
    ofImage QR_b;
    ofImage QR_c;
    ofImage QR_d;
    ofImage QR_e;
    ofImage QR_f;
    ofImage QR_g;
    ofImage QR_h;
    ofImage QR_i;
    ofImage QR_j;
    ofImage QR_k;
    ofImage QR_l;
    ofImage QR_m;
    ofImage QR_n;
    
    ofTrueTypeFont text;
    
    
};
