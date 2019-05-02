#ifndef EXCEPTION_CLASSES
#define EXCEPTION_CLASSES


#include <strstream>
#include <string>

using namespace std;

class baseException
{
public:
	baseException(const string& str=""): msgString(str){
		if (msgString == "") {
			msgString = "Unspecified exception";
		}
	}

	string what() const {
		return msgString;
	}
	

protected:
	// 继承类中需要使用该成员
	string msgString;
};

//////////////////下面是各种具体的异常

//内存分配异常
class memoryAllocationError : public baseException
{
public:
	memoryAllocationError(const string& str = "") :
		baseException(str)
	{}
};

// function argument out of proper range
class rangeError : public baseException
{
public:
	rangeError(const string& str = "") :
		baseException(str)
	{}
};

// index out of range
class indexRangeError : public baseException
{
public:
	indexRangeError(const string& msg, int i, int size) :
		baseException()	{
		char indexString[80];
		ostrstream indexErr(indexString, 80);
		indexErr << msg << " index " << i << " size " << size << ends;
		msgString = indexString;
	}
};

// attempt to erase from an empty container
class underflowError : public baseException
{
public:
	underflowError(const string& msg = "") :
		baseException(msg)
	{}
};

//// attempt to erase from an empty container
//class underflowError : public baseException
//{
//public:
//	underflowError(const string& msg = "") :
//		baseException(msg)
//	{}
//};

// attempt to insert into a full container
class overflowError : public baseException
{
public:
	overflowError(const string& msg = "") :
		baseException(msg)
	{}
};

// error in expression evaluation
class expressionError : public baseException
{
public:
	expressionError(const string& msg = "") :
		baseException(msg)
	{}
};

// bad object reference
class referenceError : public baseException
{
public:
	referenceError(const string& msg = "") :
		baseException(msg)
	{}
};

class notImplementedError : public baseException
{
public:
	notImplementedError(const string& msg = "") :
		baseException(msg)
	{}
};

// error in graph class
class graphError : public baseException
{
public:
	graphError(const string& msg = "") :
		baseException(msg)
	{}
};

// error in graph class
class fileError : public baseException
{
public:
	fileError(const string& msg = "") :
		baseException(msg)
	{}
};


// 文件打开异常
class fileOpenError : public baseException
{
public:
	fileOpenError(const string& filename) : 
		baseException() {
		char errorStr[80];
		ostrstream fileErr(errorStr, 80);
		fileErr << "file " << filename << " open error " << ends;
		msgString = errorStr;
	}
};

//  data error
class dateError : public baseException
{
public:
	dateError(const string& first, int v, const string& last) :
		baseException() {
		char errorStr[80];
		ostrstream dataErr(errorStr, 80);
		dataErr << first << ' ' << v << ' ' << last << ends;
		msgString = errorStr;
	}

};



#endif // !EXCEPTION_CLASSES
