#include "stdafx.h"
#include "DataFunction.h"


CDataFunction::CDataFunction()
{
	Left_Up.x = 20;
	Left_Up.y = 30;
	Right_Down.x = 100;
	Right_Down.y = 100;
}


CDataFunction::~CDataFunction()
{
}


CDataFunction::CDataFunction(const LONG& left, const LONG& up, const LONG& right, const LONG& down) : CElement(left, up, right, down)
{

}


CDataFunction::CDataFunction(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString& content) : CElement(left, up, right, down, content)
{

}


CDataFunction::CDataFunction(const CPoint& l_u, const CPoint& r_d) : CElement(l_u, r_d)
{

}


CDataFunction::CDataFunction(const CPoint& l_u, const CPoint& r_d, const CString& content) : CElement(l_u, r_d, content)
{

}



void CDataFunction::OnDraw(CDC* pDC)
{
	COLORREF color = RGB(255, 255, 255);
	CBrush brush(color);
	pDC->SelectObject(&brush);
	pDC->Ellipse(Left_Up.x, Left_Up.y, Right_Down.x, Right_Down.y);
	color = RGB(255, 255, 255);
	pDC->SelectObject(&brush);
	pDC->SetBkMode(0);
	pDC->TextOutW(Left_Up.x + 20, Left_Up.y + 15, Item_Content);
}


int CDataFunction::SetContent(const CString &content)
{
	Item_Content = content;
	return 0;
}


CString &CDataFunction::GetContent()
{
	return Item_Content;
}