#include "stdafx.h"
#include "DataOr.h"


CDataOr::CDataOr(const LONG& left, const LONG& up, const LONG& right, const LONG& down):CElement(left,up,right,down)
{
	or.x = left;
	or.y = up;
}

CDataOr::~CDataOr(void)
{
}

void CDataOr::OnDraw(CDC* pDC){
	pDC->TextOutW(Left_Up.x,Left_Up.y,_T("*"));
}