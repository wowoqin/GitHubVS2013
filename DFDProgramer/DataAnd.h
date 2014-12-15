#pragma once
#include "element.h"
class CDataAnd:public CElement
{
public:
	CDataAnd(void);
	~CDataAnd(void);
	CDataAnd(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
public:
	virtual void OnDraw(CDC* pDC);
protected:
	CPoint and;//数据流的与关系
};