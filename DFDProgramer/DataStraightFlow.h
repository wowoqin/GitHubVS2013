#pragma once
#include "Flow.h"
#include <list>
class CDataStraightFlow :
	public CFlow
{
public:
	CDataStraightFlow();
	~CDataStraightFlow();
	CDataStraightFlow(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
	CDataStraightFlow(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString &content);
	CDataStraightFlow(const CPoint& l_u, const CPoint& r_d);
	CDataStraightFlow(const CPoint& l_u, const CPoint& r_d, const CString& content);
public:
	void OnDraw(CDC* pDC);
	int SetContent(const CString &content);
	CString &GetContent();
	void GetItem(std::list<CItem*> startItem, std::list<CItem*> endItem);

};

