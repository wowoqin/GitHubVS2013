#pragma once
#include "element.h"
class CDataOr :
	public CElement
{
public:
	CDataOr(void);
	~CDataOr(void);
	CDataOr(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
public:
	virtual void OnDraw(CDC* pDC);
protected:
	CPoint or;//数据流的或关系
};

