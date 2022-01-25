#pragma once
#ifndef TEXTLINE_H
#define TEXTLINE_H
#include <iostream>
#include <string>
#include <Windows.h>
#include "Constants.h"

class TextLine
{
public:
	TextLine();
	~TextLine();

	void setText(const std::string& _text);
	void setColor(int _color);
	void draw(HANDLE* cHandle);
	void setDone();
	void setNotDone();

	const size_t getTextLength() const;
	std::string& getText();
	int getColor() const;
	bool isDone() const;

private:
	std::string text;
	int color;
	bool done;
};

#endif // !TEXTLINE_H

