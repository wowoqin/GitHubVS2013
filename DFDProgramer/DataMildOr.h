#pragma once
#include "element.h"
class CDataMildOr :
	public CElement
{
public:
	CDataMildOr(void);
	~CDataMildOr(void);
	CDataMildOr(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
public:
	virtual void OnDraw(CDC* pDC);
protected:
	CPoint mildor;//数据流的与或关系
};

