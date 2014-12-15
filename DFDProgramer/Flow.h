#pragma once
#include "Item.h"
class CFlow :
	public CItem
{
public:
	CFlow();
	~CFlow();
	CFlow(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
	CFlow(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString &content);
	CFlow(const CPoint& l_u, const CPoint& r_d);
	CFlow(const CPoint& l_u, const CPoint& r_d, const CString& content);
};

