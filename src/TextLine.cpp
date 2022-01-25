#include "stdafx.h"
#include "TextLine.h"


TextLine::TextLine() : color(DEFAULT_COLOR), done(false)
{
}


TextLine::~TextLine()
{
}


void TextLine::setText(const std::string& _text) {
	text = _text;
}


void TextLine::setColor(int _color) {
	color = _color;
}


void TextLine::draw(HANDLE* cHandle) {
	SetConsoleTextAttribute(*cHandle, color);
	std::cout << text;
	SetConsoleTextAttribute(*cHandle, DEFAULT_COLOR);
}


const size_t TextLine::getTextLength() const {
	return text.length();
}


std::string& TextLine::getText(){
	return text;
}


int TextLine::getColor() const {
	return color;
}


void TextLine::setDone() {
	done = true;
}


void TextLine::setNotDone() {
	done = false;
}


bool TextLine::isDone() const{
	return done;
}
