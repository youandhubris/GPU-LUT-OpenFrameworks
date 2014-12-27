#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Disable rectangle textures
    ofDisableArbTex();
    
    
    // Load the LUT
    vector<RGB> LUT;
    
    LUTpath = ofToDataPath("threshold.CUBE");
    
    ifstream LUTfile(LUTpath.c_str());
    
    while (!LUTfile.eof()) {
        string LUTline;
        getline(LUTfile, LUTline);
        
        if (LUTline.empty()) continue;
        
        RGB line;
        if (sscanf(LUTline.c_str(), "%f %f %f", &line.r, &line.g, &line.b) == 3) LUT.push_back(line);
    }
    if (LUT.size() != (pow(LUTsize, 3.0))) ofLogError() << "LUT size is incorrect.";

    
    // Create a 3D texture
    // Reference from http://content.gpwiki.org/index.php/OpenGL:Tutorials:3D_Textures
    glEnable(GL_TEXTURE_3D);
    
    glGenTextures(1, &texture3D);
    glBindTexture(GL_TEXTURE_3D, texture3D);
    
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    
    glTexImage3D(GL_TEXTURE_3D, 0, GL_RGB, LUTsize, LUTsize, LUTsize, 0, GL_RGB,
                 GL_FLOAT, &LUT[0]);
    
    glBindTexture(GL_TEXTURE_3D, 0);
    glDisable(GL_TEXTURE_3D);
    
    
    // Start the webCam and set a plane to texture
    webCam.initGrabber(1280, 720);
    
    plane.set(ofGetWidth(), ofGetHeight(), 2, 2);
    plane.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    // Load the shader
    lutFilter.load("lut_filter");

}

//--------------------------------------------------------------
void ofApp::update(){
    
    webCam.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    lutFilter.begin();
    
    lutFilter.setUniformTexture("tex", webCam.getTextureReference(), 0);
    lutFilter.setUniformTexture("lutTexure", GL_TEXTURE_3D, texture3D, 1);
    lutFilter.setUniform1f("lutSize", LUTsize);
    lutFilter.setUniform2f("mouse", (float)mouseX/ofGetWidth(), (float)mouseY/ofGetHeight());
    
    plane.draw();
    lutFilter.end();

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
