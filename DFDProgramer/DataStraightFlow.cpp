#include "stdafx.h"
#include "DataStraightFlow.h"


CDataStraightFlow::CDataStraightFlow()
{
}


CDataStraightFlow::~CDataStraightFlow()
{
}


CDataStraightFlow::CDataStraightFlow(const LONG& left, const LONG& up, const LONG& right, const LONG& down) : CFlow(left, up, right, down)
{

}


CDataStraightFlow::CDataStraightFlow(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString& content) : CFlow(left, up, right, down, content)
{

}


CDataStraightFlow::CDataStraightFlow(const CPoint& l_u, const CPoint& r_d) : CFlow(l_u, r_d)
{

}


CDataStraightFlow::CDataStraightFlow(const CPoint& l_u, const CPoint& r_d, const CString& content) : CFlow(l_u, r_d, content)
{

}



void CDataStraightFlow::OnDraw(CDC *pDC)
{
	COLORREF color = RGB(255, 255, 255);
	CBrush brush(color);
	//pDC->SelectObject(&brush);
	CPen pen(PS_SOLID, 30, color);
	pDC->SelectObject(&pen);  //»­±Ê
	pDC->MoveTo(Left_Up.x + 20, Left_Up.y + 20);
	pDC->LineTo(Left_Up.x + 50, Left_Up.y + 20);
	pDC->MoveTo(Left_Up.x + 50, Left_Up.y + 20);
	pDC->LineTo(Left_Up.x + 45, Left_Up.y + 15);
	pDC->MoveTo(Left_Up.x + 50, Left_Up.y + 20);
	pDC->LineTo(Left_Up.x + 45, Left_Up.y + 25);
	pDC->SelectObject(&brush);
	//pDC->Rectangle(Right_Down.x,Right_Down.y,Right_Down.x+5,Right_Down.y+5);  // »æÖÆ
	pDC->SelectObject(&brush);
	pDC->SetBkMode(0);
	pDC->TextOutW(Left_Up.x + 20, Left_Up.y + 25, Item_Content);
}