#include "stdafx.h"
#include "DataAnd.h"


CDataAnd::CDataAnd(const LONG& left, const LONG& up, const LONG& right, const LONG& down):CElement(left,up,right,down)
{
	and.x = left;
	and.y = up;
}

CDataAnd::~CDataAnd(){

}

void CDataAnd::OnDraw(CDC* pDC){
	pDC->TextOutW(Left_Up.x,Left_Up.y,_T("+"));
}