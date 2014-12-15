#include "stdafx.h"
#include "DataMildOr.h"


CDataMildOr::CDataMildOr(const LONG& left, const LONG& up, const LONG& right, const LONG& down):CElement(left,up,right,down)
{
	mildor.x = left;
	mildor.y = up;
}

CDataMildOr::~CDataMildOr(void)
{
}

void CDataMildOr::OnDraw(CDC* pDC){
	pDC->TextOutW(Left_Up.x,Left_Up.y,_T("¨’"));
}