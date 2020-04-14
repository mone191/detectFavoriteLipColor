#include "ofApp.h"
#include "stateA.h"//シーンのインクルード
#include "stateB.h"
#include "stateC.h"


//--------------------------------------------------------------
void ofApp::setup(){
    // SharedDataに情報を格納
    stateMachine.getSharedData().hoge = 10;
    //sharedDataの初期化
    stateMachine.addState<stateA>();  //シーンの追加
    stateMachine.addState<stateB>();
    stateMachine.addState<stateC>();
    
    stateMachine.changeState("stateA");//最初に呼び出すシーン
}


//--------------------------------------------------------------
void ofApp::update(){
   

}

//--------------------------------------------------------------
void ofApp::draw(){
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
