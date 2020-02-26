#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();

	this->frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->face.clear();
	this->frame.clear();

	int radius = 300;
	int theta_start = (int)(ofGetFrameNum() * 0.5) % 10;
	for (int theta = theta_start; theta < theta_start + 180; theta += 10) {

		for (int phi = 0; phi < 360; phi += 1) {

			auto index = this->face.getNumVertices();

			vector<glm::vec3> vertices;

			vertices.push_back(glm::vec3(
				radius * cos(phi * DEG_TO_RAD) * sin((theta + 1) * DEG_TO_RAD),
				radius * sin(phi * DEG_TO_RAD) * sin((theta + 1) * DEG_TO_RAD),
				radius * cos((theta + 1) * DEG_TO_RAD)
			));
			vertices.push_back(glm::vec3(
				radius * cos((phi + 1) * DEG_TO_RAD) * sin((theta + 1) * DEG_TO_RAD),
				radius * sin((phi + 1) * DEG_TO_RAD) * sin((theta + 1) * DEG_TO_RAD),
				radius * cos((theta + 1) * DEG_TO_RAD)
			));
			vertices.push_back(glm::vec3(
				radius * cos((phi + 1) * DEG_TO_RAD) * sin((theta - 1) * DEG_TO_RAD),
				radius * sin((phi + 1) * DEG_TO_RAD) * sin((theta - 1) * DEG_TO_RAD),
				radius * cos((theta - 1) * DEG_TO_RAD)
			));
			vertices.push_back(glm::vec3(
				radius * cos(phi * DEG_TO_RAD) * sin((theta - 1) * DEG_TO_RAD),
				radius * sin(phi * DEG_TO_RAD) * sin((theta - 1) * DEG_TO_RAD),
				radius * cos((theta - 1) * DEG_TO_RAD)
			));

			vertices.push_back(glm::vec3(
				(radius - 30) * cos(phi * DEG_TO_RAD) * sin((theta + 1) * DEG_TO_RAD),
				(radius - 30) * sin(phi * DEG_TO_RAD) * sin((theta + 1) * DEG_TO_RAD),
				radius * cos((theta + 1) * DEG_TO_RAD)
			));
			vertices.push_back(glm::vec3(
				(radius - 30) * cos((phi + 1) * DEG_TO_RAD) * sin((theta + 1) * DEG_TO_RAD),
				(radius - 30) * sin((phi + 1) * DEG_TO_RAD) * sin((theta + 1) * DEG_TO_RAD),
				radius * cos((theta + 1) * DEG_TO_RAD)
			));
			vertices.push_back(glm::vec3(
				(radius - 30) * cos((phi + 1) * DEG_TO_RAD) * sin((theta - 1) * DEG_TO_RAD),
				(radius - 30) * sin((phi + 1) * DEG_TO_RAD) * sin((theta - 1) * DEG_TO_RAD),
				radius * cos((theta - 1) * DEG_TO_RAD)
			));
			vertices.push_back(glm::vec3(
				(radius - 30) * cos(phi * DEG_TO_RAD) * sin((theta - 1) * DEG_TO_RAD),
				(radius - 30) * sin(phi * DEG_TO_RAD) * sin((theta - 1) * DEG_TO_RAD),
				radius * cos((theta - 1) * DEG_TO_RAD)
			));

			this->face.addVertices(vertices);
			this->frame.addVertices(vertices);

			this->face.addIndex(index + 0); this->face.addIndex(index + 1); this->face.addIndex(index + 2);
			this->face.addIndex(index + 0); this->face.addIndex(index + 2); this->face.addIndex(index + 3);

			this->face.addIndex(index + 4); this->face.addIndex(index + 5); this->face.addIndex(index + 6);
			this->face.addIndex(index + 4); this->face.addIndex(index + 6); this->face.addIndex(index + 7);

			this->face.addIndex(index + 0); this->face.addIndex(index + 4); this->face.addIndex(index + 5);
			this->face.addIndex(index + 0); this->face.addIndex(index + 5); this->face.addIndex(index + 1);

			this->face.addIndex(index + 2); this->face.addIndex(index + 6); this->face.addIndex(index + 7);
			this->face.addIndex(index + 2); this->face.addIndex(index + 7); this->face.addIndex(index + 3);

			this->frame.addIndex(index + 0); this->frame.addIndex(index + 1);
			this->frame.addIndex(index + 2); this->frame.addIndex(index + 3);

			this->frame.addIndex(index + 4); this->frame.addIndex(index + 5);
			this->frame.addIndex(index + 6); this->frame.addIndex(index + 7);

		}
	}
}


//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(270);

	ofSetColor(39);
	this->face.draw();

	ofSetColor(239);
	this->frame.drawWireframe();

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}