#pragma once
#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <iostream>
#include "TextLine.h"

class TextBox
{
public:
	TextBox();
	~TextBox();

	void setWidth(int _width);
	void drawSingleBox(TextLine* textLine, HANDLE* handle);
	void drawBeginBox(TextLine* textLine, HANDLE* handle);
	void drawMiddleBox(TextLine* textLine, HANDLE* handle);
	void drawEndBox(TextLine* textLine, HANDLE* handle);

private:
	int width;
	
};

#endif // !TEXTBOX_H

