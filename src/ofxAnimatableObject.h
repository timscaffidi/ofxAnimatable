//
//  ofxAnimatableObject.h
//  assimpExample
//
//  Created by Timothy Scaffidi on 6/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef assimpExample_ofxAnimatableObject_h
#define assimpExample_ofxAnimatableObject_h
#include "ofMain.h"
#include "ofxAnimatableOfPoint.h"
#include "ofxAnimatableFloat.h"
#include "ofxAnimatableOfColor.h"

class ofxAnimatableObject {
public:
    ofxAnimatableOfPoint position;
    ofxAnimatableFloat width, height;
    ofxAnimatableOfColor color;
    
    ofxAnimatableObject(){
        position.setPosition(ofPoint(0,0,0));
        width.set(0);
        height.set(0);
        color.setColor(ofColor(0,0,0,0));
    }
    
    ofxAnimatableObject(float x, float y, float w, float h, ofColor c){
        setRectangle(ofRectangle(x,y,w,h));
        setColor(c);
    }
    
    ofxAnimatableObject(ofRectangle r, ofColor c){
        setRectangle(r);
        setColor(c);
    }
    
    ofxAnimatableObject(ofRectangle r){
        setRectangle(r);
        setColor(ofColor(255,255,255,255));
    }
    
    ~ofxAnimatableObject(){}
    
    void setRectangle(ofRectangle r){
        position.setPosition(ofPoint(r.x, r.y));
        width.set(r.width);
        height.set(r.height);
    }
    void setPosition(ofPoint p){
        position.setPosition(p);
    }
    void setDimensions(ofVec2f d){
        width.set(d.x);
        height.set(d.y);
    }
    
    void setColor(ofColor c){
        color.setColor(c);
    }

    void setDuration(float d){
        position.setDuration(d);
        width.setDuration(d);
        height.setDuration(d);
        color.setDuration(d);
    }
    
    void setDimensionsDuration(float d){
        width.setDuration(d);
        height.setDuration(d);
    }
    
    void animateTo(ofColor c){
        color.animateTo(c);
    }
    
    void animateTo(ofPoint p){
        position.animateTo(p);
    }
    
    void animateDimensionsTo(ofVec2f v){
        animateDimensionsTo(v.x,v.y);
    }
    
    void animateDimensionsTo(float w, float h){
        width.animateTo(w);
        height.animateTo(h);
    }
    
    void animateTo(ofRectangle r){
        position.animateTo(ofPoint(r.x,r.y));
        width.animateTo(r.width);
        height.animateTo(r.height);
    }
    
    void animateToAfterDelay(ofRectangle r, float d){
        position.animateToAfterDelay(ofPoint(r.x,r.y), d);
        width.animateToAfterDelay(r.width,d);
        height.animateToAfterDelay(r.height,d);
    }
    
    void animateTo(ofRectangle r, ofColor c){
        animateTo(r);
        animateTo(c);
    }
    
    void animateTo(float x, float y, float w, float h){
        animateTo(ofRectangle(x,y,w,h));
    }
    
    void animateTo(float x, float y, float w, float h, ofColor c){
        animateTo(ofRectangle(x,y,w,h));
        animateTo(c);
    }
    
    void update(float ft){
        position.update(ft);
        width.update(ft);
        height.update(ft);
        color.update(ft);
    }
    
    ofPoint getCurrentPosition(){ return position.getCurrentPosition(); }
    float getWidth(){return width.val(); }
    float getHeight(){return height.val(); }    
    ofRectangle getCurrentRectangle(){
        return ofRectangle(position.getCurrentPosition(), width.val(), height.val());
    }
    ofRectangle getTargetRectangle(){
        return ofRectangle(position.getTargetPosition(), width.getTargetValue(), height.getTargetValue());
    }
    ofRectangle getOriginalRectangle(){
        return ofRectangle(position.getOriginalPosition(), width.getOriginalValue(), height.getOriginalValue());
    }
    
    void setCurve( AnimCurve curveStyle_ ){
        position.setCurve(curveStyle_);
        width.setCurve(curveStyle_);
        height.setCurve(curveStyle_);
        color.setCurve(curveStyle_);
    }
    void setRepeatType( AnimRepeat repeat ){
        position.setRepeatType(repeat);
        width.setRepeatType(repeat);
        height.setRepeatType(repeat);
        color.setRepeatType(repeat);
    }
    
    void draw(){
        ofSetColor(color.getCurrentColor());
        ofRect(getCurrentRectangle());
    }
	
    
    void draw(ofTexture &t){
        ofSetColor(color.getCurrentColor());
        t.draw(getCurrentRectangle());
    }
    
//    float getDuration(){ return MAX(position.getDuration(),width.getDuration()); }
//    float getPercentDone(){ return MAX(position.getPercentDone(), width.getPercentDone()); }			
//    bool isAnimating(){return position.isAnimating() || width.isAnimating() || height.isAnimating() ;}
//    bool hasFinishedAnimating(){return position.hasFinishedAnimating() || width.hasFinishedAnimating() || height.hasFinishedAnimating() ;}
//    bool isWaitingForAnimationToStart(){return position.isWaitingForAnimationToStart() || width.isWaitingForAnimationToStart() || height.isWaitingForAnimationToStart() ;}
//    bool isOrWillBeAnimating(){return position.isOrWillBeAnimating() || width.isOrWillBeAnimating() || height.isOrWillBeAnimating() ;}
//    float getCurrentSpeed(){ return MAX(position.getCurrentSpeed(),width.getCurrentSpeed());} ///as a percentage of linear speed
};

#endif
