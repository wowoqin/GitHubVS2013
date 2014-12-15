#pragma once
#include "Element.h"
class CDataFile :
	public CElement
{
public:
	CDataFile();
	~CDataFile();
	CDataFile(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
	CDataFile(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString &content);
	CDataFile(const CPoint& l_u, const CPoint& r_d);
	CDataFile(const CPoint& l_u, const CPoint& r_d, const CString& content);
public:
	void OnDraw(CDC* pDC);
	int SetContent(const CString &content);
	CString &GetContent();
};

