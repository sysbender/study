#pragma once
#include <iostream>
#include <string>
class LibMat
{
public:
	LibMat()
	{
		std::cout << " LibMat - constructor \n";
	}

	virtual ~LibMat()
	{
		std::cout << " LibMat - destructor \n";
	}


	virtual void print() const
	{
		std::cout << "LibMat::print() -- I am a LibMat object! \n";
	}
};

class Book : public LibMat
{
public:
	Book(const std::string& title, const std::string& author)
		: _title(title),
		  _author(author)
	{
		std::cout << "Book::Book(title,author)\n";
	}


	virtual ~Book() override
	{
		std::cout << "Book::~Book\n";
	}
	virtual void print() const override
	{
		std::cout << " Book::print() " << _title << _author <<std::endl;
	}


	std::string title() const
	{
		return _title;
	}

	std::string author() const
	{
		return _author;
	}

protected:
	std::string _title;
	std::string _author;
};



class AudioBook : public Book
{

public:
	AudioBook(const std::string& title, const std::string& author, const std::string& narrator)
		: Book(title, author),
	_narrator(narrator)
	{
		std::cout << "Audiobook::audiobook() -- constructor \n";
	}

	virtual void print() const
	{
		std::cout << "Audiobook::print() \n";
	}


	 ~AudioBook()
	{
		std::cout << "Audiobook::~Audiobook() \n";
	}


	std::string narrator () const
	{
		return _narrator;
	}
protected:
	std::string _narrator;
};
 

 
