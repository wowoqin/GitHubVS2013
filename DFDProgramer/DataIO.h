#pragma once
#include "Element.h"
class CDataIO :
	public CElement
{
public:
	CDataIO();
	~CDataIO();
	CDataIO(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
	CDataIO(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString &content);
	CDataIO(const CPoint& l_u, const CPoint& r_d);
	CDataIO(const CPoint& l_u, const CPoint& r_d, const CString& content);
public:
	void OnDraw(CDC* pDC);
	int SetContent(const CString &content);
	CString &GetContent();
};

