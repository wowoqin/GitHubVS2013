#pragma once
#include "Item.h"
class CElement :
	public CItem
{
public:
	CElement();
	~CElement();
	CElement(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
	CElement(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString &content);
	CElement(const CPoint& l_u, const CPoint& r_d);
	CElement(const CPoint& l_u, const CPoint& r_d, const CString& content);
};

