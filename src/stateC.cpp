#include "stateC.h"

//--------------------------------------------------------------
void stateC::setup(){
    
    QR_a.load("QR_a.png");
    QR_b.load("QR_b.png");
    QR_c.load("QR_c.png");
    QR_d.load("QR_d.png");
    QR_e.load("QR_e.png");
    QR_f.load("QR_f.png");
    QR_g.load("QR_g.png");
    QR_h.load("QR_h.png");
    QR_i.load("QR_i.png");
    QR_j.load("QR_j.png");
    QR_k.load("QR_k.png");
    QR_l.load("QR_l.png");
    QR_m.load("QR_m.png");
    QR_n.load("QR_n.png");
    
    ofTrueTypeFontSettings settings("abc.ttc",12);
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
void stateC::update(){
    
}

//--------------------------------------------------------------
void stateC::draw(){
    ofScale(1.9, 1.5);
    ofScale(1.7, 1.3);
    ofSetColor(255, 255, 255);
    text.drawString("あなたがときめいた色は...", 20, 40);
    
    
    ofColor c;
    int num = getSharedData().timeNumber;
    std::cout << "c:TimeNumber: " << num << endl;
    if (num < 8){
        for (int i=0 ; i<num ; i++){
        int p = getSharedData().pupilTime[i];
        c.setHsb(210+5*getSharedData().pupilTime[i], 255, 255);
        ofSetColor(c);
        ofFill();
//        ofRectangle(75+50*i, 100, 50, 100);
//        qr(i).draw(75+50*i, 220, 50, 50);
        ofRectangle(30+60*i, 20, 50, 100);
        qr(p).draw(30+60*i, 140, 50, 50);
        }}else if (num >= 8){
            for (int i=0 ; i<7 ; i++){
                int p = getSharedData().pupilTime[i];
                c.setHsb(210+5*getSharedData().pupilTime[i], 255, 255);
                ofSetColor(c);
                ofFill();
//                ofRectangle(75+100*i, 100, 50, 50);
//                qr(i).draw(75+100*i, 220, 50, 50);
                ofRectangle(30+60*i, 20, 50, 100);
                qr(p).draw(30+60*i, 140, 50, 50);
            }
            for (int i=7;i <num ; i++){
                int p = getSharedData().pupilTime[i];
                c.setHsb(210+5*getSharedData().pupilTime[i], 255, 255);
                ofSetColor(c);
                ofFill();
//                ofRectangle(75+100*(i-7), 330, 50, 50);
//                qr(i).draw(75+100*(i-7), 450, 50, 50);
                ofRectangle(30+60*(i-7), 250, 50, 50);
                qr(p).draw(30+60*(i-7), 370, 50, 50);
            }
        }
    
    
    
    
}

string stateC::getName() {
    return "stateC";
}

ofImage stateC::qr(int a) {
    switch (a) {
        case 0:
            return (QR_a);
            break;
        case 1:
            return (QR_b);
            break;
        case 2:
            return (QR_c);
            break;
        case 3:
            return (QR_d);
            break;
        case 4:
            return (QR_e);
            break;
        case 5:
            return (QR_f);
            break;
        case 6:
            return (QR_g);
            break;
        case 7:
            return (QR_h);
            break;
        case 8:
            return (QR_i);
            break;
        case 9:
            return (QR_j);
            break;
        case 10:
            return (QR_k);
            break;
        case 11:
            return (QR_l);
            break;
        case 12:
            return (QR_m);
            break;
        case 13:
            return (QR_n);
            break;
            
        default:
            break;
    }
}





