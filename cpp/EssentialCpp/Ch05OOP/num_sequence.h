#pragma once
#include <ostream>
#include <iostream>
#include <vector>

//-------------------------------------------------------------------------------
 
class num_sequence
{
public:
	virtual ~num_sequence() {};

	//brief return the element at pos
	virtual int elem(int pos) const =0;  //pure virtual function
	//return the type of sequence
	virtual const char * what_am_i() const =0;
	// print all the elements
	virtual std::ostream& print(std::ostream &os = std::cout) const=0;

 
	static int max_elems() { return _max_elems; }

protected:
	//generate elements to the position
	virtual void gen_elems(int pos)const =0;

	// check if pos is valid
	bool check_integrity(int pos) const ;

	const static int _max_elems = 1024;



};


inline bool num_sequence::check_integrity(int pos) const
{
	if(pos<=0 || pos> _max_elems)
	{
		std::cerr << " error: invalid pos = " << pos << std::endl;
		return false;
	}
	return true;
}

std::ostream& operator<< (std::ostream &os, const num_sequence&ns)
{
	return ns.print(os);
}


//---------------------------------------------------
class Fibonacci : public num_sequence
{
public:
//	virtual int elem(int pos) const override;
//	virtual const char* what_am_i() const override;
//	virtual std::ostream& print(std::ostream& os) const override;

	Fibonacci(int length=1, int beg_pos=1):
	_length(length), _beg_pos(beg_pos)
	{
		
	}
	virtual int elem(int pos) const override ;
	virtual const char* what_am_i() const override
	{
		return "Fibonacci";
	}
	virtual std::ostream & print(std::ostream &os = std::cout) const override;

	int length()const
	{
		return _length;
	}

	int beg_pos() const
	{
		return _beg_pos;
	}

protected:
//	virtual void gen_elems(int pos) const override;
	virtual void gen_elems(int pos) const override;

	int _length;
	int _beg_pos;
	static std::vector<int> _elems;

public:

};


// return the element at position pos
inline int Fibonacci::elem(int pos) const
{
	if(!check_integrity(pos))
	{
		return 0;
	}

	if(pos> _elems.size())
	{
		Fibonacci::gen_elems(pos);
	}
	return _elems[pos - 1];
}


inline void Fibonacci::gen_elems(int pos) const
{
	if(_elems.empty())
	{
		_elems.push_back(1);
		_elems.push_back(1);
	}

	if(_elems.size()<pos)
	{
		int ix = _elems.size();

		for(;ix <=pos; ++ix)
		{
			int elem = _elems[ix - 2] + _elems[ix - 1];
			_elems.push_back(elem);
		}
	}
}

inline std::ostream& Fibonacci::print(std::ostream& os) const
{
	int elem_pos = _beg_pos - 1;
	int end_pos = elem_pos + _length;

	if( end_pos > _elems.size())
	{
		Fibonacci::gen_elems(end_pos);
	}

	while(elem_pos < end_pos)
	{
		os << _elems[end_pos++] << ' ';
	}

	return os;

}
