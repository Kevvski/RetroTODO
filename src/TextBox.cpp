#include "stdafx.h"
#include "TextBox.h"


TextBox::TextBox() : width(0)
{
}


TextBox::~TextBox()
{
}


void TextBox::setWidth(int _width) {
	width = _width;
}


void TextBox::drawSingleBox(TextLine* textLine, HANDLE* handle) {
	drawBeginBox(textLine, handle);

	//Left bottom corner
	std::cout << static_cast<char>(200);

	//Line
	for (int i = 0; i < width; i++)
		std::cout << static_cast<char>(205);

	//Right bottom corner
	std::cout << static_cast<char>(188);

}


void TextBox::drawBeginBox(TextLine* textLine, HANDLE* handle) {
	//Left up corner
	std::cout << static_cast<char>(201);

	//Line
	for (int i = 0; i < width; i++)
		std::cout << static_cast<char>(205);

	//Right up corner
	std::cout << static_cast<char>(187) << std::endl;

	//Wall
	std::cout << static_cast<char>(186);
	textLine->draw(handle);

	//Wall
	std::cout << static_cast<char>(186) << std::endl;

}


void TextBox::drawMiddleBox(TextLine* textLine, HANDLE* handle) {
	//Left connector
	std::cout << static_cast<char>(204);

	//Line
	for (int i = 0; i < width; i++)
		std::cout << static_cast<char>(205);

	//Right connector
	std::cout << static_cast<char>(185) << std::endl;

	//Wall
	std::cout << static_cast<char>(186);

	//Text
	textLine->draw(handle);

	//Wall
	std::cout << static_cast<char>(186) << std::endl;

}


void TextBox::drawEndBox(TextLine* textLine, HANDLE* handle) {
	//Left connector
	std::cout << static_cast<char>(204);

	//Line
	for (int i = 0; i < width; i++)
		std::cout << static_cast<char>(205);

	//Right connector
	std::cout << static_cast<char>(185) << std::endl;

	//Wall
	std::cout << static_cast<char>(186);

	//Text
	textLine->draw(handle);

	//Wall
	std::cout << static_cast<char>(186) << std::endl;

	//Left bottom corner
	std::cout << static_cast<char>(200);

	//Line
	for (int i = 0; i < width; i++)
		std::cout << static_cast<char>(205);

	//Right bottom corner
	std::cout << static_cast<char>(188);
}
