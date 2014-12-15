#pragma once
#include "Element.h"
class CDataFunction :
	public CElement
{
public:
	CDataFunction();
	~CDataFunction();
	CDataFunction(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
	CDataFunction(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString &content);
	CDataFunction(const CPoint& l_u, const CPoint& r_d);
	CDataFunction(const CPoint& l_u, const CPoint& r_d, const CString& content);
public:
	void OnDraw(CDC* pDC);
	int SetContent(const CString &content);
	CString &GetContent();
};

